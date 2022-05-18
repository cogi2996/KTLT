#include<bits/stdc++.h>
using namespace std;
//CACH 1
int a[100];
int main()
{
	int n; cin>>n;
	set<int> s;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	for(set<int>::iterator j = s.begin();j!=s.end(); j++){
		for(int i = 0;i<n;i++){
			if(*j == a[i]){
				cout<<a[i]<<" ";
				break;
			}
		}
	}
	
	
}

//CACH 2
//int a[100],n,b[100];
//int sizeB ;
//void xuat()
//{
//	for(int i =0;i<n;i++)
//	{
//		for(int j = 0;j<sizeB ;j++)
//		{
//			if(a[i] ==  b[j])
//			{
//				cout<<a[i]<<" ";
//				break;
//			}
//		}
//	}
//		
//}
//int main()
//{
//	cin>>n;
//	for(int i =0;i<n;i++)
//	{
//		cin>>a[i];
//		b[i] = a[i];
//	}
//	 sizeB = n;
//	// cach 1
//	//2123
//	//1223
//	sort(a,a+n);
//	for(int i = 0;i<n;i++)
//	{
//		int j = i+1;
//		while(j<n&&a[i]==a[j])
//		{
//			j++;
//		}
//		if(j==n)
//			break;
//		else if(i!=j){
//			// doi den j
//			int goc = i+1;
//			for(int k = j;k<n;k++)
//			{
//				a[goc++] = a[k];
//			}
//			n = n-(j-i-1);
//		}
//	}
//	xuat();
//}
