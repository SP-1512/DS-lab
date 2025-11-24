#include<stdio.h>
#include<string.h>
struct student
{
	int rno;
	char name[30];
	float avg;
}s1,s2;
int main()
{
	printf("Enter rno:");
	scanf("%d",&s2.rno);
	printf("Enter name:");
	scanf("%s",&s2.name);
	scanf("%f",&s2.avg);
	s1=s2;
	printf("The copied string is :\n");
	printf("Rol.No=%d",s1.rno);
	printf("\nName=%s",s1.name);
	printf("\navg=%.2f",s1.avg);
	return 0;
}
