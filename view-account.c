#include "banker-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_account(void) {
  struct user u;
  const char *status = "Active";
  char user_to_look[16];
  int found = 0;
  FILE *fp;
  int option = 1;

  // loop for multiple inputs
  do {
    found = 0;
    printf("\n============================================\n");
    printf("           VIEW ACCOUNT DETAILS             \n");
    printf("============================================\n");

    printf("PLEASE INPUT THE ACCOUNT NUMBER THAT YOU WANT TO SEARCH: ");
    scanf("%15s", user_to_look);

    fp = fopen("user.bin", "rb");
    if (fp == NULL) {
      perror("Error opening user.bin");
      return;
    }

    while (fread(&u, sizeof(u), 1, fp) == 1) {
      if (u.status == 'A')
        status = "Active";
      else if (u.status == 'F')
        status = "Account Frozen!";

      if (strcmp(user_to_look, u.id) == 0) {
        printf("\n============================================\n");
        printf("\t\tUSER FOUND!\n");
        printf("============================================\n");
        printf("Name    : %s\n", u.Name);
        printf("ID      : %s\n", u.id);
        printf("Status  : %s\n", status);
        printf("Balance : %u\n", u.balance);
        printf("============================================\n");
        found = 1;
        break;
      }
    }

    if (!found) {
      printf("\n--------------------------------------------\n");
      printf("USER NOT FOUND!\n");
      printf("--------------------------------------------\n");
    }

    fclose(fp);

    // input from user if he wants to input again
    printf("\nPlease enter one of the following:\n");
    printf("1. View another account\n");
    printf("2. Menu\n");
    printf("3. Exit\n");
    printf("Option: ");
    scanf(" %d", &option);

  } while (option == 1);

  switch (option) {
  case 2:
    return;
  case 3:
    exit(0);
  }
}
