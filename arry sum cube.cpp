#include<iostream>
#include<conio.h>
using namespace std;
int main ()
{
    int i;
    int num[10], squares[10], cubes[10], sums[10], t_sum=0;
    for(i=0;i<10;i++)
    {
        num[i]=i;
        squares[i]=i*i;
        cubes[i]=i*i*i;
        sums[i]=num[i]+squares[i]+cubes[i];
        t_sum= t_sum + sums[i];
    }
    cout<<"Numbers\tSquares\tCubes\tsums"<<endl;
    for(i=0;i<10;i++)
    {
        cout<<num[i]<<"\t"<<squares[i]<<"\t"<<cubes[i]<<"\t"<<sums[i]<<endl;
    }
    cout<<"Grand total: "<<t_sum;
}

