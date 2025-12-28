#ifndef user_header_h
#define user_header_h
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
  unsigned int balance_after;
  char performed_by[16]; // ID of sender (user ID or banker ID)
  time_t timestamp;
};

// functions
int main();
void clean(void);
void user_login(void);
int user_menu(void);
void check_balance(void);
void transfer();
unsigned long get_next_txn_id(void);
void print_datetime(time_t raw_time);
void veiw_transaction();
void user_view_account();
void update_account(void);

#endif