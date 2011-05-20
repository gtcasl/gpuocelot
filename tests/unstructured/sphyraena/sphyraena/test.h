/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#pragma once

const char *sphyraena_test_cases[] = {
        "SELECT id, uniformi, normali5 FROM test WHERE uniformi > 60 AND normali5 < 0",
        "SELECT id, uniformf, normalf5 FROM test WHERE uniformf > 60 AND normalf5 < 0",
        "SELECT id, uniformi, normali5 FROM test WHERE uniformi > -60 AND normali5 < 5",
        "SELECT id, uniformf, normalf5 FROM test WHERE uniformf > -60 AND normalf5 < 5",
	"SELECT id, normali5, normali20 FROM test WHERE (normali20 + 40) > (uniformi - 10)",
	"SELECT id, normalf5, normalf20 FROM test WHERE (normalf20 + 40) > (uniformf - 10)",
	"SELECT id, normali5, normali20 FROM test WHERE normali5 * normali20 BETWEEN -5 AND 5",
	"SELECT id, normalf5, normalf20 FROM test WHERE normalf5 * normalf20 BETWEEN -5 AND 5",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE NOT uniformi OR NOT normali5 OR NOT normali20",
	"SELECT id, uniformf, normalf5, normalf20 FROM test WHERE NOT uniformf OR NOT normalf5 OR NOT normalf20",
	"SELECT SUM(normalf20) FROM test",
	"SELECT AVG(uniformi) FROM test WHERE uniformi > 0",
	"SELECT MAX(normali5), MIN(normali5) FROM test"
        };
const int sphyraena_num_tests = 13;


const int sphyraena_num_tests_size = 21;
const char *sphyraena_test_cases_size[] = {
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -100",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -90",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -80",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -70",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -60",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -50",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -40",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -30",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -20",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > -10",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 0",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 10",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 20",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 30",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 40",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 50",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 60",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 70",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 80",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 90",
	"SELECT id, uniformi, normali5, normali20 FROM test WHERE uniformi > 100"};

