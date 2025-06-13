#include<stdio.h>
int main()
{
	int size,a[5],left=0,i,target;
	printf("enter size:");
	scanf("%d",&size);
	a[size];
	printf("enter elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	int mid;
	int right=size-1;
	printf("enter target value");
	scanf("%d",&target);
	
	while(left<=right)
	{
	mid=left+(right-left)/2;
	if(a[mid]==target)
	{
		printf("element found at index:%d\n",mid);
	}
		if(a[left]<=a[mid])
		{
			if(target<a[mid]&&target>=a[left])
			{
				right=mid-1;
			}
			else
			{
				left=mid+1;
			}
		}
		else
		{
			if(target>a[mid]&&target<=a[right])
			{
				left=mid+1;
			}
			else
			{
				right=mid-1;
			}
		}
	}
	printf("target not found");
	return 0;
}
