#include<bits/stdc++.h>
using namespace std;
int a[100]  ={0};
int n;

int timSo0DauTien()
{
	int k  = n-1;
	while(k>=0&&a[k]==1)
		k--;
	return k;
	
}

void xuat()
{
	for(int i =0;i<n;i++)
		cout<< a[i]<<" ";
	cout<<endl;
}

void sinhNhiPhan()
{

int k = n-1;
do{
	xuat();
	a[k] = 1;
	for(int i = k+1;i<n;i++)
		a[i] = 0;
	k = timSo0DauTien();	
}while(k!=-1);	
xuat();
}

int main()
{
	cin>>n;
	sinhNhiPhan();
}
