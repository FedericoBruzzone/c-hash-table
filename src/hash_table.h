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

/**
 * Create a new hash table item
 *
 * @param k Key
 * @param v Value
 * @return ht_item
 */
static ht_item *ht_make_item(const char *key, const char *value);

/**
 * Create a new hash table
 *
 * @return ht_hash_table
 */
ht_hash_table *ht_make();

/**
 * Delete a hash table item
 *
 * @param i ht_item
 */
static void ht_del_item(ht_item *item);

/**
 * Delete a hash table
 *
 * @param ht ht_hash_table
 */
void ht_del_hash_table(ht_hash_table *ht);
