#include "hash_tables.h"

/**
 * hash_table_create - will create hash table.
 * @size: size of array.
 *
 * Return: NULL, if an error occurs.
 *         otherwise return a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int ui;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (ui = 0; ui < size; ui++)
		ht->array[ui] = NULL;

	return (ht);
}
