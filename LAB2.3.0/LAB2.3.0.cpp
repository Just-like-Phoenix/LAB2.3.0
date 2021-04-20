#include<stdlib.h>
#include<stdio.h>

struct node
{
    int information;
    struct node* link;
};

struct node* create_list(struct node* starting_node);
void display(struct node* starting_node);
struct node* addatbeginning(struct node* starting_node, int data);
struct node* addatend(struct node* starting_node, int data);

int main()
{
    struct node* starting_node = NULL;
    int option, data;
    while (1)
    {
        printf("1. Create a new linked list");
        printf("\n2. Display the elements of the linked list");
        printf("\n3. Add an element to beginning");
        printf("\n4. Add an element at the end");
        printf("\n5. Quit");
        printf("\nEnter Your Choice:\t");
        scanf_s("%d", &option);
        switch (option)
        {
        case 1: starting_node = create_list(starting_node);
            break;
        case 2: display(starting_node);
            break;
        case 3: printf("\nEnter the element to add at beginning:\t");
            scanf_s("%d", &data);
            starting_node = addatbeginning(starting_node, data);
            break;
        case 4: printf("\nEnter the element to insert at the end:\t");
            scanf_s("%d", &data);
            starting_node = addatend(starting_node, data);
            break;
        case 5: exit(1);
        default: printf("\nWrong Input. Enter a proper Input\n");
        }
    }
    return 0;
}

struct node* create_list(struct node* starting_node)
{
    int count, limit, data;
    printf("\nEnter the number of nodes:\t");
    scanf_s("%d", &limit);
    starting_node = NULL;
    if (limit == 0)
    {
        return starting_node;
    }
    printf("\nEnter the element to insert:\t");
    scanf_s("%d", &data);
    starting_node = addatbeginning(starting_node, data);
    for (count = 2; count <= limit; count++)
    {
        printf("\nEnter the element to insert:\t");
        scanf_s("%d", &data);
        starting_node = addatend(starting_node, data);
    }
    return starting_node;
}

void display(struct node* starting_node)
{
    struct node* new_node;
    if (starting_node == NULL)
    {
        printf("\nLinked list is empty");
        return;
    }
    new_node = starting_node;
    printf("\nLinked list elements:\n\n");
    while (new_node != NULL)
    {
        printf("%d\t", new_node->information);
        new_node = new_node->link;
    }
    printf("\n\n");
}

struct node* addatend(struct node* starting_node, int data)
{
    struct node* new_node, * temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->information = data;
    new_node = starting_node;
    while (new_node->link != NULL)
    {
        new_node = new_node->link;
    }
    new_node->link = temp;
    temp->link = NULL;
    return starting_node;
}

struct node* addatbeginning(struct node* starting_node, int data)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->information = data;
    temp->link = starting_node;
    starting_node = temp;
    return starting_node;
}