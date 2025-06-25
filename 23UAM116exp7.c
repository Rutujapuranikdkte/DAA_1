#include<stdio.h>
int main()
{
	int size,i,a[5],tmp,j,amt,cnt,amt1;
	printf("enter amount:");
	scanf("%d",&amt);
	printf("enter size of array:");
	scanf("%d",&size);
	printf("enter elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("elements in descending order:");
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(a[i]<a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	for(i=0;i<size;i++)
	{
		printf("%d\n",a[i]);
	}
	 printf("\n");

    printf("Coins used: [");

    int first = 1; // for comma formatting
    for(i = 0; i < size; i++)
    {
        while(amt >= a[i])
        {
            amt -= a[i];
            cnt++;
            if(first)
            {
                printf("%d", a[i]);
                first = 0;
            }
            else
            {
                printf(", %d", a[i]);
            }
        }
    }

    printf("]\n");
    printf("Minimum coins required: %d\n", cnt);

    return 0;
}
