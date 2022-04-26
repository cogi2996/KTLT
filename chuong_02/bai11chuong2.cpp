#include <iostream>
#include <string>
using namespace std;

bool Max(int a, int b)
{
    return a >= b;
}

void lamBang(string &a, string &b)
{
    if (Max(a.length(), b.length()))
    {
        int addZero = a.length() - b.length();
        for (int i = 0; i < addZero; i++)
        {
            b = '0' + b;
        }
    }
    else
    {
        int addZero = b.length() - a.length();
        for (int i = 0; i < addZero; i++)
        {
            a = '0' + a;
        }
    }
}

void XuatTong(string a, string b)
{
    string kq;
    int temp = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    int sl = 0;
    if (i >= j)
    {
        sl = i;
    }
    else
    {
        sl = j;
    }
    int slcp = sl + 1;
    int keyDu = 0;

    lamBang(a, b);

    while (1)
    {
        if (sl == -1)
        {
            if (temp == 0)
            {
                break;
            }
            keyDu = 1;
            string x;
            x[0] = (temp + '0');
            kq = x[0] + kq;
            break;
        }
        else
        {
            string x;
            x[0] = (((a[sl] - '0') + (b[sl] - '0') + temp) % 10) + '0';
            temp = ((a[sl] - '0') + (b[sl] - '0') + temp) / 10;
            kq = x[0] + kq;
        }
        sl--;
    }
    for (int k = 0; k < slcp + keyDu; k++)
    {
        cout << kq[k];
    }
}
// -2334
// 0238
// 0004
int thanhSo(string x)
{
    int so = 0;
    int temp = 0;
    while (temp < x.length())
    {
        if (x[temp] == '-')
        {
            temp++;
            continue;
        }
        so = so * 10 + x[temp];
        temp++;
    }
    return so;
}

int soSanh(string a, string b)
{
    if (thanhSo(a) >= thanhSo(b))
    {
        return 1;
    }
    return 0;
}

void xuatHieu(string a, string b)
{
    string kq;
    int sl = 0;
    if (!soSanh(a, b))
    {
        string x;
        x = a;
        a = b;
        b = x;
    }
    if (a.length() >= b.length())
    {
        sl = a.length() - 1;
    }
    else
    {
        sl = b.length() - 1;
    }
    lamBang(a, b);
    int slcp = sl + 1;

    int temp = 0;

    while (sl != -1)
    {
        if (a[sl] >= b[sl] + temp)
        {
            string x;
            x[0] = (((a[sl] - '0') - (b[sl] - '0') - temp) + '0');
            kq = x[0] + kq;
            temp = 0;
        }
        else
        {
            string x;
            x[0] = ((10 + (a[sl] - '0') - (b[sl] - '0') - temp) + '0');
            kq = x[0] + kq;
            temp = 1;
        }
        sl--;
    }

    if (kq[0] == '0')
    {
        for (int i = 1; i < slcp; i++)
        {
            cout << kq[i];
        }
    }
    else
    {
        for (int i = 0; i < slcp; i++)
        {
            cout << kq[i];
        }
    }
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout<<"==>tong: "<<endl;
    // tong a duong b duong
    if (a[0] != '-' && b[0] != '-')
    {
        XuatTong(a, b);
        cout<<endl;
    }
    // tong a am b duong
    if (a[0] == '-' && b[0] != '-')
    {
        string x;
        x = a;
        x.erase(x.begin());
        if(soSanh(a, b))
        {
            cout<<"-";
        }
        xuatHieu(x, b);
        cout<<endl;
    }
    // tong a duong b am
    if (a[0] != '-' && b[0] == '-')
    {
        string x;
        x = b;
        x.erase(x.begin());
        if(soSanh(x, a))
        {
            cout<<"-";
        }
        xuatHieu(a, x);
        cout<<endl;
    }
    // tong a am b am
    if (a[0] == '-' && b[0] == '-')
    {
        string x;
        x = a;
        x.erase(x.begin());
        string y;
        y = b;
        y.erase(y.begin());
        cout << "-";
        XuatTong(x, y);
        cout<<endl;
    }
cout<<"==>Hieu: "<<endl;
    // xuat hieu hai so nguyen duong
    if (a[0] != '-' && b[0] != '-')
    {
        if (soSanh(a, b))
        {
            xuatHieu(a, b);
        }
        else
        {
            cout << "-";
            xuatHieu(b, a);
        }
    }
    // hieu a am b duong
    if (a[0] == '-' && b[0] != '-')
    {
        string x;
        x = a;
        x.erase(x.begin());
        string y;
        y = b;
        cout << "-";
        XuatTong(x, y);
    }
    //  hieu a duong b am
    if (a[0] != '-' && b[0] == '-')
        {
            string x;
            x = b;
            x.erase(x.begin());
            XuatTong(a, x);
        }
    // hieu a am b am
    if (a[0] == '-' && b[0] == '-')
        {
            string x;
            x = a;
            x.erase(x.begin());
            string y;
            y =  b;
            y.erase(y.begin());
            if(soSanh(x,y))
            {
                cout<<"-";
            }
            xuatHieu(x, y);
        }
}