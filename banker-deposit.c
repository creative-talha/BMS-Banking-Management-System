#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void deposit() {
  // variables
  int found = 0, not_eligible = 0;
  int receiver_confirmation = 0;
  int option = 1, amount_check = 1;
  unsigned int amount = 0;

  // files
  FILE *fu, *ft;

  // structures
  struct transaction t;
  struct user u;

  // loop for making multiple transactions
  do {
    found = 0;
    receiver_confirmation = 0;
    amount_check = 1;
    amount = 0;

    // loop until valid receiver is found
    while (found == 0) {
      printf("====================================\n");
      printf("       ENTER RECEIVER ACCOUNT\n");
      printf("====================================\n");
      printf(" Account Number: ");
      scanf("%15s", t.account_id);

      // cleaning the terminal
      clean();

      // open file for searching
      fu = fopen("user.bin", "rb");
      if (fu == NULL) {
        printf("Unable to open user file.\n");
        return;
      }

      while (fread(&u, sizeof(u), 1, fu) == 1) {
        not_eligible = 0;

        if ((strcmp(u.id, t.account_id) == 0) && u.status != 'A') {
          printf("====================================\n");
          printf("           ERROR\n");
          printf(" Receiver account is frozen!\n");
          printf("====================================\n");
          not_eligible = 1;
          break;
        }

        if (strcmp(u.id, t.account_id) == 0) {
          found = 1;
          break;
        }
      }

      fclose(fu);

      if ((found == 0) && (not_eligible == 0)) {
        printf("====================================\n");
        printf("           ERROR\n");
        printf(" Account not found. Try again.\n");
        printf("====================================\n");
      }
    }

    while (amount_check == 1) {
      printf("====================================\n");
      printf("           ENTER AMOUNT\n");
      printf("====================================\n");
      printf(" Amount: ");
      if (scanf("%u", &amount) != 1) {
        while (getchar() != '\n')
          ;
        // cleaning the terminal
        clean();
        printf("====================================\n");
        printf("           ERROR\n");
        printf(" Invalid input. Enter a positive number.\n");
        printf("====================================\n");
        continue;
      }
      clean;

      if (amount < 1) {
        printf("====================================\n");
        printf("           ERROR\n");
        printf(" Amount must be greater than 0\n");
        printf("====================================\n");
      } else
        amount_check = 0;
    }

    // open files to update balances
    fu = fopen("user.bin", "rb");
    ft = fopen("temp.bin", "wb");
    if (fu == NULL || ft == NULL) {
      printf("File error.\n");
      return;
    }

    while (fread(&u, sizeof(u), 1, fu) == 1) {
      if (strcmp(t.account_id, u.id) == 0) {
        u.balance += amount;
        receiver_confirmation = 1;
      }

      fwrite(&u, sizeof(u), 1, ft);
    }

    fclose(fu);
    fclose(ft);

    if (receiver_confirmation) {
      remove("user.bin");
      rename("temp.bin", "user.bin");

      printf("====================================\n");
      printf("          SUCCESS\n");
      printf(" Transaction completed successfully\n");
      printf("====================================\n");
    } else {
      remove("temp.bin");
      printf("====================================\n");
      printf("           ERROR\n");
      printf(" Transaction failed. System error.\n");
      printf("====================================\n");
      return;
    }

    // save transaction history
    FILE *fp = fopen("transaction.bin", "ab");
    if (fp == NULL) {
      printf("Unable to open transaction file.\n");
      return;
    }

    t.txn_id = get_next_txn_id();
    t.amount = amount;
    strcpy(t.performed_by, "Banker"); // sender
    t.type = 'D';                     // deposit
    t.timestamp = time(NULL);

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);

    // repeat / menu / exit

    printf("====================================\n");
    printf("         TRANSACTION MENU\n");
    printf("====================================\n");
    printf(" 1. Make another Deposit\n");
    printf(" 2. Return to main menu\n");
    printf(" 3. Exit\n");
    printf("====================================\n");
    printf(" OPTION: ");
    if (scanf("%d", &option) != 1) {
      while (getchar() != '\n')
        ;
      option = 0; // force loop again
    }

    clean();

  } while (option == 1);

  switch (option) {
  case 2:
    return;
  case 3:
    exit(0);
  }
}
