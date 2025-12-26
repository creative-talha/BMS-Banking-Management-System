#include "banker_header.h"
#include <stdio.h>
#include <string.h>
void freeze_actiavte_account() {
  // variables
  struct user u;
  char user_to_freeze[16], status[22];
  char option = 'n';
  int found = 0;
  int status_change = 0;
  FILE *fp, *ft;

  // input for account number
  printf("INPUT THE ACCOUNT NUMBER THAT YOU WANT TO CHANGE THE STATUS:");
  scanf(" %s", user_to_freeze);
  // cleaning the terminal
  clean();

  // opening files

  fp = fopen("user.bin", "rb");
  ft = fopen("temp.bin", "wb");

  // starting search
  while (fread(&u, sizeof(u), 1, fp) == 1) {

    // if user is found changing the status
    if (strcmp(u.id, user_to_freeze) == 0) {
      found = 1;

      // printing user current state
      if (u.status == 'A')
        strcpy(status, "Active!");

      else if (u.status == 'F')
        strcpy(status, "Account Freezed!");

      printf("Current status:%s\n", status);

      // input from user to what status he wants

      // if the account was active
      if (u.status == 'A') {
        status_change = 1;
        do {
          printf("DO you wanna freeze the user(y/n):");
          scanf(" %c", &option);
        } while (option != 'y' && option != 'n');
        // changing status
        if (option == 'y') {
          u.status = 'F';
          printf("Account Freezed succesfully!\n");
        }
      }
      // if the account was not active
      if (u.status == 'F' && status_change == 0) {
        do {
          printf("DO you wanna Activate the user(y/n):");
          scanf(" %c", &option);
        } while (option != 'y' && option != 'n');
        // chaniging status
        if (option == 'y') {
          u.status = 'A';
          printf("Account activated succesfully!\n");
        }
      }
      // cleaning the terminal
      clean();
    }

    // pasting all the data in the temp file
    fwrite(&u, sizeof(u), 1, ft);
  }

  // closing files
  fclose(fp);
  fclose(ft);

  // if user not found
  if (!found) {
    printf("\nUSER NOT FOUND!\n");
    remove("temp.bin");

  }

  // if found and status changed removing the main and changing temp to main
  // file
  else {
    remove("user.bin");
    rename("temp.bin", "user.bin");
    printf("\nUSER Status updated SUCCESSFULLY\n");
  }
}
