#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j,a[i][j];
	cout<<"Enter Number of Row  ";
	cin>>n;
	cout<<"Enter NUmber Of Columns  ";
	cin>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
	cout<<a[i][j]<<"  ";
   cout<<"\n";
}
}
