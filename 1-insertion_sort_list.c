#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list ussing insertion sorting algorithm
 * @list: pointer to the head of the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list, *current, *tmp;

	if (list == NULL || (*list) == NULL || head == NULL || head->next == NULL)
		return;

	head = head->next;
	while (head != NULL)
	{
		current = head;
		tmp = current->prev;
		while (current && tmp)
		{
			if (current->n < tmp->n)
			{
				current->prev = tmp->prev;
				tmp->next = current->next;
				current->next = tmp;
				tmp->prev = current;
				if (tmp->next != NULL)
					tmp->next->prev = tmp;
				if (current->prev == NULL)
				{
					*list = current;
					print_list(*list);
					break;
				}
				current->prev->next = current;
				tmp = current->prev;
				print_list(*list);
			} else
				tmp = tmp->prev;
		}
		head = head->next;
	}
}
