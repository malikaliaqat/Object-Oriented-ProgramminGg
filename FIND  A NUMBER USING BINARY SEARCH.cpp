#include<iostream>
using namespace std;
int main()
{
	int i,j,end=5,start=0,loc=-1;
	int arr[5]={33,44,55,66,77};
	cout<<"Enter a number TO FIND:\n";
	cin>>i;
	while(start<=end)
	{
		int mid=(start+mid)/2;
		if(arr[mid]==i)
		{
			loc=mid;
			break;
		}
		else if(arr[mid]<i)
			start=mid+1;
		else
			end=mid-1;
	}
	if(loc==-1)
	cout<<i<<"is not found";
	else
	cout<<i<<"is found"<<loc;
}
