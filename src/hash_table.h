/**
 * Hash table data structure.
 *
 * @file hash_table.h
 * @brief Hash table data structure
 */

#define HT_PRIME_1 151
#define HT_PRIME_2 163

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
 * Create a new hash table item.
 *
 * @param k Key
 * @param v Value
 * @return ht_item
 */
static ht_item *ht_make_item(const char *key, const char *value);

/**
 * Create a new hash table.
 *
 * @return ht_hash_table
 */
ht_hash_table *ht_make();

/**
 * Delete a hash table item.
 *
 * @param i ht_item
 */
static void ht_del_item(ht_item *item);

/**
 * Delete a hash table.
 *
 * @param ht ht_hash_table
 */
void ht_del_hash_table(ht_hash_table *ht);

/**
 * Compute the hash of a string.
 *
 * @param s String
 * @param c Prime number
 * @param num_buckets Size of the hash table
 * @return int
 */
static int ht_hash(const char *s, const int c, const int num_buckets);

/**
 * Compute the hash of a string using the open addressing method with double
 * hashing.
 * Double hashing is a technique in which the second hash function is used to
 * avoid clustering and distribute the keys more uniformly to the detriment of
 * the cache performance. The linear probing and quadratic probing techniques
 * generate clusters of keys that are close to each other but offer a good cache
 * performance.
 *
 * @param s String
 * @param num_buckets Size of the hash table
 * @param attempt Attempt number
 * @return int
 */
static int ht_hash_double_hashing(const char *s, const int num_buckets,
                                  const int attempt);

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

