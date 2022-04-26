#include<iostream>
using namespace std;
struct PHANSO
{
    int tu, mau;
};

void nhap(PHANSO *ps,int &n)
{
    cout<<"Nhap so phan tu: ";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<"Nhap phan so thu "<<i+1<<" :";
        cin>>ps[i].tu>>ps[i].mau;
    }
}

void xuat(PHANSO *ps,int n)
{   
    cout<<"Cac phan so da nhap: ";
    for(int i = 0; i < n; i++)
    {
        cout<<ps[i].tu<<"/"<<ps[i].mau<<",";
    }
}

PHANSO findMax(PHANSO *ps,int n)
{   

    PHANSO maxps;
    maxps.tu = ps[0].tu;
    maxps.mau = ps[0].mau;
    for(int i = 1; i < n; i++)
    {
        if((maxps.tu*ps[i].mau - maxps.mau*ps[i].tu)*(maxps.mau*ps[i].mau)<0 )
        {
            maxps.tu = ps[i].tu;
            maxps.mau = ps[i].mau;
        }
    }
    return maxps;
}

int MAUCHUNG(PHANSO *ps,int n)
{
    int mauChung = 1;
    for(int i = 0 ; i < n; i++)
    {
        mauChung *= ps[i].mau;
    }
    return mauChung;

}

int UCLN (int tongTu,int mau)
{
    tongTu = abs(tongTu);
    mau = abs(mau);
    while(tongTu !=mau)
    {
        if(tongTu > mau ) tongTu -= mau;
        if(tongTu < mau) mau -= tongTu;
    }
    return mau;
}

PHANSO TONG(PHANSO *ps,int n)
{
    PHANSO tongPS;
    int tongTu = 0;
    for(int i = 0 ; i < n; i++)
    {
        tongTu+= ps[i].tu*(MAUCHUNG(ps,n)/ps[i].mau);
    }
    int Mau = MAUCHUNG(ps,n);
    tongPS.tu = tongTu/UCLN(tongTu,Mau);
    tongPS.mau = MAUCHUNG(ps,n)/UCLN(tongTu,Mau);
    if(tongPS.tu<0&&tongPS.mau<0)
    {
        tongPS.tu = -tongPS.tu;
        tongPS.mau = -tongPS.mau;
    }
    return tongPS;
}

int main()
{   
    PHANSO ps[100];
    int n;
    nhap(ps,n);
    xuat(ps,n);
    cout<<"Gia tri lon nhat : "<<findMax(ps,n).tu<<"/"<<findMax(ps,n).mau;
    cout<<endl<<"Tong cac phan so "<<TONG(ps,n).tu<<"/"<<TONG(ps,n).mau;
}