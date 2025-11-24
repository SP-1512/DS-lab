#include<iostream>
using namespace std;
class student
{
	private:
		int rno;
		char name[30];
		float avg;
		public:
			void get()
			{
				cout<<"enter rno:";
				cin>>rno;
				cout<<"enter name:";
				cin>>name;
				cout<<"enter avg:";
				cin>>avg;
			}
			void show()
			{
				cout<<"rno is:"<<rno<<endl;
				cout<<"name is:"<<name<<endl;
				cout<<"avg is:"<<avg<<endl;
			}
};

int main()
{
	student s1;
	s1.get();
	s1.show();
	return 0;
}		

