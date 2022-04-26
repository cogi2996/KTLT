#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int chan[100];
    int n;
    cout<<"Nhap so phan tu: ";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>chan[i];
    }
    ofstream fileOut;
    fileOut.open("SOCHAN.DAT",ios::out);
    for(int i =0;i<n;i++)
    {
        fileOut<<chan[i]<<" ";
    }

    fileOut.close();
    ifstream fileIn;
    int dem = 0;
    fileIn.open("SOCHAN.DAT",ios::in);
    int arr[100];
    for(int i = 0;i<n;i++)
    {
        
        fileIn>>arr[i];
    }
    for(int i =0;i<n;i++)
    {
        if(dem == 30)
        {
            cout<<endl;
            dem =0;
        }
        cout<<arr[i]<<" ";
        dem++;
    }

}