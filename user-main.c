// gcc check-account-balance.c clean.c make-transaction.c user-login.c time.c
// trx-id.c user-main.c user-menu.c - o c_f
#include "user-header.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int option;

  // initial login
  user_login();
  while (1) {
    option = user_menu();
    switch (option) {
    case 1: {
      check_balance();
    } break;
    case 2:
      transfer();
      break;
    case 3:
      veiw_transaction();
      break;
    case 4:

      break;
    case 5:

      break;
    case 6:

      break;
    case 7:
      // logout and login again
      main();
      break;
    case 8:
      exit(0); // exit program
    default:
      printf("Invalid option!\n");
    }
  }
}
