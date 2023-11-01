/**
 * Hash table data structure.
 *
 * @file hash_table.h
 * @brief Hash table data structure
 */

/**
 * @brief Hash table item
 *
 * @param key Key of the item
 * @param value Value of the item
 */
typedef struct {
  char *key;
  char *value;
} ht_item;

/**
 * @brief Hash table
 *
 * @param size Size of the hash table
 * @param count Number of items in the hash table
 * @param items Items in the hash table
 */
typedef struct {
  int base_size;
  int size;
  int count;
  ht_item **items;
} ht_hash_table;

/**
 * Create a new hash table.
 *
 * @return ht_hash_table
 */
ht_hash_table *ht_make();

/**
 * Delete a hash table.
 *
 * @param ht ht_hash_table
 */
void ht_del_hash_table(ht_hash_table *ht);

/**
 * Insert a key-value pair into a hash table.
 * The average case time complexity is O(1).
 * The worst case time complexity is O(n).
 *
 * @param ht ht_hash_table
 * @param key Key
 * @param value Value
 */
void ht_insert(ht_hash_table *ht, const char *key, const char *value);

/**
 * Search for a key in a hash table.
 * The average case time complexity is O(1).
 * The worst case time complexity is O(n).
 *
 * @param ht ht_hash_table
 * @param key Key
 * @return char*
 */
char *ht_search(ht_hash_table *ht, const char *key);

/**
 * Delete a key-value pair from a hash table.
 * The average case time complexity is O(1).
 * The worst case time complexity is O(n).
 *
 * @param h ht_hash_table
 * @param key Key
 */
void ht_delete(ht_hash_table *h, const char *key);
