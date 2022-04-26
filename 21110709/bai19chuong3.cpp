#include<iostream>
#include<cstdint>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int64_t	 temp = 0,i = 1;
    while(1)
    {
        temp++;
        if(i%n==0)
        {
            break;
        }
        i = i*10+1;
    }
    cout<<temp;
}