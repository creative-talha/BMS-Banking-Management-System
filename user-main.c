#include "user-header.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int option;

  while (1) {

    user_login(); // login happens here

    while (1) {
      option = user_menu();

      if (option == 6) {
        // logout
        clean();
        break; // breaks inner loop, returns to login
      }

      // normal options
      switch (option) {
      case 1:
        check_balance();
        break;
      case 2:
        transfer();
        break;
      case 3:
        view_transaction();
        break;
      case 4:
        user_view_account();
        break;
      case 5:
        update_account();
        break;
      case 7:
        exit(0);
      default:
        printf("Invalid option!\n");
      }
    }
  }
}
