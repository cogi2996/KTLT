#include <iostream>
using namespace std;

struct PHANSO
{
    long tu, mau;
};

void XuliLoiVat(PHANSO &ps1,PHANSO &ps2)
{
    if(ps1.tu < 0  && ps1.mau <0)
    {
        ps1.tu = -ps1.tu;
        ps1.mau = -ps1.mau;
    }
    if(ps2.tu < 0  && ps2.mau <0)
    {
        ps2.tu = -ps2.tu;
        ps2.mau = -ps2.mau;
    }
    ////////////////////////////////
    if(ps1.tu > 0 && ps1.mau <0)
    {
        ps1.tu = -ps1.tu;
        ps1.mau = -ps1.mau;
    }

     if(ps2.tu > 0 && ps2.mau <0)
    {
        ps2.tu = -ps2.tu;
        ps2.mau = -ps2.mau;
    }
}

void nhap(PHANSO &ps1, PHANSO &ps2)
{
    cout << "Nhap phan so 1: ";
    cin >> ps1.tu >> ps1.mau;

    cout << "Nhap phan so 2: ";
    cin >> ps2.tu >> ps2.mau;
  
}

void xuat(PHANSO x,string y)
{
    cout<<y+ " hai phan so: "<< x.tu<<"/"<<x.mau;
    cout<<endl;
}

PHANSO tong(PHANSO ps1,PHANSO ps2)
{
    PHANSO x;
    x.tu =  ps1.tu*ps2.mau + ps2.tu*ps1.mau;
    x.mau = ps1.mau*ps2.mau;
    return x;
}

PHANSO hieu (PHANSO ps1,PHANSO ps2)
{
    PHANSO x;
    x.tu =  ps1.tu*ps2.mau - ps2.tu*ps1.mau;
    x.mau = ps1.mau*ps2.mau;
    return x;
}

PHANSO tich(PHANSO ps1,PHANSO ps2)
{
    PHANSO x;
    x.tu = ps1.tu*ps2.tu;
    x.mau = ps1.mau*ps2.mau;
    return x;

}

PHANSO thuong (PHANSO ps1,PHANSO ps2)
{
    PHANSO x;
    x.tu =  ps1.tu*ps2.mau;
    x.mau =  ps1.mau*ps2.tu;
    return x;
}

int ucln(PHANSO ps)
{
    ps.tu =  abs(ps.tu);
    ps.mau = abs(ps.mau);
    while(ps.tu!=ps.mau)
    {
        if(ps.tu > ps.mau) ps.tu-= ps.mau;
        if(ps.tu < ps.mau) ps.mau -= ps.tu;
    }
    return ps.tu;
}

PHANSO rutGonPS (PHANSO ps,int UCLN)
{
    ps.tu = ps.tu/UCLN;
    ps.mau = ps.mau/UCLN;
    return ps;
}

void quyDong (PHANSO &ps1cp,PHANSO &ps2cp)
{
    long mauChung = ps1cp.mau*ps2cp.mau;
    ps1cp.tu =  ps1cp.tu*(mauChung/ps1cp.mau);
    ps1cp.mau = mauChung;
    ps2cp.tu = ps2cp.tu*(mauChung/ps2cp.mau);
    ps2cp.mau = mauChung;
}

void soSanhPS (PHANSO ps1, PHANSO ps2,PHANSO ps1cp,PHANSO ps2cp)
{
    if(ps1cp.tu>ps2cp.tu) cout<<"So sanh phan so: "<<ps1.tu<<"/"<<ps1.mau<<" > "<<ps2.tu<<"/"<<ps2.mau;
    else if(ps1cp.tu<ps2cp.tu) cout<<ps1.tu<<"/"<<ps1.mau<<" < "<<ps2.tu<<"/"<<ps2.mau;
    else cout<<"So sanh phan so: "<<ps1.tu<<"/"<<ps1.mau<<" = "<<ps2.tu<<"/"<<ps2.mau;
}

int ktraPS(PHANSO ps1, PHANSO ps2)
{
    if(ps1.mau==0||ps2.mau == 0)return 0;
    return  1;
}
int main()
{   
    
    PHANSO ps1, ps2;
    nhap(ps1, ps2);
    if(!ktraPS(ps1,ps2))
    {
        cout<<"Khong hop le, hay nhap lai phan so.";
        return 0;
    }
    XuliLoiVat(ps1,ps2);
    xuat(tong(ps1, ps2),"Tong");
    xuat(hieu(ps1, ps2),"Hieu");    
    xuat(thuong(ps1,ps2),"Thuong");
    xuat(tich(ps1,ps2),"Tich");
    PHANSO compactPS1 = rutGonPS(ps1 , ucln(ps1)),compactPS2 =  rutGonPS(ps2, ucln(ps2));
    cout<<ps1.tu<<"/"<<ps1.mau<<" ==>Rut gon = "<< compactPS1.tu<<"/"<<compactPS1.mau<<endl;
    cout<<ps2.tu<<"/"<<ps2.mau<<" ==>Rut gon = "<<compactPS2.tu<<"/"<<compactPS2.mau;
    PHANSO ps1cp = ps1, ps2cp = ps2;
    quyDong(ps1cp,ps2cp);
    cout<<endl<<ps1.tu<<"/"<<ps1.mau<<" va "<<ps2.tu<<"/"<<ps2.mau<<" sau khi quy dong: ";
    cout<<ps1cp.tu<<"/"<<ps1cp.mau<<" va "<<ps2cp.tu<<"/"<<ps2cp.mau<<endl;
    soSanhPS(ps1,ps2,ps1cp,ps2cp);
}