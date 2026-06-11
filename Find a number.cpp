#include<iostream>
using namespace std;
int main()
{
	int i,loc=-1,n;
	int arr[5]={22,4,7,2,9};
	cout<<"Enter num to find a num : ";
	cin>>n;
	for(i=0;i<5;i++)
	{
	if(arr[i]==n)
	loc=i;
    }
	if(loc==-1)
	cout<<"NOt found";
	else
	cout<<"\nfound moja : "<<loc;
}
