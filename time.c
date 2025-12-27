
#include "user-header.h"
#include <stdio.h>
#include <time.h>
void print_datetime(time_t t) {
  struct tm *ti;
  char buf[20];

  ti = localtime(&t);
  strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", ti);
  printf("%s", buf);
}