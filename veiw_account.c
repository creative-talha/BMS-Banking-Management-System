#include "header.h"
#include <stdio.h>
#include <string.h>

void view_account(void) {

  struct user u;
  char status[16] = "Active";
  char user_to_look[16];
  int found = 0;

  printf("PLEASE INPUT THE ACCOUNT NUMBER THAT YOU WANT TO SEARCH: ");
  scanf("%15s", user_to_look);

  FILE *fp = fopen("user.bin", "rb");
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
}
