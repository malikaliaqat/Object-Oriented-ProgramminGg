#include<iostream>
using namespace std;
int main()
{
	int g,grade,total_grade;
	float average;
	grade=1;
		total_grade=0;
	while(grade<=10)
	{
		cout<<"Enter Your Grade :";
		cin>>g;
		total_grade=total_grade+g;
		g=g+1;
		grade=grade+1;
	}
		average=total_grade/10;
		cout<<"your Total Grade is :"<<total_grade;
		cout<<"\nAverage is :"<<average;
	return 0;
}
