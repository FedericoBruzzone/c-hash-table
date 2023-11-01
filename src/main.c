#include "hash_table.h"
#include <stdio.h>

int main(void) {
  char *keys[] = {"key1", "key2", "key3", "key4", "key5"};
  char *values[] = {"val1", "val2", "val3", "val4", "val5"};
  const size_t size = sizeof(keys) / sizeof(keys[0]);

  // Create hash table
  ht_hash_table *ht = ht_make();

  // Insert items
  for (size_t i = 0; i < size; i++) {
    ht_insert(ht, keys[i], values[i]);
  }

  // Print all items
  for (size_t i = 0; i < size; i++) {
    char *value = ht_search(ht, keys[i]);
    printf("%s: %s\n", keys[i], value);
  }
  printf("\n");

  // Delete first and second items
  ht_delete(ht, keys[0]);
  ht_delete(ht, keys[1]);
  // Delete first and second key and value from keys and values incrementing pointer
  char **keys_sliced = keys + 2;
  char **values_sliced = values + 2;

  // Print all items
  for (size_t i = 0; i < size - 2; i++) {
    char *value = ht_search(ht, keys_sliced[i]);
    printf("%s: %s\n", keys_sliced[i], value);
  }
  printf("\n");

  // Delete hash table
  ht_del_hash_table(ht);
  return 0;
}
