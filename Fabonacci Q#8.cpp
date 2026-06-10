#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,n;
	cout<<"Enter a num";
	cin>>n;
	a=0;
	b=1;
	cout<<a<<"\t"<<b;
	c=2;
	while(c<n)
	{
		d=a+b;
		cout<<"\t"<<d;
		a=b;
		b=d;
		c++;
	}
}
