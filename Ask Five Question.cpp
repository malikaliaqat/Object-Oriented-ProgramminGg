#include<iostream>
using namespace std;
int main()
{
		cout<<"You Have Five Questions to ask user ";
		char ques[5];
	int a=0;

	char ans[5];
	ques[0]='k';
	cout<<"\n-->  Fisrt Question Is:\nWrite Fisrt Letter of My Name : ";
	cin>>ans[0];
	if(ques[0]==ans[0])
	{
		a=a+1;
	}
	if(a==1)
	{
		cout<<"\nExellent";
	}
	else
	{
		cout<<"Sorry";
	}
	ques[1]='m';
	cout<<"\n-->  second Question Is:\nWrite Fisrt Letter of Bestie Name : ";
	cin>>ans[1];
	if(ques[1]==ans[1])
	{
		a=a+1;
	}
	if(a==2)
	{
		cout<<"\nVery Good";
	}
	else
	{
		cout<<"Sorry";
	}
	ques[2]= 'k';
	cout<<"--> \n Third Question Is:\nWrite Your favourit letter : ";
	cin>>ans[2];
	if(ques[2]==ans[2])
	{
		a=a+1;
	}
	if(a==3)
	{
		cout<<"Fair(Good)";
	}
	else
	{
		cout<<"Sorry";
	}
}
