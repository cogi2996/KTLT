#include<bits/stdc++.h>
using namespace std;
 
void batBit(long long&n,long long k){
	n =  n|(0x1<<k);
}
void tatBit(long long&n,long long k){
	n = n&(~(0x1<<k));
} 
//29122 21
long long layBit(long long n,long long k)
{
	return (n>>k)&0x1;
}
int main(){
	long long n,k; cin>>n>>k;
	long long a[1000],size = 0;
	for(long long i =31;i>=31-k+1;i--)
	{
		a[size] = layBit(n,i);
		size++;
	}
	n = n <<k;
	size = 0;
	for(long long i = k-1;i>=0;i--)
	{
		long long bit = a[size];
			if(bit == 1){
				batBit(n,i); 
			}
			else if(bit==0)
				tatBit(n,i);
		size++;
	}
	cout<<n;

}
