#include<iostream>
using namespace std;

void nhap(int &n,int &x,int *a)
{
	cin>>n;
	cin>>x;
	for(int i = 0 ;i<n;i++)
	{
		cin>>a[i];
	}
}

int binarySearch(int *a,int n,int x,int left,int right)
{	
	
		
	if(a[(left+right)/2] == x)
		return 1;
	if(left == right)
		return 0;
	if(x>a[(left+right)/2])
		return binarySearch(a,n,x,(left+right)/2+1,right);
	else
		return binarySearch(a,n,x,left,(left+right)/2-1);		
		
}

int main()
{
	int n,x;
	int a[100];
	nhap(n,x,a);
	if(binarySearch(a,n,x,0,n-1) == 1) 
		cout<<"ton tai x trong mang a";
	else
		cout<<"Khong ton tai x trong  mang a";
	return 0;
}
