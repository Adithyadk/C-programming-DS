#include <stdio.h>
#include <stdlib.h>
int n;

void push(int *c,int val)
{
    c = (int*)realloc(c,(n+1)*sizeof(int));
    /*if (c == NULL)
    {
        free(c);
        exit(0);
    }*/
    *(c+n) = val;
    n++;
}
/*
int pop(int *c)
{
    int *c;
    int x = stack[(*c)-1];
    stack[(*c)-1] = NULL;
    int *r;
    printf("%d\n", *c);
    r = realloc(stack, ((*c)-1)*sizeof(int));
    if(r == NULL){
        free(stack);
        exit(0);
    }
    n--;
    stack = r;
    return x;
}*/
void display(int *c)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",*(c+i));
    }
}
void main()
{
    int data,ch;
    int *stack;
while(1){
      printf("\n---- MENU ----\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d",&data);
         stack = malloc(sizeof(int));
		 push(stack,data);
		 break;
	 //case 2: pop(stack);
		// break;
	 case 3: display(stack);
		 break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Try again!!!");
      }
   }
}