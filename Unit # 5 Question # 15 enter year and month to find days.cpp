#include<iostream>
using namespace std;
int main()
{
	int y,m;
	cout<<"Enter year  :";
	cin>>y;
	cout<<"Enter Month  : ";
	cin>>m;
     if(m==1)
	cout<<"January   "<<y<<"  has 31 days";
	else if(m==2)
	{
	if(4%y!=0)
	cout<<"febrary   "<<y<<"  has 28 days";
	else
	cout<<"febrary   "<<y<<"  has 29 days";
    }
	else if(m==3)
	cout<<"March    "<<y<<"  has 31 days";
	else if(m==4)
	cout<<"April   "<<y<<"  has 30 days";
	else if(m==5)
	cout<<"May  "<<y<<" has 31 days";
	else if(m==6)
	cout<<"June "<<y<<"  has 30 days";
	else if(m==7)
	cout<<"July  "<<y<<"  has 31 days";
	else if(m==8)
	cout<<"August  "<<y<<" has 31 days";
	else if(m==9)
	cout<<"September  "<<y<<"  has 30 days";
	else if(m==10)
	cout<<"October  "<<y<<" has 31 days";
	else if(m==11)
	cout<<"November  "<<y<<"  has 30 days";
	else if(m==12)
	cout<<"December "<<y<<"  has 31 days";
	else
	cout<<"You enter only valid input 1 to 12 months";
}
