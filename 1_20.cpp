#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
ofstream fileOut;
fileOut.open("fSONGUYEN.INP",ios:: out);
srand(time(0));
int dem =0;
for(int i = 0;i<10000;i++)
{
    if(dem ==10)
    {
        fileOut<<endl;
        dem=0;
    }
    fileOut<<1+rand()%32767<<" ";
    dem++;
}
fileOut.close();

}
