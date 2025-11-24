#include<stdio.h>
void quicksort(int[],int,int);
int  main()
{
		int a[100],n,i;
		printf("Enter n value:");
		scanf("%d",&n);
		printf("Enter %d values: ",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		quicksort(a,0,n-1);
		printf("\n sorted array is...");
		for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		return 0;
}
void quicksort(int a[],int left,int right)
{
	int pivot=left,t;
	if(left<right)
	{
		int i=left,j=right;
		while(i<j)
		{
			while(a[i]<=a[pivot] && i<=right)
			i++;
			while(a[j]>a[pivot])
			j--;
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		t=a[j];
		a[j]=a[pivot];
		a[pivot]=t;
		quicksort(a,left,j-1);
		quicksort(a,j+1,right);
	}
}
