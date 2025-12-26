/*gcc banker_login.c banker_main.c banker_menu.c clean.c create_account.c
freeze_activate_account.c update_user_account.c veiw_account.c -o combined_file
---->this is how i will now compile the files
./combined_file----->this is how i will execute the file*/
#include "banker_header.h"
#include <stdio.h>
int main() {
  // variables
  char option;
  // login function
  login();
  while (1) {
    // menu function calling
    option = banker_menu();
    // switch statements to call the desire function
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
      main();
      break;
    case '7':
      return 0;
      break;
    }
    clean();
  }
}
