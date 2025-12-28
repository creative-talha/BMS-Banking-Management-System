#ifndef user_header_h
#define user_header_h
#include <time.h>

// variables

// functions
void clean(void);
void user_login(void);
int user_menu(void);
void check_balance(void);
void transfer();
unsigned long get_next_txn_id(void);
void print_datetime(time_t raw_time);
void view_transaction();
void user_view_account();
void update_account(void);

#endif