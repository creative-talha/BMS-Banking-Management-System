#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>

void check_balance(void) {
  // variables
  int option;

  printf("====================================\n");
  printf("          ACCOUNT BALANCE\n");
  printf("====================================\n");
  printf(" Current Balance : %u\n", user_info.balance);
  printf("====================================\n");

  // input from user if he wanna input again
  do {
    printf("\nSelect one of the following:\n");
    printf(" 1. Menu\n");
    printf(" 2. Exit\n");
    printf("------------------------------------\n");
    printf(" OPTION: ");

    if (scanf(" %d", &option) != 1) {
      while (getchar() != '\n')
        ; // clear invalid input

      printf("====================================\n");
      printf(" ERROR\n");
      printf(" Invalid input. Enter 1 or 2.\n");
      printf("====================================\n");
      option = 0;
      continue;
    }

    // cleaning the terminal
    clean();

  } while (option != 1 && option != 2);

  switch (option) {
  case 1:
    return;

  case 2:
    exit(0);
  }
}
