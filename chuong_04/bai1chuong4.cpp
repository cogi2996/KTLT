#include<iostream>
using namespace std;

int Min(int *a,int n)
{
	if(n == 1)
		return a[0];
	else
	{
		if(a[n-1]<Min(a,n-1))
			return a[n-1];
		else
			return Min(a,n-1);
	}
}

int main()
{
int n,a[100];
cin>>n;
for(int i = 0;i<n;i++)
{
	cin>>a[i];
}

cout<<Min(a,n);

}

