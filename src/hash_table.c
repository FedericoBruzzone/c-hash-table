/**
 * Hash table implementation
 */

#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item *ht_make_item(const char *key, const char *value) {
  ht_item *i = malloc(sizeof(ht_item));

  // i->key = strdup(key);
  i->key = malloc(strlen(key) + 1);
  memcpy(i->key, key, strlen(key) + 1);
  // i->value = strdup(value);
  i->value = malloc(strlen(value) + 1);
  memcpy(i->value, value, strlen(value) + 1);

  return i;
}

ht_hash_table *ht_make() {
  ht_hash_table *ht = malloc(sizeof(ht_hash_table));

  ht->size = 53;
  ht->count = 0;
  ht->items = calloc((size_t)ht->size, sizeof(ht_item *));
  return ht;
}

static void ht_del_item(ht_item *item) {
  free(item->key);
  free(item->value);
  free(item);
}

void ht_del_hash_table(ht_hash_table *ht) {
  for (int i = 0; i < ht->size; i++) {
    ht_item *item = ht->items[i];
    if (item != NULL) {
      ht_del_item(item);
    }
  }
  free(ht->items);
  free(ht);
}
