#include "user-header.h"
#include <stdio.h>
int main() {
  FILE *fp;
  struct user u;

  fp = fopen("user.bin", "rb");
  while (fread(&u, sizeof(u), 1, fp) == 1) {
    printf("Name:%s\nId:%s\nBalance:%u\npass:%s,status:%c\n\n", u.Name, u.id,
           u.balance, u.password, u.status);
  }
  fclose(fp);
}
