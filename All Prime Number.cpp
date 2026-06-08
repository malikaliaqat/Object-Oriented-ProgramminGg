#include<iostream>
using namespace std;
int main()
{
	int n,a,b,p,sum=0;
	p=1;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	for(n=0;n<10;n++)
	{
		cout<<arr[n]<<endl;
	}
	for(a=2;a<10;a++)
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
	cout<<"->  "<<a<<"\tis  prime\n";
	sum++;
}
	p=1;
}
cout<<"total prime num is "<<sum;
cout<<"\nThis num is Less Then 10";
}
