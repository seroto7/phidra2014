struct node{
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
	tail->value = -1;

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
	
	printf("##DEBUG## show all list member\n");

	for (p = head ; p != NULL ; p = p->next ) {
		printf("[%d]", p->value);
	}
	printf("\n");
}

void remove_list(int input)
{
	struct node *p;
	struct node *q;
		
	printf("##DEBUG## Remove %d\n", input);

	for (p = head, q = head ; p != NULL ; p = p->next ) {
		if (input == p->value) {
			printf("##DEBUG## we got %d\n", input);
			break;
		}
		q = p;
	}

	q->next = p->next;
	free(p);
	
}

void add_list_with_sort(int input)
{
	

	struct node *p;
	struct node *q;
	struct node *new_node;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->value = input	

	printf("##DEBUG## Add with sort %d\n", input);

	for (p = head, q = head ; p != NULL ;q = p , p = p->next ) {
		if (input > p->value)
		
	}		
	
}

int main()
{
	list_init();
	
	add_list(10);
	add_list(20);
	add_list(30);
	add_list(40);
	add_list(50);
	remove_list(20);
	print_all_list();
	
	
}

	
