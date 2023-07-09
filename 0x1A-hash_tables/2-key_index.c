#include "hash_tables.h"

/**
 * key_index - Gets the index at which a key
 *      pair should be stored in array of a hash table
 * @key: key to get the index of
 * @size: size of the array of the hash table
 *
 * Return: index of the key
 * Description: the djb2 algorithm is used
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
