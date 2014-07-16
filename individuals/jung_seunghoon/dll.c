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
        tail->next = NULL;
        tail->prev = head;

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
        struct node *p, *q;

        printf("##DEBUG## Remve %d\n",input);
        for(p = head , q = head ; p != NULL ;q = p ,  p = p->next){
                if(input == p->value){
                        printf("##DEBUG## we got %d\n",input);
                        break;
                }
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
}

void add_list_with_sort(int input)
{
        struct node *p, *q;
        struct node *new_node;

        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->value = input;

        printf("##DEBUG## Add with sort %d\n", input);

        for(p = head , q = head ; p != NULL ; q = p , p = p->next) {
                if((q->value < input) && ( input < p->value)){
                        new_node->next = p->prev->next;
                        new_node->prev = p->prev;
                        p->prev->next = new_node;
                        p->prev = new_node;
                        return;
                } else if (input == p->value){
                        printf("##DEBUG## Try to add value\n");
                        free(new_node);
                        return;
                }
        }
}

int main()
{
        list_init();

        add_list_with_sort(10);
        add_list_with_sort(50);
        add_list_with_sort(30);
        add_list_with_sort(40);
        add_list_with_sort(20);

        print_all_list();

        remove_list(30);

        print_all_list();

        add_list_with_sort(49);

        print_all_list();

        return 0;
}
