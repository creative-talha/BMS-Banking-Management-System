#include "user-header.h"
#include <stdio.h>
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

  // structres
  struct transaction t;
  struct user u;

  // loop for making multiple input
  do {
    if (user_info.status == 'F') {
      printf("Your account has been freezed by the Bank.You can,t make a "
             "trasaction!\n ");
      option = 2;
      break;
    }

    found = 0;
    amount_check = 1;
    sender_confirmation = 0;
    receiver_confirmation = 0;

    /* code */

    // loop in case user is unot found
    while (found == 0) {

      // input for reciever
      printf("Account Number: ");
      scanf("%15s", t.account_id); // safer input

      // OPENING FILE FOR SEARCHING
      fu = fopen("user.bin", "rb");
      if (fu == NULL) {
        printf("Unable to open user file.\n");
        return;
      }

      // searching file
      while (fread(&u, sizeof(u), 1, fu) == 1) {
        not_eligible = 0;

        if (strcmp(t.account_id, user_info.id) == 0) {
          printf("Reciever can not be same as sender\n");
          not_eligible = 1;
          break;
        }

        if ((strcmp(u.id, t.account_id) == 0) && u.status != 'A') {
          printf("The recieiver account has been freezed!\n");
          not_eligible = 1;
          break;
        }

        // if found
        if (strcmp(u.id, t.account_id) == 0) {
          found = 1;
          break;
        }
      }

      // closing the file
      fclose(fu);

      // if user not found
      if ((found == 0) && (not_eligible == 0))
        printf("Account not found! Try again.\n");
    }

    while (amount_check == 1) {
      // as account found now make transaction
      printf("Amount: ");
      scanf("%u", &amount);

      // conditions for validity
      if (amount < 1) {
        printf("\nThe amount should be greater then 0\n");
      }

      else if (amount > user_info.balance) {
        printf("\nInsufficient amount\n");
      }

      else
        amount_check = 0;
    }

    // after the user and account has been confirmed now it is time to make
    // changes

    // oening files
    fu = fopen("user.bin", "rb");
    ft = fopen("temp.bin", "wb");

    if (fu == NULL || ft == NULL) {
      printf("File error.\n");
      return;
    }

    // starting to search and move the files to another
    while (fread(&u, sizeof(u), 1, fu) == 1) {

      // changes in sender balance
      if (strcmp(user_info.id, u.id) == 0) {
        u.balance -= amount;
        sender_confirmation = 1;
      }

      // changes in receiver balance
      if (strcmp(t.account_id, u.id) == 0) {
        u.balance += amount;
        receiver_confirmation = 1;
      }

      // reading all the file in temp
      fwrite(&u, sizeof(u), 1, ft);
    }

    // closing files
    fclose(fu);
    fclose(ft);

    if (sender_confirmation && receiver_confirmation) {
      // COMMIT
      remove("user.bin");
      rename("temp.bin", "user.bin");

      // update in-memory sender balance
      user_info.balance -= amount;

      printf("Transaction successful.\n");
    } else {
      // ROLLBACK
      remove("temp.bin");
      printf("Transaction failed. System error.\n");
      return;
    }

    // now if transaction is done time to save the transaction history

    // SAVE TRANSACTION HISTORY
    FILE *fp = fopen("transaction.bin", "ab");
    if (fp == NULL) {
      printf("Unable to open transaction file.\n");
      return;
    }

    t.txn_id = get_next_txn_id();
    t.amount = amount;
    strcpy(t.performed_by, user_info.id); // sender
    strcpy(t.account_id, t.account_id);
    t.balance_after = user_info.balance;
    t.type = 'T';
    t.timestamp = time(NULL);

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);

    printf("\n\nSelect one of the following:\nMake another transaction\n1.Menu"
           "\n2.Exit\n\nOption:");
    scanf(" %d", &option);
    // cleaning the terminal
    clean();

  } while (option == 1);
  switch (option) {
  case 2:
    return;
    break;

  case 3:
    exit(0);
    break;
  }
}
