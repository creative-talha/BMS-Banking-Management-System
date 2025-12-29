#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void freeze_activate_account() {
  // variables
  struct user u;
  char user_to_freeze[16], status[22];
  char option = 'n';
  int found = 0, op, updated;

  FILE *fp, *ft;
  do {
    option = 'n';
    found = 0;
    // input for account number
    printf("\n============================================\n");
    printf("        FREEZE / ACTIVATE ACCOUNT           \n");
    printf("============================================\n");

    printf("INPUT THE ACCOUNT NUMBER THAT YOU WANT TO CHANGE THE STATUS: ");
    scanf(" %15s", user_to_freeze);

    // cleaning the terminal before showing details
    clean();

    // opening files
    fp = fopen("user.bin", "rb");
    ft = fopen("temp.bin", "wb");

    if (!fp || !ft) {
      printf("Error opening files.\n");
      return;
    }

    // starting search
    while (fread(&u, sizeof(u), 1, fp) == 1) {

      // if user is found changing the status
      if (strcmp(u.id, user_to_freeze) == 0) {
        found = 1;

        // printing user current state
        if (u.status == 'A')
          strcpy(status, "Active!");
        else if (u.status == 'F')
          strcpy(status, "Account Frozen!");

        printf("\nCurrent status: %s\n", status);

        // input from user to decide status change

        // if the account was active
        if (u.status == 'A') {

          do {
            printf("DO you want to freeze the user? (y/n): ");
            scanf(" %c", &option);
          } while (option != 'y' && option != 'n');

          // changing status
          if (option == 'y') {
            u.status = 'F';
            updated = 1;
            printf("--------------------------------------------\n");
            printf("Account Frozen successfully!\n");
            printf("--------------------------------------------\n");
          }
        }

        // if the account was not active
        else if (u.status == 'F') {
          do {
            printf("DO you want to activate the user? (y/n): ");
            scanf(" %c", &option);
          } while (option != 'y' && option != 'n');

          // changing status
          if (option == 'y') {
            u.status = 'A';
            updated = 1;
            printf("--------------------------------------------\n");
            printf("Account Activated successfully!\n");
            printf("--------------------------------------------\n");
          }
        }
      }

      // pasting all the data in the temp file
      fwrite(&u, sizeof(u), 1, ft);
    }

    // closing files
    fclose(fp);
    fclose(ft);
    printf("%d", found);

    // if found and status changed removing the main and changing temp to main
    // file
    if (found && updated) {
      remove("user.bin");
      rename("temp.bin", "user.bin");
      printf("\n============================================\n");
      printf("USER STATUS UPDATED SUCCESSFULLY\n");
      printf("============================================\n");

    }

    // if user not found
    else {
      printf("\n--------------------------------------------\n");
      printf("USER NOT FOUND!\n");
      printf("--------------------------------------------\n");
      remove("temp.bin");
    }
    // input from user if he wants to input again

    printf("\nPlease enter one of the following:\n");
    printf("1. Freeze another account\n");
    printf("2. Menu\n");
    printf("3. Exit\n");
    do {
      printf("%d", op);
      scanf(" %d", &op);
    } while (op > 3 || op < 1);

    // cleaning terminal before next iteration
    clean();

  } while (op == 1);

  switch (op) {
  case 2:
    return;
  case 3:
    exit(0);
  }
}
