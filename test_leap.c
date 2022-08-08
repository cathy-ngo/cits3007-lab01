
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/* return 0 (false) or 1 (true), depending on whether
 * `year` is a leap year or not.
 */
int is_leap(long year) {

  if (year % 4 != 0) { 
    return 0;
  }

  else if (year % 100 != 0) {
    return 1;
  }

  else if (year % 400 != 0) {
    return 0;
  }

  return 1;
}

int main(int argc, char **argv) {
  argc--;
  argv++;

  if (argc != 1) {
    fprintf(stderr, "Error: expected 1 command-line argument (a YEAR), but got %d\n", argc);
    exit(1);
  }

  char *end;

  // clear errno so we can check whether strtol fails
  errno = 0;
  long year = strtol(argv[0], &end, 10);
  int res_errno = errno;

  if (end == argv[0]) {
    fprintf(stderr, "Error: couldn't interpret '%s' as a number\n", argv[0]);
    exit(1);
  } else if (res_errno == ERANGE) {
    fprintf(stderr, "Error: '%s' is outside the range of numbers we can handle\n", argv[0]);
    exit(1);
  } else {
    if (is_leap(year)) {
      printf("%ld is a leap year\n", year);
    } else {
      printf("%ld is not a leap year\n", year);
    }
  }

}

