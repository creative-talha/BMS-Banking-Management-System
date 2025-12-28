/*gcc check-account-balance.c clean.c make-transaction.c user-login.c time.c
  user-veiw_account.c trx-id.c user-main.c user-menu.c user-veiw-transaction.c
  -o op
 */

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
      user_view_account();
      break;
    case 5:
      update_account();
      break;

    case 6:
      // logout and login again
      main();
      break;
    case 7:
      exit(0); // exit program
    default:
      printf("Invalid option!\n");
    }
  }
}
