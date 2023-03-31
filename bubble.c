#include<stdio.h>
void bubblesort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
void main()
{
  int a[10],n,i;
  printf("enter the size of the array\n");
  scanf("%d",&n);
  printf("enter the array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  bubblesort(a,n);
  
  printf("the  sorted array is\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  } 
}