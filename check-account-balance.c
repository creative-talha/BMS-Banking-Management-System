#include "user-header.h"
#include <stdio.h>
#include <stdlib.h>
void check_balance(void) {
  // variables
  int option;
  printf("Balance:%u\n", user_info.balance);

  // input from user if he wanna input again
  do {
    printf("\n\nSelect one of the following:\n1.Menu"
           "\n2.Exit\n\nOption:");
    scanf(" %d", &option);
    // cleaning the terminal
    clean();
  } while (option != 1 && option != 2);
  switch (option) {
  case 1:
    return;
    break;

  case 2:
    exit(0);
    break;
  }
}