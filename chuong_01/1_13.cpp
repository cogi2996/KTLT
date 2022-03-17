#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

struct DATE
{
    int d, m, y;
};

struct DIEM
{
    float toan, li, hoa, diemTB;
};

struct SINHVIEN
{
    string MSSV;
    string TEN;
    DATE NGAYSINH;
    DIEM SOCRES;
    int rank = 0;
};

void solveDiemTB(SINHVIEN &sv)
{
    float diemtb;
    diemtb = (sv.SOCRES.toan + sv.SOCRES.li + sv.SOCRES.hoa) / 3;
    diemtb = round(diemtb * 10) / 10;
    sv.SOCRES.diemTB = diemtb;
}

void nhapSV(SINHVIEN &sv)
{
    cin.ignore(1);
    cout << "Nhap MSSV: ";
    getline(cin, sv.MSSV);
    cout << "HO VA TEN: ";
    cin.ignore(1);
    getline(cin, sv.TEN);
    cout << "NGAY SINH: ";
    cin >> sv.NGAYSINH.d >> sv.NGAYSINH.m >> sv.NGAYSINH.y;
    cout << endl
         << "DIEM TOAN: ";
    cin >> sv.SOCRES.toan;
    cout << endl
         << "DIEM LY:";
    cin >> sv.SOCRES.li;
    cout << endl
         << "DiEM HOA: ";
    cin >> sv.SOCRES.hoa;
    solveDiemTB(sv);
}

void xuatMang(SINHVIEN sv)
{
    cout << "----------------------------------------------------------------";
    cout << "MSSV" << sv.MSSV << endl;
    cout << "HO VA TEN: " << sv.TEN << endl;
    cout << "NGAY SINH: " << sv.NGAYSINH.d << "/" << sv.NGAYSINH.m << "/" << sv.NGAYSINH.y << endl;
    cout << "DIEM TOAN: " << sv.SOCRES.toan << " , "
         << "DIEM LI: " << sv.SOCRES.li << " , "
         << "DIEM HOA: " << sv.SOCRES.hoa << endl;
    cout << "==> diem trung binh: " << sv.SOCRES.diemTB << endl;
    cout << "----------------------------------------------------------------" << endl;
}

void duyetMang(SINHVIEN *sv, int &n)
{
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        nhapSV(sv[i]);
        solveDiemTB(sv[i]);
    }
    for (int i = 0; i < n; i++)
    {
        xuatMang(sv[i]);
    }
}

void FindRank(SINHVIEN *x, int n)
{
    map<float, int> a;
    for (int i = 0; i < n; i++)
    {
        float tempScore = x[i].SOCRES.diemTB;
        a[tempScore] = i;
    }

    int rankDiemTB = 1;
    for (auto r : a)
    {
        for (int i = 0; i < n; i++)
        {
            if (x[i].SOCRES.diemTB == r.first)
            {
                x[i].rank = rankDiemTB;
            }
        }
        rankDiemTB++;
    }
}

void xuatMangTheoRank(SINHVIEN *sv, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == sv[j].rank)
            {
                xuatMang(sv[j]);
            }
        }
    }
}

void xuatMangTheoDiemToan(SINHVIEN *sv, int n)
{
    float a[1000];
    for (int i = 0; i < n; i++)
        a[i] = sv[i].SOCRES.toan;
    sort(a, a + n);
    cout << "Xuat danh sach sinh vien theo thu tu giam dan diem toan: " << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (sv[j].SOCRES.toan == a[i])
            {
                xuatMang(sv[j]);
            }
        }
    }
}

void xuatMang3(SINHVIEN *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (sv[i].SOCRES.diemTB > 5 && sv[i].SOCRES.toan >= 3 && sv[i].SOCRES.li >= 3 && sv[i].SOCRES.hoa >= 3)
        {
            xuatMang(sv[i]);
        }
    }
}

int ktraNamNhuan(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

void xuatOldest(SINHVIEN *sv, int n)
{
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ktraNamNhuan(sv[0].NGAYSINH.y);
    int totalDay = sv[0].NGAYSINH.d + month[sv[0].NGAYSINH.m];
    int totalYear = sv[0].NGAYSINH.y;
    for (int i = 1; i < n; i++)
    {
        ktraNamNhuan(sv[i].NGAYSINH.y);
        if (!(totalDay < (sv[i].NGAYSINH.d + month[sv[i].NGAYSINH.m]) && totalYear <= sv[i].NGAYSINH.y))
        {
            totalDay = sv[i].NGAYSINH.d + month[sv[i].NGAYSINH.m];
            totalYear = sv[i].NGAYSINH.y;
        }
    }

    // duyet mang , cai nao co total day va total year bang thi in ra

    cout << "Sinh vien co tuoi lon nhat: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].NGAYSINH.d + month[sv[i].NGAYSINH.m] == totalDay && sv[i].NGAYSINH.y == totalYear)
        {
            cout << sv[i].TEN << " - MSSV: " << sv[i].MSSV << endl;
            cout << sv[i].NGAYSINH.d << "/" << sv[i].NGAYSINH.m << "/" << sv[i].NGAYSINH.y << endl;
            cout << "---!----!----!----!----!----!----!----!----!----" << endl;
        }
    }
}

void xuatTheoTen(SINHVIEN *sv, int n)
{
    string nameSV;
    cout << "Nhap vao ten sinh vien can tim thong tin ve sinh vien do: ";
    cin.ignore(1);
    getline(cin, nameSV);
    // diuet mang tim ten trung
    int checkOne = 1;
    for (int i = 0; i < n; i++)
    {
        if (nameSV == sv[i].TEN)
        {
            if (checkOne == 1)
            {
                cout << "         ==> Ket Qua ve ten sinh vien da nhap: " << endl;
                checkOne = 0;
            }
            xuatMang(sv[i]);
        }
        else
        {
            cout << "==> Khong co bat ki sinh vien nao co ten ban da nhap (X_x)" << endl;
        }
    }
}

int main()
{
    int n;
    SINHVIEN sv[100];
    duyetMang(sv, n);
    // cout<<endl<<"(xong cau a,b)"<<endl;
    // xuatMangTheoRank(sv, n);
    // cout<<endl<<"(xong cau d)"<<endl;
    // xuatMangTheoDiemToan(sv, n);
    // cout<<endl<<"(xong cau e)"<<endl;
    // diem trung binh lon hon 5 va khong co mon nao duoi 3
    // xuatMang3(sv, n);
    // cout<<endl<<"(xong cau f)"<<endl;
    // xuat sinh vien co tuoi lon nhat
    // xuatOldest(sv, n);
    // xuat thong tin sinh vien theo ten da nhap
    xuatTheoTen(sv, n);
}