#include<iostream>
#include<set>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{
    fstream file1,file2;
    file1.open("SONGUYEN.INP",ios::out);
    for(int i =1 ;i<=10000;i++)
    {
        file1<< rand()%10<<" ";
        if(i%10==0)
            file1<<endl;
    }
    file1.close();
    file1.open("SONGUYEN.INP",ios::in);
    multiset<int>s;
    int i  =0;
    while(i<10000)
    {
        int x;
        file1>>x;
        s.insert(x);
        i++;
    }
    i = 0;
    file1.close();
    file2.open("SONGUYEN.OUT",ios::out);
    int temp = 0;
    for(auto v:s)
    {
        file2<<v<<" ";
        temp++;
        if(temp == 10)
        {
            file2<<endl;
            temp = 0; 
        }
    }
    file2.close();
}