
#include "banker-header.h"
#include <stdio.h>
#include <string.h>
// definition of password and id as only one user
#define id 12345
#define password "admin1"

// login function

void login() {
  // vbariables
  int input_id;
  char input_password[21];
  int c;
  // loop in case more user input invalid id or password
  while (1) {
    printf("================================\n");
    printf("         BANKER LOGIN\n");
    printf("================================\n");

    printf("User ID   : ");
    scanf("%d", &input_id);
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    printf("Password  : ");
    scanf("%20s", input_password);
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    if (input_id != id || strcmp(input_password, password) != 0) {
      printf("--------------------------------\n");
      printf("  Invalid Credential! Try again.\n");
      printf("--------------------------------\n");
    } else {
      printf("\nLogin Successful!\n");
      clean(); // clear after successful login
      break;
    }
  }
}
