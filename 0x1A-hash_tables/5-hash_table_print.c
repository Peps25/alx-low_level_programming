#include "hash_tables.h"

/**
 * hash_table_print - will prints a ht
 * @ht: Pointer to the ht to print
 *
 * Description: key pairs are printed in the order
 *              they appear in the array of the ht
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int ui;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (ui = 0; ui < ht->size; ui++)
	{
		if (ht->array[ui] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[ui];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
