#include <stdio.h>
void clean(void) {
  printf("\033[2J\033[H");
  fflush(stdout);
}
