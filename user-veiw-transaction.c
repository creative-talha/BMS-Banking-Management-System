#include "user-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* helper function to print time */

void veiw_transaction() {
  FILE *fp;
  struct transaction t;
  int count = 0, option = 0;

  fp = fopen("transaction.bin", "rb");
  if (fp == NULL) {
    printf("transaction.bin not found or cannot be opened.\n");
    return 1;
  }

  while (fread(&t, sizeof(t), 1, fp) == 1) {
    if (strcmp(t.performed_by, user_info.id) == 0) {

      printf("\nTransaction #%d\n", ++count);
      printf("-------------------------------\n");
      printf("Txn ID          : %lu\n", t.txn_id);
      printf("Account ID      : %s\n", t.account_id);
      printf("Performed By    : %s\n", t.performed_by);
      printf("Amount          : %u\n", t.amount);
      printf("Balance After   : %u\n", t.balance_after);
      printf("Type            : %c\n", t.type);
      printf("Timestamp       : ");
      print_datetime(t.timestamp);
      printf("\n");
    }
  }

  fclose(fp);

  if (count == 0) {
    printf("\nNo transactions found.\n");
  } else {
    printf("\n======= %d TRANSACTION(S) VERIFIED =======\n", count);
  }

  // input from user if he wanna input again
  do {
    printf("\n\nSelect one of the following:\n1.Menu"
           "\n2.Exit\n\nOption:");
    scanf(" %d", &option);
    // cleaning the terminal
    clean();
  } while (option != 1 && option != 2);
  switch (option) {
  case 1:
    return;
    break;

  case 2:
    exit(0);
    break;
  }
}
