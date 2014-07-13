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
	struct node *new_node, *temp_node;

	new_node = (struct node *)malloc(sizeof(struct node));

	new_node->value = input;

	/* need to change */
	new_node->next = head->next;
	new_node->prev = head->prev;
	temp_node = new_node->next;
	head->next = new_node;
	temp_node->prev = new_node;

	printf("##DEBUG## %d add in the list \n", input);
}

void print_all_list(void)
{
	struct node *p;

	printf("##DEBUG## Show all list member\n");

	for (p = head ; p != NULL ; p = p->next) {
		printf("[%d] -> ", p->value);
	}
	printf("\n");
	free(p);
}

void remove_list(int input)
{
	/* need to change */
	struct node *p, *q, *r;

	printf("##DEBUG## Remove %d \n", input);

	for (p = head, q = head, r = head ; p != NULL ; p = p->next) {

		if (input == p->value) {
			q = p->prev;
			q->next = p->next;
			r = p->next;
			r->prev = p->prev;
			free(p);
			break;
		}
	}
}

void add_list_with_sort(int input)
{
	struct node *p, *q;
	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->value = input;

	printf("##DEBUG## Add with sort %d\n", input);

	/* need to change */
	for (p = head, q = head ; p != NULL ; p = p->next) {
		q = p->prev;
		if ((q->value < input) && (input < p->value)) {
			new_node->next = q->next;
			new_node->prev = p->prev;
			q->next = new_node;
			p->prev = new_node;
			return;
		}
		else if (input == p->value) {
			printf("##DEBUG## Already exist	%d \n", input);
			free(new_node);
			return;
		}
	}
}

int main()
{
	list_init();

//	add_list(10);
//	add_list(20);
//	add_list(30);
//	add_list(40);
//	add_list(50);
//	add_list(60);






	add_list_with_sort(10);
	add_list_with_sort(20);
	add_list_with_sort(30);
	add_list_with_sort(40);
	add_list_with_sort(50);

	print_all_list();

	remove_list(30);

	print_all_list();

	add_list_with_sort(45);

	print_all_list();

	return 0;
}
