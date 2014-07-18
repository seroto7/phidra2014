#include <stdio.h>
#include <stdlib.h>

//#include "check_time.h"

#define MAX_INPUT 500

/* Singly Linked List */

typedef struct list {
	struct list *next;
	int value;
} list_t;

list_t* head;
list_t* tail;

void init_list(void)
{
	head = (list_t*)malloc(sizeof(list_t));
	tail = (list_t*)malloc(sizeof(list_t));

	head->next = tail;
	head->value = -1;
	tail->next = NULL;
	tail->value = 0x7FFFFFFF;
}

void add_list(int v)
{
	list_t *temp;
	
	temp = (list_t*)malloc(sizeof(list_t));
	temp->value = v;

	temp->next = head->next;
	head->next = temp;
}

void show_all_list(void)
{
	list_t *p;
	int i = 0;

	if (MAX_INPUT > 100) {
		printf("Too Much members in list\n");
		return;
	}

	if (head->next == tail)
		printf("List is Empty\n");

	for (p = head->next ; p != tail ; p = p->next) {
		printf("[%3d]   ", p->value);

		if ((i%10) > 9)
			printf("\n");

		i++;
	}

	printf("\n");
}

list_t* find_list(int v)
{
	list_t *p;

	for (p = head ; p != tail ; p = p->next)
		if (v == p->value)
			break;

	return p;
}

/* Insert Sorting */
void add_list_with_sort(int v)
{
	list_t *temp, *p, *q;
	int i = 0;
	
	temp = (list_t*)malloc(sizeof(list_t));
	temp->value = v;

	for (q = head, p = head ; p != NULL ; q = p, p = p->next) {
		if ((q->value < temp->value) && (temp->value < p->value)) {
			temp->next = q->next;
			q->next = temp;
			return;
		} else if (temp->value == p->value) {
			printf("[ERR] Same Value\n");
			free(temp);
			return;
		}
	}
}

void remove_list(list_t *temp)
{
	list_t *p;

	for (p = head ; p != tail ; p = p->next)
		if (p->next == temp)
			break;

	p->next = temp->next;
	free(temp);
}

void remove_all_list(void)
{
	list_t *p, *temp;

	while (1) {
		if (head->next == tail)
			break;

		remove_list(find_list(head->next->value));
	}
}

/* bubble sorting */
void sort_list(void)
{
	list_t *prev, *curr, *next;
	list_t *p;

	prev = head;
	curr = prev->next;
	next = curr->next;

	if (curr == tail || next == tail) {
		printf("No node for sorting\n");
		return;
	}

	for (p = head ; p != tail ; p = p->next) {
		prev = head;
		curr = prev->next;
		next = curr->next;

		while (next != tail) {
			if (curr->value > next->value) {
				prev->next = next;
				curr->next = next->next;
				next->next = curr;
			}

			prev = prev->next;
			curr = prev->next;
			next = curr->next;
		}
	}
}

/* function pointer */
/* We can make a pointer, removed name declaration */
void inputer(int *r_value, void (*input_method)(int))
{
	int i;

	for (i = 0 ; i < MAX_INPUT ; i++) {
		(*input_method)(r_value[i]);
	}
}

int main()
{
	list_t *t;
	int i, input[MAX_INPUT];
//	struct timeval start, end;

	for (i = 0 ; i < MAX_INPUT ; i++)
		input[i] = rand();

	init_list();

//	gettimeofday(&start, NULL);
	inputer(input, add_list_with_sort);
//	gettimeofday(&end, NULL);
	show_all_list();
/*
	printf("Insert with Sort : %lu.%lu\n",
			end.tv_sec - start.tv_sec,
			end.tv_usec - start.tv_usec);
*/

	remove_all_list();

//	gettimeofday(&start, NULL);
	inputer(input, add_list);
	sort_list();
//	gettimeofday(&end, NULL);
	show_all_list();
/*
	printf("Insert before Sort : %lu.%lu\n",
			end.tv_sec - start.tv_sec,
			end.tv_usec - start.tv_usec);
*/

	return 0;
}

