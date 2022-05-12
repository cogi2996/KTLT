#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100][100];
	int m,n; cin>>m>>n;
	for(int i =0;i<m;i++)
	{
		for(int j= 0;j<n;j++)
			cin>>a[i][j];
	}
	
	for(int i  =0;i<m;i++){
		for(int j =0;j<n;j++){
			int maxD = 1,minC = 1;
			int point = a[i][j];
			for(int x = 0;x<n;x++){
				if(a[i][x]>=point&&x!=j){
					maxD = 0;
				}
			}
			if(maxD == 0)
				continue;
			for(int y = 0;y<m;y++){
				if(a[y][j]<=point&&y!=i){
					minC = 0;
				}
			}
			if(minC ==0)
				continue;
			cout<<a[i][j]<<" ";
		}
	}
}

