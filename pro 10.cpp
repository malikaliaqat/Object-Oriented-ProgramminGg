#include<iostream>
using namespace std;
main()
{
	int x,n,sum;
	cout<<"Enter number";
	cin>>x;
	sum=0;
	for(n=1;n<=x;n=n+1)
	sum=sum+(n*x^n);
	cout<<sum;
}
