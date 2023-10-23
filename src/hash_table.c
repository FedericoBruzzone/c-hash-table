/**
 * Hash table implementation
 */

#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

/**
 * Create a new hash table item
 *
 * @param k Key
 * @param v Value
 * @return ht_item
 */
static ht_item *ht_new_item(const char *k, const char *v) {
  ht_item *i = malloc(sizeof(ht_item));
  i->key = strdup(k);
  i->value = strdup(v);
  return i;
}
