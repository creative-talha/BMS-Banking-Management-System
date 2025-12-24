#include "header.h"
#include <stdio.h>
void create_account() {
  // variables

  int k = 1, i = 10;
  char password2[21], id2[51];
  struct user u;

  // some rules for the banker to know before saving data
  printf("\t\t\tSOME RULES TO NOTE!\n");

  printf("1.There should be no space in between the id or password.\n\n");

  printf("2.The ID should be upto 50 characters long the other characters "
         "morethen 50 will not be considererd\n\n");

  printf("3.The Password should be upto 20 characters long the other "
         "characters more then 20 will not be considererd\n\n");

  // loop in case the input is incorrect
  while (k) {
    // input
    printf("Name:");
    scanf("%50s", u.Name);

    printf("ID:");
    scanf("%15s", u.id);

    printf("Confirm ID:");
    scanf("%15s", id2);

    printf("PASSWORD:");
    scanf("%20s", u.password);

    printf("Confirm PASSWORD:");
    scanf("%20s", password2);
    // status
    u.status = 'A';
    // balance
    u.balance = 0;

    // validity to confirm that the id and passwords are confirmed by entring
    // again
    if (!(strcmp(u.id, id2) || strcmp(password2, u.password)))
      k = 0;
    else {
      k = 1;
      printf("THe password or User name is incorrect\n");
    }
  }
  // file handling to save the data for future use
  FILE *fp;
  fp = fopen("user.bin", "ab");
  fwrite(&u, sizeof(u), 1, fp);
  fclose(fp);
}
