#include "common-structs-header.h"
#include <stdio.h>

int user_menu(void) {
  int option;

  printf("====================================\n");
  printf("            USER MENU\n");
  printf("====================================\n");
  printf(" 1. Check Account Balance\n");
  printf(" 2. Make Transaction\n");
  printf(" 3. View Transactions\n");
  printf(" 4. View Account Information\n");
  printf(" 5. Update Personal Info\n");
  printf(" 6. Logout\n");
  printf(" 7. Exit Program\n");
  printf("====================================\n");

  while (1) {
    printf(" OPTION: ");

    if (scanf(" %d", &option) != 1) {
      while (getchar() != '\n')
        ; // clear invalid input

      printf("====================================\n");
      printf(" ERROR\n");
      printf(" Invalid input. Enter a number (1-7).\n");
      printf("====================================\n");
      continue;
    }

    if (option >= 1 && option <= 7)
      break;

    printf("====================================\n");
    printf(" ERROR\n");
    printf(" Option must be between 1 and 7.\n");
    printf("====================================\n");
  }

  clean(); // clean terminal before next screen
  return option;
}
