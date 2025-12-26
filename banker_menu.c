#include "banker_header.h"
#include <stdio.h>

char banker_menu(void) {
  // variable
  int i = 1;
  char option;
  // input of the option to select

  printf("\nPlease select one of the option in the given menu:\n"
         "\t\t(from 1 to 7)\n");
  printf("1.Create account\n"
         "2.View account Details\n"
         "3.View Transaction Details\n"
         "4.Update Account Details\n"
         "5.Freeze/Activate Account\n"
         "6.Logout\n"
         "7.Exit Program\n");
  while (i) {
    printf("OPTION:");
    scanf("%c", &option);

    // validity for option check
    if (option < '1' || option > '7') {
      i = 1;
      printf("The option should be from 1 to 7!\n");
    } else
      i = 0;
  }
  // cleaning the terminal
  clean();

  return option;
}
