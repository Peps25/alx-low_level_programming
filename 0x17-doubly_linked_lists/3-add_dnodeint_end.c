#include "lists.h"

/**
 * add_dnodeint_end - will add new node at the end of dlistint_t list.
 * @head: Pointer to the first element of the list
 * @n: integer to be set in the new node
 * Return: new element address, or NULL if it fails
 **/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *aux = *head;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (aux)
	{
		while (aux->next)
			aux = aux->next;
		new->prev = aux;
		aux->next = new;
	}
	else
	{
		*head = new;
		new->prev = NULL;
	}

	return (new);
}
