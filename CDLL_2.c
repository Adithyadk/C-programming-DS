
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *HedNo;
struct Node *read(struct Node *head)
{
    struct Node *p, *q;
    printf("Enter the data of nodes\n");
    scanf("%d", &head->data);
    q = head;
    for (int i = 0; i < HedNo->data - 1; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &p->data);
        p->next = NULL;
        p->prev = q;
        q->next = p;
        q = q->next;
    }
    q->next = HedNo;
    HedNo->prev = q;
    return HedNo;
}
void disp(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Elements(Forward Traversal):\t");
        while (ptr->next != head->prev)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
        printf("Elements(Backward Traversal):\t");
        while (ptr != head->prev)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->prev;
        }
        printf("\n");
    }
}
struct Node *Insert_Front(struct Node *head)
{
    HedNo->data++;
    struct Node *p, *q = head;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->next = head;
    head->prev = p;
    HedNo->next = p;
    p->prev = HedNo;
    printf("Enter the Data\n");
    scanf("%d", &p->data);
    head = p;
    return head;
}
struct Node *Insert_Rear(struct Node *head)
{
    HedNo->data++;
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data\n");
    scanf("%d", &ptr->data);
    ptr->next = HedNo;
    ptr->prev = HedNo->prev;
    HedNo->prev->next = ptr;
    HedNo->prev = ptr;
    return head;
}
struct Node *Insert_Pos(struct Node *head)
{
    int Pos;
    printf("Enter the Pos\n");
    scanf("%d", &Pos);
    if (Pos == 1)
    {
        head = Insert_Front(head);
    }
    else
    {
        HedNo->data++;
        struct Node *ptr, *p = head;
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data\n");
        scanf("%d", &ptr->data);
        for (int i = 0; i < Pos - 2; i++)
        {
            p = p->next;
        }
        ptr->next = p->next;
        ptr->prev = p;
        p->next->prev = ptr;
        p->next = ptr;
    }
    return head;
}

struct Node *Delete_Front(struct Node *head)
{
    if (HedNo->data == 0)
    {
        printf("Empty List\n");
    }
    else
    {
        HedNo->data--;
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        HedNo->next = head;
        head->prev = HedNo;
    }
    return head;
}

struct Node *Delete_Rear(struct Node *head)
{
    if (HedNo->data == 0)
    {
        printf("Empty List\n");
    }
    else
    {
        HedNo->data--;
        struct Node *p = HedNo->prev;
        p->prev->next = HedNo;
        HedNo->prev = p->prev;
        free(p);
    }
    return head;
}

struct Node *Delete_Pos(struct Node *head)
{
    int Pos;
    if (HedNo->data == 0)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter the Pos to be deleted\n");
        scanf("%d", &Pos);
        if (Pos == 1)
        {
            head = Delete_Front(head);
        }
        else
        {
            HedNo->data--;
            struct Node *p = head;
            struct Node *q = head->next;
            for (int i = 0; i < Pos - 2; i++)
            {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
            q->next->prev = p;
            free(q);
        }
    }
    return head;
}

struct Node *Delete_key(struct Node *head)
{
    int val;
    if (HedNo->data == 0)
    {
        printf("Empty List");
    }
    else
    {
        printf("Enter the Value(key) to be deleted\n");
        scanf("%d", &val);
        struct Node *p = head;
        struct Node *q = head->next;
        if (head->data == val)
        {
            head = Delete_Front(head);
        }
        else
        {
            while (q->data != val && q->next != head)
            {
                p = p->next;
                q = q->next;
            }
            if (q->data == val)
            {
                HedNo->data--;
                p->next = q->next;
                q->next->prev = p;
                free(q);
            }
            else
            {
                printf("Val not found\n");
            }
        }
    }
    return head;
}

void Search(struct Node *head)
{
    int ele, index = 0;
    printf("Enter the Element to be searched\n");
    scanf("%d", &ele);
    struct Node *ptr = head;
    do
    {
        ptr = ptr->next;
        index++;
    } while (ptr->data != ele && ptr != head);
    if (ptr->data == ele)
    {
        printf("Element found at Position %d\n", index + 1);
    }
    else
    {
        printf("Element Not Found\n");
    }
}

struct Node *Sorting(struct Node *head)
{
    int a;
    struct Node *q = head;
    struct Node *p;
    do
    {
        for (p = q->next; p != head; p = p->next)
        {
            if (p->data < q->data)
            {
                a = q->data;
                q->data = p->data;
                p->data = a;
            }
        }
        q = q->next;
    } while (q != head);
    return head;
}

struct Node *Reverse(struct Node *head)
{
    struct Node *q = head;
    head = head->prev->prev;
    struct Node *p = HedNo->next;
    HedNo->next = HedNo->prev;
    HedNo->prev = p;
    for (int i = 0; i < HedNo->data; i++)
    {
        p = q->prev;
        q->prev = q->next;
        q->next = p;
        q = q->prev;
    }
    return head;
}
struct Node *Copy()
{
    struct Node *nN=malloc(sizeof(struct Node));;
    struct Node *p, *q = nN;
    for (int i = 0; i < HedNo->data; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->next = NULL;
        p->prev = q;
        q->next = p;
        q = q->next;
    }
    q->next = nN;
    nN->prev = q;
    // Created Blocks |^
    //  Assigning Values
    struct Node *ptr = HedNo;
    p = nN;
    for (int i = 0; i <= HedNo->data; i++)
    {
        p->data = ptr->data;
        p = p->next;
        ptr = ptr->next;
    }
    return nN;
}
void Free()
{
    int x = HedNo->data+1;
    struct Node *q = HedNo, *p = HedNo->next;
    while (x)
    {
        free(q);
        q = p;
        p = p->next;
        x--;
    }
}

int main()
{
    int ch;
    struct Node *head;
    HedNo = (struct Node *)malloc(sizeof(struct Node));
    head = (struct Node *)malloc(sizeof(struct Node));
    HedNo->next = head;
    HedNo->prev = HedNo;
    head->prev = HedNo;
    head->next = NULL;
    printf("Enter No of Nodes Required\n");
    scanf("%d", &HedNo->data);
    while (1 < 2)
    {
        puts("Choices Available\n1.Read\t2.Display\n3.Insert(Front)\t4.Insert(Rear)\t5.Insert(Pos)\n6.Delete(Front)\t7.Delete(Rear)\t8.Delete(Pos)\t9.Delete(key)");
        puts("10.Search(key)\t11.Sorting\t12.Reverse\t13.Create(Copy)\n14.Free");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            read(head);
            break;
        case 2:
            disp(head);
            break;
        case 3:
            head = Insert_Front(head);
            break;
        case 4:
            head = Insert_Rear(head);
            break;
        case 5:
            head = Insert_Pos(head);
            break;
        case 6:
            head = Delete_Front(head);
            break;
        case 7:
            head = Delete_Rear(head);
            break;
        case 8:
            head = Delete_Pos(head);
            break;
        case 9:
            head = Delete_key(head);
            break;
        case 10:
            Search(head);
            break;
        case 11:
            head = Sorting(head);
            break;
        case 12:
            head = Reverse(head);
            break;
        case 13:
            disp(Copy()->next);
            break;
        case 14:
            Free(head);
            head = NULL;
            HedNo = NULL;
            break;
        default:
            printf("Exiting\n");
            exit(0);
            break;
        }
    }
    return 0;
}