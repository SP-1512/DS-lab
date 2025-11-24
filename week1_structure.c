#include<stdio.h>
struct student 
{
	char name[30];
	int m1,m2,m3;
	float total,avg;
};
int main()
{
	int n,i;
	printf("Enter no students:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("Enter name,3 subject marks of students %d:",i+1);
		scanf("%s %d %d %d",&s[i].name,&s[i].m1,&s[i].m2,&s[i].m3);
	}
	for(i=0;i<n;i++)
	{
		s[i].total=s[i].m1+s[i].m2+s[i].m3;
		s[i].avg=s[i].total/3.0;
		printf("Total : %.2f and average : %.2f of student %d\n",s[i].total,s[i].avg,i+1);
	}		
	return 0;
}
