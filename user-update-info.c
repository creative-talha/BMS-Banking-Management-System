#include "user-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void update_account(void) {

  struct user u;

  char choice;
  int option = 1;
  FILE *fp, *ft;

  fp = fopen("user.bin", "rb");
  ft = fopen("temp.bin", "wb");

  if (!fp || !ft) {
    printf("\n====================================\n");
    printf("        FILE ACCESS ERROR\n");
    printf("====================================\n");
    printf("Unable to open required files.\n");
    return;
  }

  while (fread(&u, sizeof(u), 1, fp) == 1) {

    if (strcmp(user_info.id, u.id) == 0) {

      printf("\n====================================\n");
      printf("        UPDATE ACCOUNT INFO\n");
      printf("====================================\n");
      printf(" Logged-in User ID : %s\n", user_info.id);
      printf("------------------------------------\n");
      printf(" 1. Change Name\n");
      printf(" 2. Change ID\n");
      printf(" 3. Change Password\n");
      printf("------------------------------------\n");
      printf(" Enter Choice : ");
      scanf(" %c", &choice);

      clean();

      switch (choice) {

      case '1': {
        char n1[51], n2[51];
        printf("\n---------- CHANGE NAME ----------\n");
        do {
          printf(" New Name     : ");
          scanf("%50s", n1);
          printf(" Confirm Name : ");
          scanf("%50s", n2);
        } while (strcmp(n1, n2) != 0);
        strcpy(u.Name, n1);
        printf("\n Name updated successfully.\n");
        break;
      }

      case '2': {
        char i1[16], i2[16];
        printf("\n---------- CHANGE ID ------------\n");
        do {
          printf(" New ID       : ");
          scanf("%15s", i1);
          printf(" Confirm ID   : ");
          scanf("%15s", i2);
        } while (strcmp(i1, i2) != 0);
        strcpy(u.id, i1);
        printf("\n ID updated successfully.\n");
        break;
      }

      case '3': {
        char p1[21], p2[21];
        printf("\n-------- CHANGE PASSWORD --------\n");
        do {
          printf(" New Password     : ");
          scanf("%20s", p1);
          printf(" Confirm Password : ");
          scanf("%20s", p2);
        } while (strcmp(p1, p2) != 0);
        strcpy(u.password, p1);
        printf("\n Password updated successfully.\n");
        break;
      }

      default:
        printf("\n Invalid option selected.\n");
        break;
      }
    }

    fwrite(&u, sizeof(u), 1, ft);
  }

  fclose(fp);
  fclose(ft);

  remove("user.bin");
  rename("temp.bin", "user.bin");

  printf("\n====================================\n");
  printf("     ACCOUNT UPDATED SUCCESSFULLY\n");
  printf("====================================\n");

  printf("\n------------------------------------\n");
  printf(" 1. Update Another Field\n");
  printf(" 2. Return to Menu\n");
  printf(" 3. Exit Application\n");
  printf("------------------------------------\n");
  printf(" Enter Option : ");
  scanf(" %d", &option);

  clean();

  switch (option) {
  case 2:
    return;
  case 3:
    exit(0);
  }
}
