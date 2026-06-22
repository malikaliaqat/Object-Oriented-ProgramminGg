#include<iostream>
using namespace std;
int main()
{
	int a,n,b,c;
	int p=1;
	cout<<"Enter Ending Number:";
	cin>>n;
	for(a=2;a<n;a++)
	{
	for(b=2;b<a;b++)
	{
		if(a%b==0)
		{
		p=0;
		break;
	}
	}
    if(p==1)
   {
       cout<<a<<"is prime";
	}	
	p=1;
 }
}
