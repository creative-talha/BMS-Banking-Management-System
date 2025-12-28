#include "banker-header.h"
#include <stdio.h>

char banker_menu(void) {
  // variable
  int i = 1;
  char option;

  // input of the option to select
  printf("\n=======================================\n");
  printf("            BANKER MAIN MENU           \n");
  printf("=======================================\n");
  printf("\t(from 1 to 7)\n");

  printf("1. Create Account\n");
  printf("2. View Account Details\n");
  printf("3. View Transaction Details\n");
  printf("4. Update Account Details\n");
  printf("5. Freeze/Activate Account\n");
  printf("6. Logout\n");
  printf("7. Exit Program\n");
  printf("=======================================\n");

  while (i) {
    printf("OPTION: ");
    scanf(" %c", &option); // space added to avoid newline issue

    // validity for option check
    if (option < '1' || option > '7') {
      i = 1;
      printf("---------------------------------------\n");
      printf(" The option should be from 1 to 7!\n");
      printf("---------------------------------------\n");
    } else {
      i = 0;
    }
  }

  // cleaning the terminal
  clean();

  return option;
}
