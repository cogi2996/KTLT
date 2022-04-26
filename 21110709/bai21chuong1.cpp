#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fileOut;
    int n ;
    cout<<"Nhap so phan tu ";
    cin>>n;
    fileOut.open("SONGUYEN.INP",ios::out);
    int a[1000];
    // nhap so
    for(int i= 0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i =0;i<n;i++)
    {
        fileOut<<a[i]<<" ";
    }
    fileOut.close();
    // doc file
    cout<<endl<<"HERE";
    ifstream DocSo;
    DocSo.open("SONGUYEN.INP",ios::in);
    int arr[100],chan[100],le[100];
    int i =0;
    int demChan = 0;
    int demLe = 0;
    while(i<n)
    {
        DocSo>>arr[i];
        if(arr[i]%2==0)
        {
            chan[demChan] =  arr[i];
            demChan++;
        }
        if(arr[i]%2!=0)
        {
            
            le[demLe] =  arr[i];
            demLe++;
        }
        i++;
    }
    cout<<endl<<"HERE"<<endl;

    // // xuat chan 
    // DocSo.close();
    // for(int j = 0;j<demChan;j++)
    // {
    //     cout<<chan[j]<<",";
    // }
    
    ofstream fileOut3,fileOut4;
    fileOut3.open("SOLE.OUT",ios::out);
    for(int j = 0;j<i-demChan;j++)
    {   
        fileOut3<<le[j]<<" ";
    }
    fileOut3.close();
    fileOut4.open("SOCHAN.OUT",ios::out);
    for(int j = 0;j<demChan;j++) 
    { 
        fileOut4<<chan[j]<<" ";
    }
    fileOut4.close();

}