#include<stdlib.h>
#include <stdio.h>
typedef struct Node node;

void insert_begin();
void display();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void deleteList();
int getCount();
void search_item();


struct node
{
        int data;
        struct node *next;
};
struct node *start=NULL;
node *head =NULL;
int main()
{
    int key;
        int choice;
        int value;
        while(1){


                printf(" 1.Display\n");
                printf(" 2.Insert first\n");
                printf(" 3.Insert last\n");
                printf(" 4.Insert at position\n");
                printf(" 5.Delete first\n");
                printf(" 6.Delete last\n");
                printf(" 7.Delete at position\n");
                printf(" 8.Delete all\n");
                printf(" 9.Size of Linked List\n");
                printf(" 10.Search \n");
                printf(" 11.Exit \n");
                printf(" Enter your choice:\t");

                scanf("%d",&choice);

                switch(choice)
                {

                        case 1:
                                        display();
                                        break;
                        case 2:
                                        insert_begin();
                                        break;
                        case 3:
                                        insert_end();
                                        break;
                        case 4:
                                        insert_pos();
                                        break;
                        case 5:
                                        delete_begin();
                                        break;
                        case 6:
                                        delete_end();
                                        break;
                        case 7:
                                        delete_pos();
                                        break;

                        case 8:         deleteList();
                                        break;


                        case 9:
                                        getCount(head);
                                        break;
                        case 10:
                                        printf("Enter the value you want to search: ");
                                        scanf("%d",&value);
                                        search_item();
                                        break;
                        case 11:
                                        exit(0);
                                        break;


                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}


void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->data );
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space\n");
                return;
        }
        printf("\nPush at beginning :\t" );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->data );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->data) ;

        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nThe deleted element is :%d\t",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("\nThe deleted element is:%d\t",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is:%d\t",ptr->data);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\t",ptr->data  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->data );
                        free(ptr);
                }
        }
}
void deleteList()
{
    struct node *temp,*head=NULL;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }

    printf("SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n");
}
int getCount(struct node* head)
{

    if (head == NULL)
        return 0;


    return 1 + getCount(head->next);
}
void search_item(int value)
{
    struct node *searchnode = head;
    int flag = 0;

    while(searchnode!=NULL)
    {
        if(searchnode->data==value)
        {
            printf("%d is present in this list. Memory address is %d\n", value, searchnode);
            flag = 1;
            break;
        }
        else
            searchnode = searchnode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}
