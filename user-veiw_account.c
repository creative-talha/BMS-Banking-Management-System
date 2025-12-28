#include "user-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void user_view_account() {

  char status[22] = "Active";
  int option;

  if (user_info.status == 'A')
    strcpy(status, "Active!");
  else if (user_info.status == 'F')
    strcpy(status, "Account Freezed!");

  printf("\n");
  printf("Name: %s\nID: %s\nStatus: %s\nBalance: %u\n", user_info.Name,
         user_info.id, status, user_info.balance);

  // input from user if he wanna input again
  printf("\n\nplease enter one of the following:\n");
  printf("1.Menu\n2.Exit\n\nOption: ");
  scanf("%d", &option);

  switch (option) {
  case 1:
    return; // go back to menu
  case 2:
    exit(0); // exit program
  default:
    printf("Invalid option.\n");
    return;
  }
}
