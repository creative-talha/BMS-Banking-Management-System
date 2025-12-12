// gcc login.c menu.c create_account.c main.c -o combined_file---->this is how i
// will now compile the files
//./combined_file----->this is how i will execute teh file
#include "header.h"
#include <stdio.h>
int main() {
  // variables
  char option;
  // login function
  login();
  // menu function calling
  option = banker_menu();
  printf("hi");
  // switch statements to call the desire function
  switch (option) {
  case '1':
    create_account();
    break;
  }
}
