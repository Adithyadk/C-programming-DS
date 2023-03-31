#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct stack
{
    int top;
    int size;
    float *A;
}stack;

void push(stack *st,float data)
{
    if(st->top==st->size-1)
    {
        printf("Reallocating\n");
        st->A=realloc(st->A,2*sizeof(int)*st->size);
    }
    else
      st->A[++st->top]=data;
}

int pop(stack *st)
{
    return st->A[(st->top)--];
}

int prec(char a) //check if its operator or not
{
    if(a=='^' || a=='$') return 3;
    
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    else return 0;
}

float operate(float op1, float op2, char a){
    switch(a){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '^': 
        case '$': return pow(op1,op2);
    }
}

void posteval(char exp[],int size)
{
    stack *st=malloc(sizeof(struct stack));
    st->top=-1;
    st->size=size;
    st->A=malloc(sizeof(int)*st->size);
    int i;
    float d,op1,op2;
    char a;
    for(i=0;i<size;i++)
    {
        a=exp[i];
        if(prec(a)==0)
        {
            d=a-'0';
            push(st,d);
        }
        else if(prec(a)>0)
        {
            op1=pop(st);
            op2=pop(st);
            push(st,operate(op2,op1,a));
        }
    }
    printf("Postfix Evaluation is %f\n",st->A[st->top]);
}

void prefeval(char exp[],int size)
{
    stack *st=malloc(sizeof(struct stack));
    st->top=-1;
    st->size=size;
    st->A=malloc(sizeof(int)*st->size);
    int i;
    float d,op1,op2;
    char a;
    for(i=size-1;i>=0;i--)
    {
        a=exp[i];
        if(prec(a)==0)
        {
            d=a-'0';
            push(st,d);
        }
        else if(prec(a)>0)
        {
            op1=pop(st);
            op2=pop(st);
            push(st,operate(op1,op2,a));
        }
    }
    printf("Prefix Evaluation is %f\n",st->A[st->top]);
}
void main()
{
    char exp[50];
    int ch;
    while(1){
        printf("Enter 1.Postfix Evaluation 2.Prefix Evaluation 3.Exit\n");
        scanf("%d", &ch);
        switch(ch){ 

            case 1:
            printf("Enter exp\n");
            scanf("%s", exp);
            posteval(exp, strlen(exp));
            break;

            case 2:
            printf("Enter exp\n");
            scanf("%s", exp);
            prefeval(exp, strlen(exp));
            break;

            case 3:
            exit(0); 

            default:
            printf("Invalid choice\n");

        }
    }
}
