#include<iostream>
using namespace std;
int main()
{
	int i,j,num,n,tem,arr[5];
	for(i=0;i<5;i++)
	{
		cout<<"Enter number : ";
		cin>>arr[i];
	}
		cout<<"\nNumber in Order Form:\n ";
   	for(i=0;i<5;i++)
   	{
   		cout<<arr[i]<<"  ";
   	}
	   	for(i=0;i<5;i++)
	   		for(j=0;j<4;j++)
	   		if(arr[j]>arr[j+1])
	   		   {
	   			tem=arr[j+1];
	   			arr[j+1]=arr[j];
	   			arr[j]=tem;
			   }
			   	cout<<"\nIN sorted arry:\n ";
					for(i=0;i<5;i++)   
					cout<<arr[i]<<"  ";
}
