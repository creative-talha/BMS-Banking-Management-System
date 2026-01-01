#ifndef common_structs_header_h
#define common_structs_header_h
#include <time.h>

// variables

// structures
struct user {
  char id[16], Name[51], password[21], status;
  unsigned int balance;
};
extern struct user user_info;

struct transaction {
  unsigned long txn_id; // Unique transaction number
  char account_id[16];  // Account affected
  char type;            // 'D' = Deposit, 'W' = Withdraw, 'T' = Transfer
  unsigned int amount;
  char performed_by[16]; // ID of sender (user ID or banker ID)
  time_t timestamp;
};

// function
void clean(void);

#endif