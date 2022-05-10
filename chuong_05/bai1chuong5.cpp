#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n ;
	string tempS;
	int count = 0,countCP = count;
	while(countCP <=n)
	{
		do{
			char numtoS =  count%2 +'0'; 
			tempS = numtoS+tempS;
			if(count/2 == 0)
				break;
			count/=2;
		}while(1);
		cout<<tempS<<endl;
		tempS.erase(tempS.begin(),tempS.end());
		count = ++countCP;
	}
}
