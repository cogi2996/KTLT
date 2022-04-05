#include<iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 double s = 0;
 double sx = 1,temp = 1;
 double x ;
 cin>>x;
 // do phuc tap n
for(int i = 0; i<= n;i++)
{
    s =  s + sx/temp;
    sx = sx * x;
    temp = temp*(++i,i--);
}
cout<<s;
}