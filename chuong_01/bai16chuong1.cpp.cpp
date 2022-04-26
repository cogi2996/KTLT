#include <iostream>
#include <string>
using namespace std;

struct DATE
{
    int d = 0, m = 0, y = 0;
};

struct COMPUTER
{
    string loaimay;
    string address;
    DATE date;
};

COMPUTER nhap()
{   
    cin.ignore(1);
    COMPUTER comp;
    cout << "Loai may:";
    getline(cin, comp.loaimay);
    cout << "xuat su: ";
    getline(cin, comp.address);
    cout << "time bao hanh"<<endl;
    cout << "[1]-ngay bao hanh" << endl;
    cout << "[2]-thang bao hanh" << endl;
    cout << "[3]-nam bao hanh" << endl;
    int chose = 0;
    do
    {   
        cout<<"==> nhap lua chon: ";
        cin >> chose;
        
        if (chose == 1)
        {
            cout << "nhap so ngay bao hanh: ";
            cin >> comp.date.d;
            break;
        }
        else if (chose == 2)
        {
            cout << "nhap so thang bao hanh: ";
            cin >> comp.date.m;
            break;
        }
        else if (chose == 3)
        {
            cout << "nhap so nam bao hanh: ";
            cin >> comp.date.y;
            break;
        }
        else
        {
            cout<<" ==>lua chon khong hop le, hap nhap lai";
            
        }
    } while (chose<1||chose>3);
    return comp;
}

void thongKe(COMPUTER *comp,int soLuong)
{
    int dem = 0;
    cout<<"Cac loai may bao hanh mot nam: "<<endl;
    for(int i =0;i<soLuong;i++)
    {
        if(comp[i].date.y == 1 )
        {
            dem++;
        }   
    }
    cout<<"-->Co "<<dem<<" may bao hanh 1 nam";
}

void thongKeMy(COMPUTER *comp,int soLuong)
{   
    int check = 0;
    cout<< "Cac may tinh co xuat su tu my: "<<endl;
    for(int i = 0;i <  soLuong;i++)
    {
        if(comp[i].address ==  "My"||comp[i].address ==  "my")
        {
            cout<<"-"<<comp[i].loaimay<<endl;
            check =1;
        }
    }
    if(check == 0)
    {
        cout<<endl<<"Khong ton tai may nao co xuat su tu My."<<endl;
    }
}

int main()
{
    int chose = 0;
    COMPUTER comp[100];
    int soLuong = 0;
    do
    {
        cout<<endl<<"[0]-EXIT"<<endl;
        cout<<"[1]-Them vao danh sach thong tin mot may tinh"<<endl;
        cout<<"[2]-Thong ke cac may co thoi han bao hanh 1 nam"<<endl;
        cout<<"[3]-In ra danh sach cac may tinh co xuat su tu My"<<endl;
        cin >> chose;
        switch (chose)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            comp[soLuong++] = nhap();
            break;
        }
        case 2: 
        {
            thongKe(comp,soLuong);
            break;
        }
        case 3:
        {
            thongKeMy(comp,soLuong);
            break;
        }
        default:
        {
            cout<<endl<<"Lua chon khong hop le, hap nhap lai."<<endl;
        }
        }
    } while (chose);
}