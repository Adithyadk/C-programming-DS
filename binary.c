#include<stdio.h>
void binarysearch(int a[],int n,int key)
{
    int low=0,high=n-1,mid,k=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        
            if (a[mid]==key)
            {
                k=1;
                break;
            }
            else if(a[mid]>key)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            
    }
    
    if (k==1)
    {
    printf("%d is found in the location %d\n",key,(mid+1));
    }
    else 
    {
    printf("key element is not found in the array");
    }
}
void main()
{
  int a[10],n,key,i;
  printf("enter the size of the array\n");
  scanf("%d",&n);
  printf("enter the array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("enter the kay value to be searched\n");
  scanf("%d",&key);
  binarysearch(a,n,key); 
}