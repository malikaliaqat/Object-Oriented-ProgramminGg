#include<iostream>
using namespace std;
int main()
{
	int k=0,khadi[5],a,sum=0;
	for(a=1;a<=5;a++)
	{
		cout<<" Enter an integer:";
		cin>>khadi[a];
			sum=sum+khadi[a];
			k++;
		}
	float ave;
	ave=sum/k;
	cout<<"sum of given integer is:"<<sum<<endl;
	cout<<"Average is:"<<ave;
}
