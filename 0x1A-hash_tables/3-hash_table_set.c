#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: Pointer to the hash table.
 * @key: key to add (cant be an empty string)
 * @value: value associated with the key.
 *
 * Return: 0 if unsuccessful,
 *         Otherwise return 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *value_copy;
	unsigned long int index, ui;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (ui = index; ht->array[ui]; ui++)
	{
		if (strcmp(ht->array[ui]->key, key) == 0)
		{
			free(ht->array[ui]->value);
			ht->array[ui]->value = value_copy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
