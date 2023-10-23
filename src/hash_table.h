/**
 * Hash table data structure
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
  int size;
  int count;
  ht_item **items;
} ht_hash_table;
