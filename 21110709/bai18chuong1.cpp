#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct MATHANG
{
    string mahang;
    string name;
    int soluong;
    float dongia;
    int soluongton;//  hang ton kho
    int timeBH; // time bao hanh
};

void xuat(MATHANG mh)
{
    cout << endl
         << "Ma hang: " << mh.mahang << endl;
    cout << "Ten mat hang: " << mh.name << endl;
    cout << "So luong: " << mh.soluong << endl;
    cout << "Don gia: " << mh.dongia << endl;
    cout << "So luong ton: " << mh.soluongton << endl;
    cout << "Bao hanh: " << mh.timeBH << endl;
}

MATHANG nhap()
{
    MATHANG mh;
    cin.ignore();
    cout << "Ma hang: ";
    getline(cin, mh.mahang);
    cout << "Ten mat hang: ";
    getline(cin, mh.name);
    cout << "So luong: ";
    cin >> mh.soluong;
    cout << "Don gia: ";
    cin >> mh.dongia;
    cout << "So luong ton: ";
    cin >> mh.soluongton;
    cout << "Thoi gian bao hanh: ";
    cin >> mh.timeBH;
    return mh;
}

void FindTonKho1(MATHANG *mh, int sl, int *arr, int &keySL)
{
    set<int> s; // so luong hang ton kho khong trung lap
    for (int i = 0; i < sl; i++)
    {
        s.insert(mh[i].soluongton);
    }
    int chiSo = 0;
    for (auto x : s)
    {
        arr[chiSo++] = x;
    }
    int key = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (key == 1)
        {
            break;
        }
        for (int j = 0; j < sl; j++)
        {
            if (arr[i] == mh[j].soluongton)
            {
                cout << "-" << mh[j].name << endl;
                key = 1;
            }
        }
    }
    keySL = s.size();
}

void FindTonKho2(MATHANG *mh, int sl, int *arr, int &keySL)
{
    set<int> s; // so luong hang ton kho khong trung lap
    for (int i = 0; i < sl; i++)
    {
        s.insert(mh[i].soluongton);
    }
    int chiSo = 0;
    for (auto x : s)
    {
        arr[chiSo++] = x;
    }
    int key = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (key == 1)
        {
            break;
        }
        for (int j = 0; j < sl; j++)
        {
            if (arr[i] == mh[j].soluongton)
            {
                cout << "-" << mh[j].name << endl;
                key = 1;
            }
        }
    }
    keySL = s.size();
}

// void doiNguocArr(int *arr, int sl)
// {
//     int arv[100]; // arr copy
//     int z = 0;
//     for (int i = sl - 1; i >= 0; i--)
//     {
//         arv[z] = arr[i];
//         z++;
//     }
//     for (int i = 0; i < sl; i++)
//     {
//         arr[i] = arv[i];
//     }
// }

void MaxMoney(MATHANG *mh, int sl)
{
    float m[100];
    for (int i = 0; i < sl; i++)
    {
        m[i] = mh[i].dongia;
    }
    sort(m, m + sl);
    cout << endl
         << "Mat hang co gia tien cao nhat: " << endl;
    for (int i = 0; i < sl; i++)
    {
        if (m[sl - 1] == mh[i].dongia)
        {
            cout << mh[i].name << endl;
        }
    }
}

void BaoHanh12(MATHANG *mh, int sl)
{
    int check = 0;
    for (int i = 0; i < sl; i++)
    {
        if (mh[i].timeBH > 12)
        {
            xuat(mh[i]);
            check = 1;
        }
    }
    if (check == 0)
    {
        cout << endl
             << "Khong co san pham nao bao hanh tren 12 thang";
    }
}

void SXluongTon (MATHANG *mh, int sl)
{
    set<int> sx;
    for(int i =0;i<sl;i++)
    {
        sx.insert(mh[i].soluongton);
    }
    for(auto x:sx)
    {
        for(int i =0 ;i<sl;i++)
        {
            if(x == mh[i].soluongton)
            {
                xuat(mh[i]);
            }
        }
    }
}

int main()
{
    int keySL = 0;
    int SLmatHang = 0;
    MATHANG mathang[200];
    int arr[100];
    int chose;
    do
    {
        cout << "[0]-EXIT" << endl;
        cout << "[1]-Nhap mot don hang" << endl;
        cout<<"[2]-Tim mat hang co luong ton nhieu nhat"<<endl;
        cout<<"[3]-Tim mat hang co luong ton it nhat"<<endl;
        cout<<"[4]-Tim mat hang co gia tien cao nhat"<<endl;
        cout<<"[5]-In ra nhung mat hang bao hanh 12 thang"<<endl;
        cout<<"[6]-Sap xep cac mat hang tang dan theo luong hang ton"<<endl;
        cin >> chose;
        switch (chose)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            mathang[SLmatHang++] = nhap();
            break;
        }
        case 2:
        {
            cout << "Mat hang co so luong ton kho nhieu nhat: " << endl;
            FindTonKho1(mathang, SLmatHang, arr, keySL);
            break;
        }
        case 3:
        {
            cout << "Mat hang co so luong ton kho it nhat: " << endl;
            // doiNguocArr(arr, keySL);
            FindTonKho2(mathang, SLmatHang, arr, keySL);
            break;
        }
        case 4:
        {
            // gia tien cao nhat
            MaxMoney(mathang, SLmatHang);
            break;
        }
        case 5:
        {
            BaoHanh12(mathang, SLmatHang);
            break;
        }
        case 6:
        {
            SXluongTon(mathang,SLmatHang);
            break;
        }
        }
    } while (chose);
}
