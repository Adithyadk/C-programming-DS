#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *createNodeList(int n)
{
    struct node *ptr;
    int data, i;
    struct node *head= malloc(sizeof(struct node));

    if(head == NULL) 
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        printf(" Input data for node 1 : ");
        scanf("%d", &data);
        head->data = data;      
        head->link = NULL; 
        ptr = head;

        for(i=2; i<=n; i++)
        {
            struct node *current = malloc(sizeof(struct node));
            if(current == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &data);
 
                current->data = data;      
                current->link = NULL; 
                ptr->link = current; 
                ptr = ptr->link;
            }
        }
    }
    return head;
}

struct node *display(struct node *head)
{

    if (head == NULL)
    {
        printf("Linked list empty\n");
    }
    struct node *ptr = head;
    printf("Linked list is--> ");
    while (ptr!= NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->link;
    }
    return head;
}
 
void sort(struct node *head ) 
{  
        struct node *ptr = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) 
        {  
            return;  
        }  
        else {  
            while(ptr != NULL) 
            {  
             
                index = ptr->link;  
                  
                while(index != NULL)
                {  
                    if(ptr->data > index->data) 
                    {  
                        temp = ptr->data;  
                        ptr->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->link;  
                }  
                ptr = ptr->link;  
            }      
        } 
        display(head);
}  

struct node *delete_key(struct node *head)
{
    int key;
    struct node *prev;
    struct node *ptr=head;
    printf("Enter the key to be Deleted\n");
    scanf("%d",&key);  
    if (ptr != NULL && ptr->data == key) 
    {
        head = ptr->link;
        free(ptr);
        ptr=NULL;
        return head;
    }
  
    
    while (ptr != NULL && ptr->data != key) 
    {
        prev = ptr;
        ptr = ptr->link;
    }
  
    if (ptr == NULL)
    {
        printf("%d not present in SLL\n",key);
        return head;
    }
    prev->link = ptr->link;
  
    free(ptr);
    ptr=NULL;
    return head;
}


void main()
{
    struct node *head = NULL;
    int n,ch;
    while (1)
    {
        printf("\n1.Read\n2.Display\n3.Sort\n4.Delete By Key\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: 
            printf("Input the number of nodes : ");
            scanf("%d", &n);
            head = createNodeList(n);
            break;
        case 2:
            display(head);
            break;
        case 3:
            sort(head);
            break;
        case 4:
            head=delete_key(head);
            display(head);
            break;
        default:exit(0);
        }
    }
}