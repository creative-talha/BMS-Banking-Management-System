#include <stdio.h>
void create_account() {
  // variables
  char password[21], password2[21], id[51], id2[51];
  int k = 1;

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

    printf("ID:");
    scanf("%50s", id);

    printf("Confirm ID:");
    scanf("%50s", id2);

    printf("PASSWORD:");
    scanf("%20s", password);

    printf("Confirm PASSWORD:");
    scanf("%20s", password2);

    // validity to confirm that the id and passwords are confirmed by entring
    // again
    if (!(strcmp(id, id2) || strcmp(password2, password)))
      k = 0;
    else {
      k = 1;
      printf("THe password or User name is incorrect\n");
    }
  }
  // file handling to save the data for future use
  FILE *fp;
  fp = fopen("user.txt", "a");
  fprintf(fp, "%s %s\n", id, password);
}