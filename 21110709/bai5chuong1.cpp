#include <iostream>
using namespace std;

struct SOPHUC 
{
    int re, im;
};

void nhap(SOPHUC &sp1, SOPHUC &sp2)
{
    cout<<"nhap so phuc thu 1: ";
    cin>>sp1.re>>sp1.im;
    cout<<"nhap so phuc thu 2: ";
    cin>>sp2.re>>sp2.im;
}

SOPHUC tong(SOPHUC sp1,  SOPHUC sp2)
{
    SOPHUC PhucTong;
    PhucTong.re  = sp1.re + sp2.re;
    PhucTong.im =  sp1.im + sp2.im;
    return PhucTong;
}

SOPHUC hieu (SOPHUC sp1, SOPHUC sp2)
{
    SOPHUC PhucHieu;
    PhucHieu.re =  sp1.re - sp2.re;
    PhucHieu.im = sp1.im - sp2.im;
    return PhucHieu;
}

SOPHUC tich(SOPHUC sp1,SOPHUC sp2)
{
    SOPHUC PhucTich;
    PhucTich.re =  sp1.re*sp2.re - sp1.im*sp2.im ;
    PhucTich.im = sp1.re*sp2.im + sp2.re*sp1.im;
    return PhucTich;
}


void xuat(SOPHUC x,string  y)
{
if(x.re>0) cout<<y+ " hai so phuc: "<<x.im<<"i + "<<x.re;
    else cout<<y+" hai so phuc: "<<x.im<<"i "<<x.re;
cout<<endl;
}
int main()
{
    SOPHUC sp1,sp2;
    nhap(sp1, sp2);
    SOPHUC PhucTong = tong(sp1,sp2),PhucHieu = hieu(sp1,sp2),PhucTich = tich(sp1,sp2);
    xuat(PhucTong,"Tong");
    xuat(PhucHieu,"Hieu");
    xuat(PhucTich,"Tich");    
}