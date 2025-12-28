#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void user_view_account() {
  char status[22] = "Active";
  int option;

  // determine user account status
  if (user_info.status == 'A')
    strcpy(status, "Active!");
  else if (user_info.status == 'F')
    strcpy(status, "Account Freezed!");

  // display account info in box-style
  printf("====================================\n");
  printf("          ACCOUNT INFORMATION\n");
  printf("====================================\n");
  printf(" Name    : %s\n", user_info.Name);
  printf(" ID      : %s\n", user_info.id);
  printf(" Status  : %s\n", status);
  printf(" Balance : %u\n", user_info.balance);
  printf("====================================\n");

  // input from user for next action
  do {
    printf("====================================\n");
    printf("         ACCOUNT MENU\n");
    printf("====================================\n");
    printf(" 1. Return to main menu\n");
    printf(" 2. Exit\n");
    printf("====================================\n");
    printf(" OPTION: ");

    if (scanf("%d", &option) != 1) {
      while (getchar() != '\n')
        ;         // clear invalid input
      option = 0; // force loop again
    }

    clean(); // clear terminal for next screen
  } while (option != 1 && option != 2);

  // handle user choice
  switch (option) {
  case 1:
    return; // go back to menu
  case 2:
    exit(0); // exit program
  }
}
