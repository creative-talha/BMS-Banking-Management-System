#include "user-header.h"
#include <stdio.h>
#include <string.h>

void transfer() {
  // variables
  int found = 0, not_eligible = 0, amount_check = 1, sender_confirmation = 0,
      receiver_confirmation = 0;
  unsigned int amount = 0;
  // files
  FILE *fu, *ft;
  // structres
  struct transaction t;
  struct user u;

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
    printf("Amount:");
    scanf(" %u", &amount);

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

  // starting to search and move the files to another
  while (fread(&u, sizeof(u), 1, fu) == 1) {
    // changes in sender balance
    if (strcmp(user_info.id, u.id) == 0) {
      printf("Comparing sender %s with record %s\n", user_info.id, u.id);

      u.balance = u.balance - amount;
      user_info.balance -= amount;
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
  // changing the files
  remove("user.bin");
  rename("temp.bin", "user.bin");
}