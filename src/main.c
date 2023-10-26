#include "hash_table.h"
#include <stdio.h>

int main(void) {
  ht_hash_table *ht = ht_make();
  // ht->items[0] = ht_make_item("key", "value");
  // printf("K[0]: %s\n", ht->items[0]->key);
  // printf("V[0]: %s\n", ht->items[0]->value);
  test();
  ht_del_hash_table(ht);
  return 0;
}
