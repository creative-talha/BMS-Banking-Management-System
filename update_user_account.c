#include "header.h"
#include <stdio.h>
#include <string.h>

void update_user_account(void) {

  struct user u;
  char user_to_look[16];
  char choice;
  int found = 0;

  printf("PLEASE INPUT THE ACCOUNT NUMBER THAT YOU WANT TO SEARCH: ");
  scanf("%15s", user_to_look);

  FILE *fp = fopen("user.bin", "rb");
  FILE *ft = fopen("temp.bin", "wb");

  if (!fp || !ft) {
    printf("File error\n");
    return;
  }

  while (fread(&u, sizeof(u), 1, fp) == 1) {

    if (strcmp(user_to_look, u.id) == 0) {
      found = 1;

      printf("\nWhat do you want to change?\n");
      printf("1. Name\n2. ID\n3. Password\nChoice: ");
      scanf(" %c", &choice);

      switch (choice) {

      case '1': {
        char n1[51], n2[51];
        do {
          printf("New Name: ");
          scanf("%50s", n1);
          printf("Confirm Name: ");
          scanf("%50s", n2);
        } while (strcmp(n1, n2) != 0);
        strcpy(u.Name, n1);
        break;
      }

      case '2': {
        char i1[16], i2[16];
        do {
          printf("New ID: ");
          scanf("%15s", i1);
          printf("Confirm ID: ");
          scanf("%15s", i2);
        } while (strcmp(i1, i2) != 0);
        strcpy(u.id, i1);
        break;
      }

      case '3': {
        char p1[21], p2[21];
        do {
          printf("New Password: ");
          scanf("%20s", p1);
          printf("Confirm Password: ");
          scanf("%20s", p2);
        } while (strcmp(p1, p2) != 0);
        strcpy(u.password, p1);
        break;
      }

      default:
        printf("Invalid option\n");
        break;
      }
    }

    fwrite(&u, sizeof(u), 1, ft);
  }

  fclose(fp);
  fclose(ft);

  if (!found) {
    printf("\nUSER NOT FOUND!\n");
    remove("temp.bin");
    return;
  } else {
    remove("user.bin");
    rename("temp.bin", "user.bin");

    printf("\nUSER UPDATED SUCCESSFULLY\n");
  }
}
