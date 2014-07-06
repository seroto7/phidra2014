#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

struct node *head;
struct node *tail;

void list_init(void)
{
	head = (struct node *)malloc(sizeof(struct node));
	tail = (struct node *)malloc(sizeof(struct node));

	head->value = -1;
	tail->value = 0x7FFFFFFF;
	// MSB is a signed bit
	// The value is a negative when the signed bit is 1

	head->next = tail;
	tail->next = NULL;

	printf("##DEBUG## list initialize success\n");
} 


void add_list(int input)
{
	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));

	new_node->value = input;
	new_node->next = head->next;
	head->next = new_node;

	printf("##DEBUG## %d is added in list\n", input);
}

void print_all_list(void)
{
	struct node *p;
	for (p = head ; p != NULL ; p = p->next) {
		printf("[%d] -> ", p->value);
	}
	printf("\n");
}

void remove_list(int input)
{
	struct node *p,*q;

	printf("##DEBUG## Remove %d\n", input);

	for (p = head , q = head ; p != NULL ; p = p->next) {
	
		if(input == p->value) {
			printf("##DEBUG## We got %d\n", input);
			break;
		}
		q = p;
		
	}

	q->next = p->next;
	free(p);


}

void add_list_with_sort(int input)
{
	struct node *p,*q;
	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->value = input;

	printf("##DEBUG## Add with sort %d\n", input);

	for (p = head , q = head ; p != NULL ; q = p,  p = p->next) {
		
		if((q->value < input) && (input < p->value)) {
			new_node->next = q->next;
			q->next = new_node;
			return;
		} else if (input == p->value) {
			printf("##DEBUG## Try to add smae value\n");
			free(new_node);
			return;
		}
	}
}

int main()
{
	list_init();
	
	
	add_list_with_sort(10);
	add_list_with_sort(20);
	add_list_with_sort(30);
	add_list_with_sort(40);
	add_list_with_sort(50);
	

	print_all_list();
	
	remove_list(40);

	print_all_list();

	return 0;
}



