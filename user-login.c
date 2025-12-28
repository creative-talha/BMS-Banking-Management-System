// gcc user-login.c clean.c -o combined_file
//./combined_file

#include "common-structs-header.h"
#include <stdio.h>
#include <string.h>

// structure for keeping user info
struct user user_info;

void user_login(void) {
  // variables
  char password[21], account_number[16];
  char login = 0;
  // structures
  struct user u;
  // file
  FILE *fp;

  // loop in case invalid credantials
  do {
    // input
    printf("====================================\n");
    printf("           USER LOGIN                \n");
    printf("====================================\n");
    printf(" Account Number : ");
    scanf(" %15s", account_number);

    printf(" Password       : ");
    scanf(" %20s", password);
    printf("====================================\n");

    // cleaning the terminal
    clean();

    // opening file
    fp = fopen("user.bin", "rb");

    if (!fp) {
      printf("File error\n");
      return;
    }

    // starting reading file
    while (fread(&u, sizeof(u), 1, fp)) {

      // if found
      if ((strcmp(u.id, account_number) == 0) &&
          (strcmp(u.password, password) == 0)) {
        login = 1;

        // transfrering the info of the user to a global structure
        user_info.balance = u.balance;
        strcpy(user_info.id, u.id);
        strcpy(user_info.Name, u.Name);
        strcpy(user_info.password, u.password);
        user_info.status = u.status;
        return;
        fclose(fp);
      }
    }
    printf("====================================\n");
    printf(" Invalid credentials. Try again.\n");
    printf("====================================\n");

    // closing files
    fclose(fp);

  } while (login == 0);
}