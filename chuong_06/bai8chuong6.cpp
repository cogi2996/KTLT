#include<iostream>
#include<string>
using namespace std;
int pascal(int k,int n)
{
	if(k==0||k==n)
		return 1;
	else{
		return pascal(k-1,n-1) + pascal(k,n-1);
	}
}
int main()
{
	int a[100] = {0},sizeA = 0;
	string s[100][100];
	int n;	cin>>n;
	int k,i;
	for(i= 0;i<=n;i++)
	{
		for( k = 0;k<=i;k++){
			a[sizeA++] = pascal(k,i);
		}
	}	
	int lc = n-1;
	int countA = 0;
	for(int i =0;i<n;i++)
	{	
		int cur = lc;
		for(int j = 0;j<2*n-1;j++){
			
			if(j == cur&&j<=((n-1)*2-lc)){
				s[i][j] += to_string(a[countA++]);	
				cur = cur + 2;		
			}
			else
				s[i][j] += ' ';
			cout<<s[i][j]<<"      ";
		}
		cout<<endl;
		lc--;
	}
	
	
}
