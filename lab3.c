/*
-> Write a C program to implement Single linked lists for below operations
    Name of the functions : insertAtbeginS(struct node* head,int data),
    insertAtEndS(struct node* head,int data), deleteAtbeginS(struct node*head), 
    deleteAtEndS(struct node* head),printList(struct node* head)
    
    Input : -------
    Output :
    Intial Single linked list
    Linked list : NULL
    After Insertion three nodes at beginning
    Linked list : R -> G -> U -> NULL
    After Insertion two nodes at End
    Linked list : R -> G -> U -> K -> T -> NULL
    After Deleting two nodes at beginning
    Linked list : U -> K -> T -> NULL
    After Deleting two nodes at End
    Linked list : U -> NULL
*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    char data;
    struct node *next;
};

void printList(struct node *head)
{
    printf("\nLinked List : ");
    if(head==NULL)
    {
        printf("NULL");
    }
    else
    {
        struct node *temp = head;
        while(temp!=NULL)
        {
            printf("%c ->",temp->data);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }
}

struct node *insertAtBeginS(struct node *head,char val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
        return head;
    }
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *insertAtEndS(struct node *head,char val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
        return head;
    }
    struct node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node *deleteAtBeginS(struct node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *deleteAtEndS(struct node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

void main()
{
    struct node *head = NULL;

    printf("Initial Single list");
    printList(head);

    head = insertAtBeginS(head,'U');
    head = insertAtBeginS(head,'G');
    head = insertAtBeginS(head,'R');
    printf("\nAfter three nodes insert at beginning");
    printList(head);

    head = insertAtEndS(head,'K');
    head = insertAtEndS(head,'T');
    printf("\nAfter two nodes insert at end");
    printList(head);

    head = deleteAtBeginS(head);
    head = deleteAtBeginS(head);
    printf("\nAfter two nodes deleted at beginning");
    printList(head);

    head = deleteAtEndS(head);
    head = deleteAtEndS(head);
    printf("\nAfter two nodes deleted at end");
    printList(head);
}