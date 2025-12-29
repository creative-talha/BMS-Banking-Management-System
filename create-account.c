#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void create_account() {
  // variables
  int k, option = 0;
  char password2[21], id2[51];
  struct user u;

  // loop in case user wants more then one accounts to create
  do {
    k = 1;
    // some rules for the banker to know before saving data
    printf("\n============================================\n");
    printf("             CREATE NEW ACCOUNT             \n");
    printf("============================================\n");
    printf("\t\tSOME RULES TO NOTE!\n");
    printf("1. There should be no space in ID or Password.\n");
    printf("2. ID can be up to 15 characters.\n");
    printf("3. Password can be up to 20 characters.\n");
    printf("============================================\n");

    // loop in case the input is incorrect
    while (k) {
      // input
      printf("Name          : ");
      scanf("%50s", u.Name);

      printf("ID            : ");
      scanf("%15s", u.id);

      printf("Confirm ID    : ");
      scanf("%15s", id2);

      printf("PASSWORD      : ");
      scanf("%20s", u.password);

      printf("Confirm PASS  : ");
      scanf("%20s", password2);

      // status
      u.status = 'A';
      // balance
      u.balance = 0;

      // validity to confirm that the id and passwords are confirmed by entering
      // again
      if (!(strcmp(u.id, id2) || strcmp(password2, u.password))) {
        k = 0;
      } else {
        k = 1;
        printf("--------------------------------------------\n");
        printf("The ID or Password did not match. Try again!\n");
        printf("--------------------------------------------\n");
      }
    }

    // file handling to save the data for future use
    FILE *fp = fopen("user.bin", "ab");
    if (fp != NULL) {
      fwrite(&u, sizeof(u), 1, fp);
      fclose(fp);
    } else {
      printf("Error opening file to save user data.\n");
    }

    printf("\nAccount created successfully!\n");
    printf("============================================\n");

    // option for user to add another or go back

    // input from user if he wants to input again
    do {
      printf("\nPlease enter one of the following:\n");
      printf("1. Create another account\n");
      printf("2. Menu\n");
      printf("3. Exit\n");
      printf("Option: ");
      scanf(" %d", &option);
    } while (option < 1 || option > 3);
    clean();
  } while (option == 1);

  switch (option) {
  case 2:
    return;
  case 3:
    exit(0);
  }
}
