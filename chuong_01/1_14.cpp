#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct VIDEO
{
    string name;
    string theloai;
    string nameDirect;
    string nameActor;
    string nameAtress;
    int year;
    string firm;
};

VIDEO nhapFilm()
{
    VIDEO film;
    cin.ignore(1);
    cout << "Ten phim: ";
    getline(cin, film.name);
    cout << endl
         << "The loai: " << endl;
    cout << "[1]-Hinh su" << endl;
    cout << "[2]-tinh cam" << endl;
    cout << "[3]-hai" << endl;
    int x;
    while (1)
    {
        cin >> x;
        if (x == 1)
        {
            film.theloai = "hinh su";
            break;
        }
        if (x == 2)
        {
            film.theloai = "tinh cam";
            break;
        }
        if (x == 3)
        {
            film.theloai = "hai";
            break;
        }
        if (x < 1 || x > 3)
        {
            cout << "-->lua chon khong hop le, hay nhap lai...";
        }
    }
    cout << "Ten dao dien: ";
    cin.ignore(1);
    getline(cin, film.nameDirect);
    cout << endl
         << "Ten dien vien nam: ";
    getline(cin, film.nameActor);
    cout << endl
         << "Ten dien vien nu: ";
    getline(cin, film.nameAtress);
    cout << endl
         << "Nam san xuat: ";
    cin >> film.year;
    cout << endl
         << "Hang san xuat: ";
    cin.ignore(1);
    getline(cin, film.firm);
    return film;
}

void xuatDSphim1(VIDEO *film, string theLoai, int n)
{
    cout << "Cac phim nam trong the loai vua nhap :" << endl;
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (film[i].theloai == theLoai)
        {
            cout << " -" << film[i].name << endl;
            check = 1;
        }
    }
    if (check == 0)
    {
        cout << "==>Khong ton tai phim co the loai ban vua nhap.";
    }
}

void xuatDSphim2(VIDEO *film, string name, int n)
{
    cout << "Cac bo phim co dien vien nam nay dong: "<<endl;
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (film[i].nameActor == name)
        {
            cout << " -" << film[i].name << endl;
            check = 1;
        }
    }
    if (check == 0)
    {
        cout << "==>Khong ton tai phim co nam dien vien vua nhap dong";
    }
}

void xuatDSphim3(VIDEO *film, string name, int n)
{
    cout << "Cac bo phim do dao dien nay dan dung: "<<endl;
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (film[i].nameDirect == name)
        {
            cout << " -" << film[i].name << endl;
            check = 1;
        }
    }
    if (check == 0)
    {
        cout << "==>Khong ton tai phim do dao dien nay dan dung";
    }
}

int main()
{

    VIDEO dsfilm[21];
    int chose = 1;
    int slfilm = 0;
    do
    {
        cout << endl << "==>Nhap lua chon: ";
        cin >> chose;
        if(chose>4||chose<1)
        {
            cout<<"Khong hop le, hay nhap ";
            continue;
        }
        switch (chose)
        {
        case 0:
            break;
        case 1:
            dsfilm[slfilm++] = nhapFilm();
            break;
        case 2:
        {
            string theLoai;
            cin.ignore(1);
            getline(cin, theLoai);
            xuatDSphim1(dsfilm, theLoai, slfilm);
            break;
        }

        case 3:
        {
            string name;
            cin.ignore(1);
            getline(cin, name);
            xuatDSphim2(dsfilm, name, slfilm);
            break;
        }
        case 4:
        {
            string nameDD;
            cin.ignore(1);
            getline(cin, nameDD);
            xuatDSphim3(dsfilm,nameDD,slfilm);

        }
        }

    } while (chose);
}