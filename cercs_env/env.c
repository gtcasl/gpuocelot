#include "config.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "cercs_env.h"

typedef struct {
    int value_count;
    char **name_values;
} env_table_struct;

static env_table_struct env_table = {-1, NULL};
static int cercs_env_verbose = 0;

#define CERCS_INIT_FILE "cercs_config"

static char *search_path[] = { "HOME", 
			       INSTALL_DIR, 
			       "/users/c/chaos/lib",
			       "/usr/local/lib",
			       NULL,
};

#if defined(_MSC_VER)
#define putenv _putenv
#endif

static FILE *
find_config_file()
{
    char *config_file_name;
    FILE *config_fd;
    int i = 0;

    if ((config_file_name = getenv("CERCS_CONFIG_FILE")) != NULL) {
	if ((config_fd = fopen(config_file_name, "r")) != NULL) {
	    if (cercs_env_verbose) {
		fprintf(stderr, "CERCS_ENV: Using config file \"%s\".\n",
			config_file_name);
	    }
	    return config_fd;
	}
	fprintf(stderr, "CERCS_ENV:  Warning - file specified by CERCS_CONFIG_FILE \"%s\" not available\n", 
		config_file_name);
    }

    while (search_path[i] != NULL) {
	char *directory;
	char *filename;
	if (strcmp(search_path[i], "HOME") == 0) {
	    directory = getenv("HOME");
	} else {
	    directory = search_path[i];
	}
	if (directory == NULL) {
	    i++;
	    continue;
	}

	filename = malloc(strlen(directory) + strlen(CERCS_INIT_FILE) + 2);
	strcpy(filename, directory);
	if ((filename[0] != 0) && (filename[strlen(filename) -1] != '/')) {
	    /* add directory sep char */
	    strcat(filename, "/");
	}
	strcat(filename, CERCS_INIT_FILE);
	if ((config_fd = fopen(filename, "r")) != NULL) {
	    if (cercs_env_verbose) {
		fprintf(stderr, "CERCS_ENV: Using config file \"%s\".\n",
			filename);
	    }
	    free(filename);
	    return config_fd;
	} else {
	    if (cercs_env_verbose) {
		fprintf(stderr, "CERCS_ENV: Status - config file \"%s\" not found.\n",
			filename);
	    }
	}
	free(filename);
	i++;
    }
    if (cercs_env_verbose) {
	fprintf(stderr, "CERCS_ENV: Warning - no config file.\n");
    }
    return NULL;
}

static void
init_env_table()
{
    FILE * config_file = find_config_file();
    char value_buffer[1024];
    int value_count = 0;
    char **name_values = NULL;
    size_t *offset_values = NULL;
    size_t string_table_size = 0;
    char *string_table;
    int i;

    if (config_file == NULL) return;
    
    string_table = malloc(1);
    offset_values = malloc(sizeof(name_values[0]));

    while (fgets(value_buffer, sizeof(value_buffer), config_file) != NULL) {
	size_t item_length = strlen(value_buffer) + 1;
	size_t white_count = strspn(value_buffer, " \t\n");

	if (white_count +1 == item_length) continue;  /* blank line */
	if (value_buffer[white_count] == '#') continue; /* comment */
	if (value_buffer[item_length - 2] == '\n') {
	    value_buffer[item_length - 2] = 0;
	}

	string_table = realloc(string_table, string_table_size + item_length);
	offset_values = realloc(offset_values, sizeof(offset_values[0]) *
			      (value_count + 1));
	/* offset_values just has offsets into string table now */
	offset_values[value_count] = string_table_size;
	strcpy(&string_table[string_table_size], value_buffer);
	string_table_size += item_length;
	value_count++;
    }

    name_values = malloc(sizeof(name_values[0]) * value_count);
    for (i=0; i < value_count; i++) {
	char *equal;
	/* change name_values into real pointers */
	name_values[i] = string_table + offset_values[i];
	equal = strchr(name_values[i], '=');
	if (equal != NULL) {
	    *equal = 0;
	    if (getenv(name_values[i]) == NULL) {
		*equal = '=';
		putenv(name_values[i]);
	    }
	}
    }
    free(offset_values);

    /* 
     *  don't write env_table until the very end to reduce risk of 
     *  simultaneous update.
     */
    env_table.value_count = value_count;
    env_table.name_values = name_values;
}
    
extern char *
cercs_getenv(char *name)
{
    int i;
    size_t name_len;
    char *value = NULL;
    if (env_table.value_count == -1) {
	cercs_env_verbose = (getenv("CERCS_ENV_VERBOSE") != NULL);
	init_env_table();
    }
    
    /*
     * actual environment values override file defaults
     */
    value = getenv(name);
    if (value != NULL) {
	if (cercs_env_verbose) {
	    fprintf(stderr, "CERCS_ENV: query for value %s returning \"%s\" (getenv).\n",
		    name, value);
	}
	return value;
    }
#ifdef HAVE_WINDOWS_H
    {
	DWORD   dwType;
	DWORD   dwSize;
	HKEY hKey;
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\PBIO", 0, KEY_READ, 
			 &hKey) == ERROR_SUCCESS) {
	    if (RegQueryValueEx(hKey, name, NULL, &dwType, NULL, 
				&dwSize) == ERROR_SUCCESS) {
		value = malloc(dwSize);
    		if (RegQueryValueEx(hKey, name, NULL, &dwType, 
				    value, &dwSize) != ERROR_SUCCESS) {
		    free(name);
		}
	    }
	    RegCloseKey(hKey);
	}
    }
#endif

    /*
     * walk the table
     */
    name_len = strlen(name);
    for (i=0; i < env_table.value_count; i++) {
	if ((strncmp(name, env_table.name_values[i], name_len) == 0) &&
	    (env_table.name_values[i][name_len] == '=')) {
	    value = &env_table.name_values[i][name_len + 1];
	    if (cercs_env_verbose) {
		fprintf(stderr, "CERCS_ENV: query for value %s returning \"%s\" (file).\n",
			name, value);
	    }
	    return value;
	}
    }
    if (cercs_env_verbose) {
	fprintf(stderr, "CERCS_ENV: query for value %s returning NULL.\n",
		name);
    }

    return NULL;
}

extern int cercs_putenv(char *name_value)
{
    return 0;
}

    
