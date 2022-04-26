#include<iostream>
#include<math.h>
using namespace std;

struct HINHTRU
{
    float BanKinh,ChieuCao;
};

void nhap(HINHTRU &htru)
{   
    cout<<"Nhap R:";
    cin>>htru.BanKinh;
    cout<<"Nhap h: ";
    cin>>htru.ChieuCao;
}

float Sxq(HINHTRU htru)
{
    return round(htru.BanKinh*2*3.14*htru.ChieuCao*1000)/1000;
}

float Stp(HINHTRU htru)
{
    float kq =  htru.BanKinh*2*3.14*htru.ChieuCao + 2*3.14*pow(htru.BanKinh,2);
    return round(kq*1000)/1000;
}

float V(HINHTRU htru)
{
    float kq = 3.14*pow(htru.BanKinh,2)*htru.ChieuCao;
    return round(kq*1000)/1000;
}

int main()
{
    HINHTRU htru;
    nhap(htru);
    cout<<"Dien tich xung quanh: "<<Sxq(htru)<<endl;
    cout<<"Dien tich toan phan: "<<Stp(htru)<<endl;
    cout<<"The tich hinh tru: "<<V(htru);
    return 0;
}