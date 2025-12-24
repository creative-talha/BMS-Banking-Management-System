#include "header.h"
#include <stdio.h>
#include <string.h>

int main() {
  // variables
  struct user u;
  char user_to_freeze[16], status[22];
  char option = 'n';
  int found = 0;
  FILE *fp, *ft;

  // input for account number
  printf("INPUT THE ACCOUNT NUMBER THAT YOU WANT TO FREEZEZ:");
  scanf("%s", user_to_freeze);

  // opening files

  fp = fopen("user.bin", "rb");
  ft = fopen("user.bin", "wb");

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
        do {
          printf("DO you wanna freeze the user(y/n):");
          scanf("%c", &option);
        } while (option != 'y' && option != 'n');
        // changing status
        if (option == 'y') {
          u.status = 'F';
          printf("Account Freezed succesfully!\n");
        }

        // if the account was not active
        if (u.status == 'F') {
          do {
            printf("DO you wanna Activate the user(y/n):");
            scanf("%c", &option);
          } while (option != 'y' && option != 'n');
          // chaniging status
          if (option == 'y') {
            u.status = 'A';
            printf("Account activated succesfully!\n");
          }
        }
      }
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
    return;
  }

  // if found and status changed removing the main and changing temp to main
  // file
  else {
    remove("user.bin");
    rename("temp.bin", "user.bin");
    printf("\nUSER Status updated SUCCESSFULLY\n");
  }
}