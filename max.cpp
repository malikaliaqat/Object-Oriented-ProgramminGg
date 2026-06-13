#include<iostream>
using namespace std;
int main()
{
	int a,b,max,c;
	cout<<"Enter a number to find maximum number";
	cin>>a;
	cout<<"Enter a number to find maximum number";
	cin>>b;
	cout<<"Enter a number to find maximum number";
	cin>>c;
	max=a;
	if(max<b)
	max=b;
	if(max<c)
	max=c;
		cout<<" maximum number is "<<max;
}
