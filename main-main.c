#include "banker-header.h"
#include "common-structs-header.h"
#include "user-header.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  char choice;

  while (1) {
    // Display main entry menu
    printf("====================================\n");
    printf("       WELCOME TO BANK SYSTEM       \n");
    printf("====================================\n");
    printf(" Select your role:\n");
    printf(" 1. Banker\n");
    printf(" 2. User\n");
    printf(" 3. Exit\n");
    printf("====================================\n");
    printf(" Enter Choice: ");
    scanf(" %c", &choice);

    // clear terminal before redirecting
    clean();

    switch (choice) {
    case '1':
      // Banker login and menu
      login(); // banker login
      while (1) {
        char option = banker_menu();
        switch (option) {
        case '1':
          create_account();
          break;
        case '2':
          view_account();
          break;
        case '4':
          update_user_account();
          break;
        case '5':
          freeze_actiavte_account();
          break;
        case '6':
          goto main_menu; // logout back to main menu
        case '7':
          exit(0); // exit program
        default:
          break;
        }
        clean();
      }
      break;

    case '2':
      // User login and menu
      user_login();
      while (1) {
        int option = user_menu();
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
        case 6:
          goto main_menu; // logout back to main menu
        case 7:
          exit(0); // exit program
        default:
          break;
        }
        clean();
      }
      break;

    case '3':
      printf("Exiting program. Goodbye!\n");
      exit(0);

    default:
      printf("====================================\n");
      printf(" Invalid input! Please select 1, 2, or 3.\n");
      printf("====================================\n");
      break;
    }

  main_menu:
    continue; // loop back to main entry menu
  }

  return 0;
}
