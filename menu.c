

char banker_menu(void) {
  // variable
  int i = 1;
  char option;
  // input of the option to select
  while (i) {
    printf("\nPlease select one of the option in the given menu:\n"
           "\t\t(from 1 to 6)\n");
    printf("1.Create account\n"
           "2.View account Details\n"
           "3.View Transaction Details\n"
           "4.Update Account Details\n"
           "5.Freeze/Activate Account\n"
           "6.Logout\n");
    printf("OPTION:");
    scanf("%c", &option);
    // validity for option check
    if (option < '1' || option > '6') {
      i = 1;
      printf("The option should be from 1 to 6!\n");
    } else
      i = 0;
  }

  return option;
}
