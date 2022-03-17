#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
using namespace std;

struct  DATE 
{
    int d,m,y;

};
 struct HOCSINH 
 {
    string mshs,hoten,diachi,phai;
    DATE  ngaysinh;
    float diemtb;
    string dauOrRot;
 };

void nhap(HOCSINH *hs,int &n)
{
    cout<<"Nhap so luong hoc sinh: ";
    cin>>n;
    cin.ignore();
        cout<<"----*----*----*----*----*----*----*----*----"<<endl;
    for(int i =0;i<n;i++)
    {   
        cout<<"Nhap MSHS cua hoc sinh thu "<<i+1<< " : ";
        getline(cin,hs[i].mshs);
        cout<<endl<<"Ho va ten :";
        getline(cin,hs[i].hoten);
        cout<<"Ngay thang nam sinh:";
        cin>>hs[i].ngaysinh.d>>hs[i].ngaysinh.m>>hs[i].ngaysinh.y;
        cout<<"Dia chi:"; 
        cin.ignore();
        getline(cin,hs[i].diachi);  
        cout<<"Gioi tinh:";
        getline(cin,hs[i].phai); 
        cout<<"Diem trung binh: ";
        cin>>hs[i].diemtb;
        cout<<"----*----*----*----*----*----*----*----*----"<<endl;
    }
}

void xuat(HOCSINH *hs,int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<"MSHS: "<<hs[i].mshs<<endl;
        cout<<"Ho va ten: "<<hs[i].hoten<<endl;
        cout<<"Ngay sinh: "<<hs[i].ngaysinh.d<<"/"<<hs[i].ngaysinh.m<<"/"<<hs[i].ngaysinh.y<<endl;
        cout<<"Dia chi: "<<hs[i].diachi<<endl;
        cout<<"Gioi tinh: "<<hs[i].phai<<endl;
        cout<<"Diem trung binh: "<<hs[i].diemtb<<endl;
        if(hs[i].diemtb>=5)
        {
            cout<<"==> Du dieu kien len lop."<<endl;
        }
        else{
            cout<<"==> Khong du dieu kien len lop.";
        }
        cout<<"----*----*----*----*----*----*----*----*----"<<endl;
    }
}

 int main()
 {
    HOCSINH hs[50];
    int n;
    nhap(hs,n);
    xuat(hs,n);
 }