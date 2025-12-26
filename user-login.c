// gcc user-login.c clean.c -o combined_file
//./combined_file

#include "user-header.h"
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
    printf("Account Number:");
    scanf(" %s", account_number);

    printf("Password:");
    scanf(" %s", password);

    // cleaning the terminal
    clean();

    // opening file
    fp = fopen("user.bin", "rb");

    if (!fp) {
      printf("File error\n");
      return 0;
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
        return 0;
      }
    }
    printf("\n\t\tinvalid Credantials!\n\n");
    // closing files
    fclose(fp);

  } while (login == 0);
}