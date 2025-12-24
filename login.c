

// definition of password and id
#define id 12345
#define password "admin1"

// login function
void login() { // variables
  int input_id, loop_counter = 1;
  char input_password[10];

  // loop
  do {
    // login inputs
    printf("User id:");
    scanf(" %d", &input_id);
    int c = 0;
    while (c = getchar() != '\n') {
    }
    printf("Password:");
    scanf(" %9s", input_password);
    c = 0;
    while (c = getchar() != '\n')
      ;

    // validity condition
    if (input_id != id || strcmp(input_password, password))
      printf("Invalid Credantial please try again!\n");
    else
      loop_counter--;

  }
  // loop running condition
  while (loop_counter);
  return 0;
}
