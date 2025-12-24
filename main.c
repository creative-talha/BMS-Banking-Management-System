/*gcc login.c menu.c create_account.c main.c veiw_account.c
update_user_account.c -o combined_file
---->this is how i will now compile the files
./combined_file----->this is how i will execute the file*/
#include "header.h"
#include <stdio.h>
#include <string.h>
int main() {
  // variables
  char option;
  // login function
  login();
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
  }
  return 0;
}
