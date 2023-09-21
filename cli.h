#include <stdbool.h>
#include <ctype.h>

#include "utils.h"
#include "polynomial.h"

int cli(int argc, char const *argv[]);

void help(const char programName[]);

bool isValidArgs(int argc, char const *argv[]);