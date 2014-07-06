#include <stdio.h>
// DLL
struct node {
	int value;
	struct node *next;
	struct node *prev;
};

struct node *head;
struct node *tail;

void list_init(void)
{
	head = (struct node *)malloc(sizeof(struct node));
	tail = (struct node *)malloc(sizeof(struct node));

	head->value = -1;
	tail->value = 0x7FFFFFFF;
	/* MSB is a signed bit */
	/* The value is a negative when the signed bit is 1 */

	head->next = tail;
	head->prev = head;
	tail->next = NULL;
	tail->prev = head;

	printf("##DEBUG## list initialize success\n");
}

void add_list(int input)
{
	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));

	new_node->value = input;

	/* need to change */

	printf("##DEBUG## %d is added in list\n", input);
}

void print_all_list(void)
{
	struct node *p;

	printf("##DEBUG## Show all list member\n");

	for (p = head ; p != NULL ; p = p->next) {
		printf("[%d] -> ", p->value);
	}
	printf("\n");
}

void remove_list(int input)
{
	/* need to change */
}

void add_list_with_sort(int input)
{
	struct node *p, *q;
	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->value = input;

	printf("##DEBUG## Add with sort %d\n", input);

	/* need to change */
}

int main()
{
	list_init();

	return 0;
}
