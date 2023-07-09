vi #include "hash_tables.h"

/**
 * hash_table_delete - will delete a ht
 * @ht: Pointer to a ht
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int ui;

	for (ui = 0; ui < ht->size; ui++)
	{
		if (ht->array[ui] != NULL)
		{
			node = ht->array[ui];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
