#include "katl.h"

static char **__environ = NULL;

static char *
__findenv(name, offset)
	register const char *name;
	int *offset;
{
	register int len;
	register char **P, *C;
	register const char *tmp;

	for (tmp = name, len = 0; *tmp && *tmp != '='; ++tmp, ++len);

	if (__environ == NULL)
		return NULL;

	for (P = __environ; *P; ++P)
		if (!strncmp(*P, name, len))
			if (*(C = *P + len) == '=') {
				*offset = P - __environ;
				return(++C);
			}
	return(NULL);
}

/* Return the value of the environment variable NAME.  */
char *
atl_getenv (name)
     const char *name;
{
  const size_t len = strlen (name);
  char **ep;

  if (__environ == NULL)
    return NULL;

  for (ep = __environ; *ep != NULL; ++ep)
    if (!strncmp (*ep, name, len) && (*ep)[len] == '=')
      return &(*ep)[len + 1];

  return NULL;
}

/*
 * setenv --
 *	Set the value of the environmental variable "name" to be
 *	"value".  If rewrite is set, replace any current value.
 */
int
atl_setenv(name, value, rewrite)
	register const char *name;
	register const char *value;
	int rewrite;
{
	static int alloced;			/* if allocated space before */
	register char *C;
	int l_value, offset;
	char *__findenv();

	if (*value == '=')			/* no `=' in value */
		++value;
	l_value = strlen(value);
	if ((C = __findenv(name, &offset))) {	/* find if already exists */
		if (!rewrite)
			return (0);
		if (strlen(C) >= l_value) {	/* old larger; copy over */
			while ((*C++ = *value++));
			return (0);
		}
	} else {					/* create new slot */
		register int	cnt = 0;
		register char	**P;

		if (__environ != NULL)
			for (P = __environ, cnt = 0; *P; ++P, ++cnt);

		if (alloced) {			/* just increase size */
			__environ = (char **)atl_DReallocMM((char *)__environ,
			    (size_t)(sizeof(char *) * (cnt + 2)));
			if (!__environ)
				return (-1);
		}
		else {				/* get new space */
			alloced = 1;		/* copy old entries into it */
			P = (char **)atl_DAllocMM((size_t)(sizeof(char *) *
			    (cnt + 2)));
			if (!P)
				return (-1);
			memcpy(__environ, P, cnt * sizeof(char *));
			__environ = P;
		}
		__environ[cnt + 1] = NULL;
		offset = cnt;
	}
	for (C = (char *)name; *C && *C != '='; ++C);	/* no `=' in name */
	if (!(__environ[offset] =			/* name + `=' + value */
	    atl_DAllocMM((size_t)((int)(C - name) + l_value + 2))))
		return (-1);
	for (C = __environ[offset]; (*C = *name++) && *C != '='; ++C)
		;
	for (*C++ = '='; (*C++ = *value++); )
		;
	return (0);
}

