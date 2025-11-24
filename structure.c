#include<stdio.h>
#include<stdlib.h>
struct student
{
	int rno;
	char name[30];
	float avg;
};
int main()
{
	struct student *s1;
	int i,n;
	scanf("%d",&n);
	s1=(struct student*)malloc(n*sizeof(struct student));
	for(i=0;i<n;i++)
	{
		printf("Enter roll no,name and average marks\n");
		scanf("%d%s%f",&(s1+i)-> rno,&(s1+i)-> name,&(s1+i)->avg);
	}
	printf("Roll no,name\t average\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t %s\t %f\n",(s1+i)->rno,(s1+i)->name,(s1+i)->avg);
	}
	return 0;
}
