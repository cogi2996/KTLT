#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct DONGIA
{
    string loai1, loai2;
};

struct LINHKIEN
{
    string name;
    string quycach;
    string loai;
    DONGIA dongia;
};

void xuatSP(LINHKIEN linhkien)
{
    cout << endl
         << "----------------------------------------------------------------" << endl;
    cout << "Ten linh kien: " << linhkien.name << endl;
    cout << "Quy cach: " << linhkien.quycach << endl;
    cout << "Loai: " << linhkien.loai << endl;
    cout << "Don gia " << linhkien.dongia.loai1 << endl;
    cout << "----------------------------------------------------------------" << endl;
}

LINHKIEN nhap()
{
    cin.ignore();
    LINHKIEN linhkien;
    cout << "Ten linh kien: ";
    getline(cin, linhkien.name);
    cout << endl
         << "Quy cach: ";
    getline(cin, linhkien.quycach);
    cout << "Loai :";
    int chose;
    cout << endl
         << "[1] - loai A.";
    cout << endl
         << "[2] - loai B." << endl;
    int key1 = 0;
    do
    {
        cin >> chose;
        switch (chose)
        {
        case 1:
        {
            linhkien.loai = "A";
            key1 = 1;
            break;
        }

        case 2:
        {
            linhkien.loai = "B";
            key1 = 1;
            break;
        }
        default:
        {
            cout << " ==> lua chon khong hop le, hay chon lai." << endl;
        }
        }

    } while (key1 == 0);
    int choseCost;
    cout << "[1] - Don gia loai 1";
    cout << endl
         << "[2] -  Don gia loai 2" << endl;
    do
    {
        cin >> choseCost;
        if (choseCost == 1)
        {
            cout << endl
                 << "--->Nhap gia tien : ";
            cin.ignore(1);
            getline(cin, linhkien.dongia.loai1);
            linhkien.dongia.loai1 = " loai 1: " + linhkien.dongia.loai1;
            break;
        }
        else if (choseCost == 2)
        {
            cout << "--->Nhap gia tien: ";
            cin.ignore(1);
            getline(cin, linhkien.dongia.loai2);
            linhkien.dongia.loai2 = " loai 2: " + linhkien.dongia.loai2;
            break;
        }
        else if (choseCost != 1 && choseCost != 2)
        {
            cout << "Lua chon khong hop le , hay chon lai";
        }
    } while (choseCost != 1 || choseCost != 2);
    return linhkien;
}

void sapxep(LINHKIEN *linhkien, int n)
{
    set<int> a;
    for (int i = 0; i < n; i++)
    {
        if (linhkien[i].loai == "A")
        {
            // if(minName(linhkien[i],linhkien,n)) //tim ten ngan nhat
            for (int j = 0; j < n; j++)
            {
                a.insert(linhkien[j].name.length());
            }
            int j = 0;
            for (auto x : a)
            {

                for (int j = 0; j < n; j++)
                {
                    if (x == linhkien[j].name.length())
                    {
                        xuatSP(linhkien[j]);
                    }
                }
            }
        }
    }
}

int main()
{
    int slLinhkien = 0;
    LINHKIEN linhkien[100];

    int chose;
    do
    {
        cout << "[0]-EXIT" << endl;
        cout << "[1]-Them mot san pham" << endl;
        cout << "[2]-Xuat danh sach san pham:" << endl;
        cin >> chose;
        switch (chose)
        {
        case 0:
        {
            break;
        }
        case 1:
            linhkien[slLinhkien++] = nhap();
            break;
        case 2:
        {
            sapxep(linhkien, slLinhkien);
        }
        default:
            cout << endl
                 << "Lua chon khong hop le, hay thu lai." << endl;
        }
    } while (chose);
}