#include "banker_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_account(void) {

  struct user u;
  char status[22] = "Active";
  char user_to_look[16];
  int found = 0;
  FILE *fp;
  int option = 1;
  // loop for multiple inpts
  do {
    found = 0;
    printf("PLEASE INPUT THE ACCOUNT NUMBER THAT YOU WANT TO SEARCH: ");
    scanf("%15s", user_to_look);

    fp = fopen("user.bin", "rb");
    if (fp == NULL) {
      perror("Error opening user.bin");
      return;
    }

    while (fread(&u, sizeof(u), 1, fp) == 1) {

      if (u.status == 'A')
        strcpy(status, "Active!");
      else if (u.status == 'F')
        strcpy(status, "Account Freezed!");

      if (strcmp(user_to_look, u.id) == 0) {
        printf("\n\t\t\tUSER FOUND!\n");
        printf("Name: %s\nID: %s\nStatus: %s\nBalance: %u\n", u.Name, u.id,
               status, u.balance);
        found = 1;
        break;
      }
    }

    if (!found) {
      printf("\nUSER NOT FOUND!\n");
    }

    fclose(fp);
    // input from user if he wanna input again
    printf("\n\nplease enter one of the following:\n1.Veiw another "
           "account\n2.Menu\n3.Exit\n\nOption:");
    scanf(" %d", &option);

  } while (option == 1);
  switch (option) {
  case 2:
    return;
    break;

  case 3:
    exit(0);
    break;
  }
}
