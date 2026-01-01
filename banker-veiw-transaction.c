#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void banker_view_transaction() {
  FILE *fp;
  struct transaction t;
  int count = 0, option = 0;
  char user_to_look[20];
  // loop for multiple choices
  do {
    count = 0;
    fp = fopen("transaction.bin", "rb");
    if (fp == NULL) {
      printf("====================================\n");
      printf("           ERROR\n");
      printf(" transaction.bin not found or cannot be opened.\n");
      printf("====================================\n");
      return;
    }

    // input to enter the user name to check for transactions
    printf("ACCOUNT NUMBER: ");
    scanf("%19s", user_to_look);

    printf("====================================\n");
    printf("       TRANSACTION HISTORY\n");
    printf("====================================\n\n\n");

    while (fread(&t, sizeof(t), 1, fp) == 1) {
      if ((strcmp(t.performed_by, user_to_look) == 0) ||
          strcmp(t.account_id, user_to_look) == 0) {
        count++;
        printf("====================================\n");
        printf(" Transaction #%d\n", count);
        printf("------------------------------------\n");
        printf(" Txn ID        : %lu\n", t.txn_id);
        printf(" Account ID    : %s\n", t.account_id);
        printf(" Performed By  : %s\n", t.performed_by);
        printf(" Amount        : %u\n", t.amount);
        printf(" Type          : %c\n", t.type);
        printf(" Timestamp     : ");
        print_datetime(t.timestamp);
        printf("\n");
      }
    }

    fclose(fp);

    if (count == 0) {
      printf("====================================\n");
      printf("           INFO\n");
      printf(" No transactions found.\n");
      printf("====================================\n");
    } else {
      printf("====================================\n");
      printf("    %d TRANSACTION(S) VERIFIED\n", count);
      printf("====================================\n");
    }

    // input from user if he wants to continue
    printf("\n\n");
    printf("====================================\n");
    printf("         TRANSACTION MENU\n");
    printf("====================================\n");
    printf(" 1. Veiw another transaction history\n");
    printf(" 2. Return to main menu\n");
    printf(" 3. Exit\n");
    printf("====================================\n");

    do {
      printf(" OPTION: ");
      if (scanf("%d", &option) != 1) {
        while (getchar() != '\n')
          ;         // clear invalid input
        option = 0; // force loop to repeat
      }
    } while (option != 1 && option != 2 && option != 3);

    printf("\n\n");
  } while (option == 1);

  switch (option) {
  case 2:
    return;
  case 3:
    exit(0);
  }
}
