#ifndef myfunc_h
#define myfunc_h
// structures
struct user {
  char id[16], Name[51], password[21], status;
  unsigned int balance;
};
// functions
void clean(void);
void login();
char banker_menu(void);
void create_account();
void view_account(void);
void update_user_account(void);
void freeze_activate_account();
int main();

#endif
