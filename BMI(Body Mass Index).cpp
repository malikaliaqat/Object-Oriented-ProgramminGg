#include<iostream>
using namespace std;
main()
{
	double Height,Weight,BMI;
	cout<<"\t\t\t\tBody Mass Index Calculater\n\n";
	cout<<"\t\tEnter your Heigth in inche :=";
	cin>>Height;
		cout<<"\n\tEnter our Weight in kg :=";
		cin>>Weight;
		Height=Height/39.0;
		BMI=Weight/(Height*Height);
			cout<<" \tYour BML(Body Mass Index) is := "<<BMI;
			if(BMI<18.5)
			cout<<"\tUnderweight(Need More Eat)";
			else if(BMI<=24.9)
				cout<<"\tNormal Weight(Moja)";
				else if(BMI<=29.9)
					cout<<"\tOverweigth(You Do Exercise)";
					else 
						cout<<"\tObese(!Far Away From Food)";
						return 0;
}
