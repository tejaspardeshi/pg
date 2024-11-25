// single linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*head;

void insertAt_start();
void insertAt_last();
void insertAt_random();
void delete_start();
void delete_last();
void delete_random();
void display();
void search();
void exit();

int main ()
{
    int choice =0;

    printf("\n************ Menu of Single linked list ***********\n");
    printf("\nChoose one option from the following list ...\n");
    printf("\n==================================================================\n");
    printf("\n1.Insert in start\n2.Insert at last\n3.Insert at any random location\n4.Delete from start\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");

    while(choice != 9)
    {
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);

      switch(choice)
      {

          case 1:insertAt_start();
                break;
          case 2:insertAt_last();
                break;
          case 3:insertAt_random();
                break;
          case 4:delete_start();
                break;
          case 5:delete_last();
                break;
          case 6:delete_random();
                break;
          case 7:search();
                break;
          case 8:display();
                break;
          case 9:exit(0);
                break;
          default:
            printf("Please enter valid choice..");
      }
    }
    return 0;
}

void insertAt_start()
{
    struct node*ptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node *));
    if(ptr==NULL)
    {
        printf("\n Cant inset, because memory allocation is fail");
    }
    else
    {
        printf("\nEnter a value to insert at start: \n");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\n%d node is inserted at start",item);
  }
}

void insertAt_last()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\n Cant inset, because memory allocation is fail");
    }
    else
    {
        printf("\nEnter value to insert at last: \n");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            head = ptr;
            printf("\n%d Node inserted at last",item);
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\n%d Node inserted at last",item);
        }
    }
}

void insertAt_random()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\n Cant inset, because memory allocation is fail");    }
    else
    {
        printf("\nEnter element value to insert randomly: ");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert: ");
        scanf("\n%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\n%d Node inserted at %d location",item,loc);
    }
}

void delete_start()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        printf("deleted value is:%d",ptr->data);
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}

void delete_last()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\nlist is empty");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        printf("\nDeleted Node from the last ...\n:%d",ptr->data);
        free(ptr);
    }
}

void delete_random()
{
    struct node *ptr,*ptr1;
    int loc,item,i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d",&loc);
    if(loc==1)
    {
        item=head->data;
        head=head->next;
    }
    ptr=head;
    for(i=0;i<loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1 ->next = ptr ->next;

    free(ptr);
    printf("\nnode is deleted from %d location",loc+1);
}

void search()
{
    struct node *ptr;
    int item,i=0,flag=0;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("item found at location %d ",i+1);
                flag=1;
            }
            else
            {
                flag=0;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==0)
        {
            printf("Item not found\n");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values present in linked list\n");
        while (ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr = ptr -> next;
        }
    }
}

