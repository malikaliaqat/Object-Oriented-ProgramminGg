#include<iostream>
using namespace std;
int main()
{
	int i,n,Days_per,arr[12]={30,28,31,30,31,30,31,31,30,31,30,31};
	cout<<"Enter  date ";
	cin>>n;
	for(i=1;i<=12;i++)
	cout<<"Enter month";
	cin>>arr[i];
	Days_per=n*arr[i];
	cout<<"today all days:"<<Days_per;
}
