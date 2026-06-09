#include<iostream>
using namespace std;
int main()
{
	int i,n,arr[5];
	for(i=1;i<=5;i++)
	{
	cout<<"Enter number:";
	cin>>arr[i];
}
    cout<<"Arry in actual order:  ";
    for(i=1;i<=5;i++)
	cout<<arr[i]<<"\t";
    cout<<"\nnum in reverse ORDER:";
    for(i=5;i>=1;i--)
    cout<<"\t"<<arr[i];
}
