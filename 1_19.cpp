#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <set>
#include <vector>
using namespace std;

int main()
{
    srand(time(0));
    ofstream fileOut1;
    fileOut1.open("SONGUYEN.INP", ios::out);
    long dem = 0;
    for (long i = 0; i < 1000; i++)
    {
        if (dem == 10)
        {
            fileOut1 << endl;
            dem = 0;
        }
        fileOut1 << rand() % 10 << " ";
        dem++;
    }
    // sap xep  theo thu tu tang dan
    ifstream fileIn;
    fileIn.open("SONGUYEN.INP", ios::in);
    multiset<long> s;
    long arr[2000];
    long i = 0;
    while (!fileIn.eof())
    {
        fileIn >> arr[i];
        s.insert(arr[i]);
        i++;
    }
    ofstream fileOut2;
    fileOut2.open("SONGUYEN.OUT", ios::out);
    long dem1 = 0;
    for (long v : s)
    {
        // if(v==1000)break;
        if (dem1 == 10)
        {
            fileOut2 << endl;
            dem1 = 0;
        }
        fileOut2 << v << " ";
        dem1++;
    }
    // fileOut2<<s.size();
    fileOut1.close();
    fileIn.close();
    fileOut2.close();
}
// fix loi thieu mat dong 100   