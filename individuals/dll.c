
#include <stdio.h>
#include <stdlib.h>

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
        tail->prev = head;
	tail->next = NULL;

        printf("##DEBUG## list initialize success\n");
}

void add_list(int input)
{
        struct node *new_node;

        new_node = (struct node *)malloc(sizeof(struct node));

        new_node->value = input;

	new_node->next = head->next;
	new_node->prev = head;
	head->next->prev = new_node;
	head->next = new_node;	

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
	struct node *p;
	
	printf("##DEBUG## Remve %d\n",input);
        for(p = head ; p != NULL ; p = p->next) {
                if(input == p->value){
                        printf("##DEBUG## we got %d\n",input);
                        break;
                }
        }
	p->next->prev = head;
	head->next = p->next;

}

void add_list_with_sort(int input)
{
        struct node *p;
        struct node *new_node;

        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->value = input;

        printf("##DEBUG## Add with sort %d\n", input);

        /* need to change */
 	for(p = head ; p != NULL ; p = p->next) {
                if( input > p->value){
			new_node->next = p->next;                       
			new_node->prev = p;
			p->next->prev = new_node;                        
			p->next = new_node;
                        return;
                } else{
                        printf("##DEBUG## Try to add value\n");	
                        free(new_node);
                        return;
                }
        }
}

int main()
{
        list_init();

	add_list(30);
	print_all_list();

        remove_list(30);
        print_all_list();

        add_list_with_sort(10);
        add_list_with_sort(40);
        add_list_with_sort(30);
        add_list_with_sort(50);
        add_list_with_sort(20);
        print_all_list();
	
        return 0;
}
                                            
