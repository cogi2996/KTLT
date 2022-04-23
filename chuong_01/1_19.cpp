#include <iostream>
#include<set>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void docFile();
void taoFile();
void ghiFile();
multiset<int>s;

int main()
{
    taoFile();
    docFile();
    ghiFile();
}

void taoFile()
{
    fstream output;
    output.open("songuyen.inp", ios::out | ios::binary);
    if (output)
    {
        int A[10];
        int n = 1000;
        srand(unsigned(time(NULL)));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                A[j] = rand() % 100;
                // cout<<" "<<A[j]<<" ";
            }
            output.write(reinterpret_cast<char *>(&A), sizeof(A));
            output.write("\n", 1);
        }
        output.close();
    }
}

void docFile()
{
    fstream input("songuyen.inp", ios::in | ios::binary);
    if (!input)
    {
        cout << "Khong mo duoc file";
        exit(0);
    }
    cout << "---------------------------" << endl;
    int n = 0;
    while (true)
    {
        int B[10];
        input.read(reinterpret_cast<char *>(&B), sizeof(B));
        char c;
        input.read(reinterpret_cast<char *>(&c), sizeof(c));
        if (input.eof())
            break;
        for (int i = 0; i < 10; i++)
        {
          s.insert(B[i]);
            // cout<<A[n]<<" ";
        }
    }
    input.close();
    // for(auto v:s)
    //     cout<<v<<" ";
}

void ghiFile()
{
    fstream fileOut;
    fileOut.open("songuyen.out",ios::out);
    int n = 0;
    for(auto v:s)
    {
        fileOut<<v<<" ";
        n++;
        if(n == 10)
        {
            fileOut<<endl;
            n=0;
        }
        
    }
    fileOut.close();
}