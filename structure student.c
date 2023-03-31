#include<stdio.h>
struct student
{
    char name[40];
    int roll;
    float marks;
}s[3];
void main()
{
    int i;
    printf("enter information of the student:\n");
    for(i=0;i<3;i++)
    {
    s[i].roll=i+1;
    printf("\n for roll number %d,\n",s[i].roll);
    printf("enter name:\n");
    scanf("%s",s[i].name);
    printf("enter the marks:");
    scanf("%f",&s[i].marks);
    }
    printf(" \n displaying information:\n");
    for(i=0;i<3;i++)
    {
    printf("\n roll number:%d \n",(i+1));
    printf("name: ");
    puts(s[i].name);
    printf("marks: %f",s[i].marks);
    printf("\n \n");
    }
}