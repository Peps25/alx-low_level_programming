#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - node of a ht
 * @key: key, which is a str
 * The key is unique in the HT
 * @value: value corresponding to key
 * @next: Pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - ht data structure
 * @size: size of the array
 * @array: array of the size @size
 * Each cell of this array is a ptr to the first node of a linked list,
 * because we want our HT to use a chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s - node of a sorted ht
 * @key: key, which is a str
 * The key is unique in the HT
 * @value: value corresponding to key
 * @next: Pointer to the next node of list
 * @sprev: Pointer to the previous element of sorted linked list
 * @snext: Pointer to the next element of sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - the sorted ht data structure
 * @size: size of array
 * @array: array of size @size
 * Each cell of this array is a ptr to the first node of a linked list,
 * because we want our HT to use chaining collision handling
 * @shead: Pointer to the first element of sorted linked list
 * @stail: Pointer to the last element of sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */
