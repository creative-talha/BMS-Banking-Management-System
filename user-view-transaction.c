#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void view_transaction() {
  FILE *fp;
  struct transaction t;
  int count = 0, option = 0;

  fp = fopen("transaction.bin", "rb");
  if (fp == NULL) {
    printf("====================================\n");
    printf("           ERROR\n");
    printf(" transaction.bin not found or cannot be opened.\n");
    printf("====================================\n");
    return;
  }

  printf("====================================\n");
  printf("       TRANSACTION HISTORY\n");
  printf("====================================\n");

  while (fread(&t, sizeof(t), 1, fp) == 1) {
    if ((strcmp(t.performed_by, user_info.id) == 0) ||
        (strcmp(t.account_id, user_info.id))) {
      count++;
      printf("====================================\n");
      printf(" Transaction #%d\n", count);
      printf("------------------------------------\n");
      printf(" Txn ID        : %lu\n", t.txn_id);
      printf(" Account ID    : %s\n", t.account_id);
      printf(" Performed By  : %s\n", t.performed_by);
      printf(" Amount        : %u\n", t.amount);
      printf(" Balance After : %u\n", t.balance_after);
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
  do {
    printf("====================================\n");
    printf("         TRANSACTION MENU\n");
    printf("====================================\n");
    printf(" 1. Return to main menu\n");
    printf(" 2. Exit\n");
    printf("====================================\n");
    printf(" OPTION: ");

    if (scanf("%d", &option) != 1) {
      while (getchar() != '\n')
        ;         // clear invalid input
      option = 0; // force loop again
    }

    clean(); // clear screen for next action
  } while (option != 1 && option != 2);

  switch (option) {
  case 1:
    return;
  case 2:
    exit(0);
  }
}
