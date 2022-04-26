#include <iostream>
#include <math.h>
using namespace std;

struct TOADO
{
    float x, y;
};

void nhap(TOADO &td1, TOADO &td2)
{
    cout << "Nhap toa do diem 1 (x1,y1): ";
    cin >> td1.x >> td1.y;
    cout << "Nhap toa do diem 2 (x2,y2): ";
    cin >> td2.x >> td2.y;
}

void xuat(string cauDan, TOADO td, string y, TOADO tdKQ, int key)
{
    if (key == 1)
    {
        cout << cauDan << "(" << td.x << "," << td.y << ")" << y << "(" << tdKQ.x << "," << tdKQ.y << ")";
    }
    else if (key == 0)
    {
        cout << cauDan << "(" << tdKQ.x << "," << tdKQ.y << ")";
    }
}

TOADO dxOx(TOADO td)
{
    TOADO tdcp;
    tdcp.x = td.x;
    tdcp.y = -td.y;
    return tdcp;
}

TOADO dxOy(TOADO td)
{
    TOADO tdcp;
    tdcp.x = -td.x;
    tdcp.y = td.y;
    return tdcp;
}

TOADO dxO(TOADO td)
{
    TOADO tdcp;
    tdcp.x = -td.x;
    tdcp.y = -td.y;
    return tdcp;
}

TOADO tong(TOADO td1, TOADO td2)
{
    TOADO tdcp;
    tdcp.x = td1.x + td2.x;
    tdcp.y = td1.y + td2.y;
    return tdcp;
}

TOADO hieu(TOADO td1, TOADO td2)
{
    TOADO tdcp;
    tdcp.x = td1.x - td2.x;
    tdcp.y = td1.y - td2.y;
    return tdcp;
}

float tich(TOADO td1, TOADO td2)
{
    float kq;
    kq = td1.x * td2.x + td1.y * td2.y;
    return kq;
}

float disPoint(TOADO td1, TOADO td2)
{
    float kq;
    kq = sqrt(pow(td1.x - td2.x, 2) + pow(td1.y - td2.y, 2));
    return round(kq * 100) / 100;
}

void tinhToan(TOADO td1, int key, TOADO td2, TOADO tdRong)
{
    cout << endl;
    xuat("Diem doi  xung qua hoanh do cua ", td1, " : ", dxOx(td1), key);
    cout << endl;
    xuat("Diem doi xung qua tung do cua ", td1, " : ", dxOy(td1), key);
    cout << endl;
    xuat("Diem doi xung qua toa do tam cua: ", td1, ":", dxO(td1), key);
}
int main()
{
    TOADO td1, td2, tdRong;
    nhap(td1, td2);
    int key = 1;
    tinhToan(td1, key, td2, tdRong);
    tinhToan(td2, key, td2, tdRong);
    key = 0;
    cout << endl;
    xuat("Tong cua hai diem da nhap: ", tdRong, ":", tong(td1, td2), key);
    cout << endl;
    xuat("Hieu cua hai diem da nhap: ", tdRong, ":", hieu(td1, td2), key);
    cout << endl;
    cout << "Tich cua hai diem da nhap:" << tich(td1, td2) << endl;
    cout << "Khoang cach giua hai diem da nhap: " << disPoint(td1, td2) << endl;
}