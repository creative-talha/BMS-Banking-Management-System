#include "user-header.h"
#include <stdio.h>

int user_menu(void) {
  int option;

  printf("\nPlease select one of the options in the given menu:\n"
         "\t\t(from 1 to 8)\n");
  printf("1.Check Account Balance\n"
         "2.Make Transaction\n"
         "3.View Transactions\n"
         "4.View Account Information\n"
         "5.Update Personal Info\n"
         "6.Change Account Password\n"
         "7.Logout\n"
         "8.Exit Program\n");

  while (1) {
    printf("OPTION: ");
    if (scanf("%d", &option) != 1) {
      while (getchar() != '\n')
        ; // clear invalid input
      printf("Invalid input. Enter a number from 1 to 8.\n");
      continue;
    }

    if (option >= 1 && option <= 8)
      break;

    printf("The option should be from 1 to 8!\n");
  }

  clean(); // cleaning terminal
  return option;
}
