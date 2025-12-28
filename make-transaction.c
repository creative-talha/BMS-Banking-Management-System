#include "common-structs-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void transfer() {
  // variables
  int found = 0, not_eligible = 0, amount_check = 1;
  int sender_confirmation = 0, receiver_confirmation = 0;
  int option = 1;
  unsigned int amount = 0;

  // files
  FILE *fu, *ft;

  // structures
  struct transaction t;
  struct user u;

  // loop for making multiple transactions
  do {
    // check if sender account is frozen
    if (user_info.status == 'F') {
      printf("====================================\n");
      printf("           NOTICE\n");
      printf(" Your account has been freezed by the Bank.\n");
      printf(" You cannot make a transaction.\n");
      printf("====================================\n");
      option = 2;
      break;
    }

    found = 0;
    amount_check = 1;
    sender_confirmation = 0;
    receiver_confirmation = 0;

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

        if (strcmp(t.account_id, user_info.id) == 0) {
          printf("====================================\n");
          printf("           ERROR\n");
          printf(" Receiver cannot be the same as sender\n");
          printf("====================================\n");
          not_eligible = 1;
          break;
        }

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

    // loop until valid amount is entered
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
      } else if (amount > user_info.balance) {
        printf("====================================\n");
        printf("           ERROR\n");
        printf(" Insufficient balance\n");
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
      if (strcmp(user_info.id, u.id) == 0) {
        u.balance -= amount;
        sender_confirmation = 1;
      }
      if (strcmp(t.account_id, u.id) == 0) {
        u.balance += amount;
        receiver_confirmation = 1;
      }

      fwrite(&u, sizeof(u), 1, ft);
    }

    fclose(fu);
    fclose(ft);

    if (sender_confirmation && receiver_confirmation) {
      remove("user.bin");
      rename("temp.bin", "user.bin");
      user_info.balance -= amount;

      printf("====================================\n");
      printf("          SUCCESS\n");
      printf(" Transaction completed successfully\n");
      printf(" New Balance: %u\n", user_info.balance);
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
    strcpy(t.performed_by, user_info.id); // sender
    // receiver account already in t.account_id
    t.balance_after = user_info.balance;
    t.type = 'T';
    t.timestamp = time(NULL);

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);

    // repeat / menu / exit

    // cleaning terminal
    clean();

    printf("====================================\n");
    printf("         TRANSACTION MENU\n");
    printf("====================================\n");
    printf(" 1. Make another transaction\n");
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
