#include "lists.h"

/**
 * add_dnodeint - will add new node at the beginning of dlistint_t list
 * @head: Pointer to the first element of the list
 * @n: integer to be set in the new node
 * Return: new element address, or NULL if it fails
 **/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}
