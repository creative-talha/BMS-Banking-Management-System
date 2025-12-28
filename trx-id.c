#include "common-structs-header.h"
#include <stdio.h>

unsigned long get_next_txn_id(void) {
  FILE *ft;
  struct transaction t;
  unsigned long next_id = 1;

  ft = fopen("transaction.bin", "rb");
  if (ft == NULL) {
    // No transaction file yet
    return next_id;
  }

  // Move to last record
  fseek(ft, -sizeof(struct transaction), SEEK_END);

  if (fread(&t, sizeof(t), 1, ft) == 1) {
    next_id = t.txn_id + 1;
  }

  fclose(ft);
  return next_id;
}
