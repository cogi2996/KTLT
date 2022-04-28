#include<iostream>
using namespace std;

void hanoi(int n,string nguon, string dich,string tam)
{
	if(n > 0)
	{
		hanoi(n-1,nguon,tam,dich);
		cout<<"chuyen "<<n<<" dia tu cot "<<nguon<<" sang cot "<<dich<<endl;
		hanoi(n-1,tam,dich,nguon);
	}
}

int main()
{
	int n;
	cin>>n;
	hanoi(n,"nguon","dich","tam");
}
