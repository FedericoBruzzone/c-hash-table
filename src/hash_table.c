/**
 * Hash table implementation
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"
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

static int ht_hash(const char *s, const int a, const int m) {
  long hash = 0;
  const int len_s = strlen(s);
  for (int i = 0; i < len_s; i++) {
    hash += (long)pow(a, len_s + (i + 1)) * s[i];
    hash = hash % m;
  }
  return (int)hash;
}

static int ht_hash_double_hashing(const char *s, const int num_buckets,
                                  const int attempt) {
  const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
  const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

static ht_item HT_DELETED_ITEM = {NULL, NULL};

void ht_insert(ht_hash_table *ht, const char *key, const char *value) {
  ht_item *item = ht_make_item(key, value);
  int index = ht_hash_double_hashing(item->key, ht->size, 0);
  ht_item *cur_item = ht->items[index];
  int i = 1;
  while (cur_item != NULL) {
    if (cur_item != &HT_DELETED_ITEM) {
      if (strcmp(cur_item->key, key) == 0) {
        ht_del_item(cur_item);
        ht->items[index] = item;
        return;
      }
    }
    index = ht_hash_double_hashing(item->key, ht->size, i);
    ht_item *cur_item = ht->items[index];
    i++;
  }
  ht->items[index] = item;
  ht->count++;
}

char *ht_search(ht_hash_table *ht, const char *key) {
  int index = ht_hash_double_hashing(key, ht->size, 0);
  ht_item *item = ht->items[index];
  int i = 1;
  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(item->key, key) == 0) {
        return item->value;
      }
    }
    index = ht_hash_double_hashing(key, ht->size, i);
    item = ht->items[index];
    i++;
  }
  return NULL;
}

void ht_delete(ht_hash_table *ht, const char *key) {
  int index = ht_hash_double_hashing(key, ht->size, 0);
  ht_item *item = ht->items[index];
  int i = 1;
  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(item->key, key) == 0) {
        ht_del_item(item);
      }
    }
    index = ht_hash_double_hashing(key, ht->size, i);
    item = ht->items[index];
    i++;
  }
  ht->count--;
}

