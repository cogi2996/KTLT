#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a;
	getline(cin,a);
	int diem  =0;
	for(int i =0;i<a.length();i++)
	{
		if(a[i] == 'V')
			diem++;
	}
	cout<<diem;
	
}
