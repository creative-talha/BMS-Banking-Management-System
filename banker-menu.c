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
  printf("\t(from 1 to 9)\n");

  printf("1. Create Account\n");
  printf("2. Deposit Money\n");
  printf("3. Withdrawal Money\n");
  printf("4. View Account Details\n");
  printf("5. View Transaction Details\n");
  printf("6. Update Account Details\n");
  printf("7. Freeze/Activate Account\n");
  printf("8. Logout\n");
  printf("9. Exit Program\n");
  printf("=======================================\n");

  while (i) {
    printf("OPTION: ");
    scanf(" %c", &option); // space added to avoid newline issue

    // validity for option check
    if (option < '1' || option > '9') {
      i = 1;
      printf("---------------------------------------\n");
      printf(" The option should be from 1 to 9!\n");
      printf("---------------------------------------\n");
    } else {
      i = 0;
    }
  }

  // cleaning the terminal
  clean();

  return option;
}
