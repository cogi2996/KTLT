#include <iostream>
using namespace std;
struct PHANSO
{
    int tu, mau;
};
struct HONSO
{
    int nguyen, tu, mau;
};

void nhap(HONSO &hs)
{
    cout << "Nhap phan nguyen: ";
    cin >> hs.nguyen;
    cout << "Nhap tu so: ";
    cin >> hs.tu;
    cout << "Nhap mau so: ";
    cin >> hs.mau;
}

void xuatPS(PHANSO ps)
{
    cout << "==> dang phan so: ";

    cout << ps.tu << "/" << ps.mau << endl;
}

PHANSO HStoPS(HONSO hs)
{
    PHANSO ps;
    ps.tu = hs.nguyen * hs.mau + hs.tu;
    ps.mau = hs.mau;
    return ps;
}

HONSO SumHS(HONSO hs1, HONSO hs2)
{

    HONSO sum;
    sum.nguyen = hs1.nguyen + hs2.nguyen;
    sum.mau = hs1.mau * hs2.mau;
    sum.tu = hs1.tu * hs2.mau + hs2.tu * hs1.mau;
    return sum;
}

void xuatHS(HONSO hs)
{
    cout << hs.nguyen << "(" << hs.tu << "/" << hs.mau << ")";
}

PHANSO tichHS(HONSO hs1, HONSO hs2)
{
    PHANSO ps1 = HStoPS(hs1), ps2 = HStoPS(hs2), tichPS;
    tichPS.tu = ps1.tu * ps2.tu;
    tichPS.mau = ps1.mau * ps2.mau;
    return tichPS;
}

int main()
{
    HONSO hs1, hs2;
    nhap(hs1);
    xuatPS(HStoPS(hs1));
    nhap(hs2);
    cout << hs1.nguyen << "(" << hs1.tu << "/" << hs1.mau << ")"
         << " + " << hs2.nguyen << "(" << hs2.tu << "/" << hs2.mau << ") = ";
    xuatHS(SumHS(hs1, hs2));
    cout << endl
         << hs1.nguyen << "(" << hs1.tu << "/" << hs1.mau << ")"
         << " * " << hs2.nguyen << "(" << hs2.tu << "/" << hs2.mau << ") = ";
    xuatPS(tichHS(hs1, hs2));
}