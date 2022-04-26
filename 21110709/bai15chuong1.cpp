#include <iostream>
#include<string>
using namespace std;

struct SACH
{
    string MaSach;
    string TenSach;
    string TacGia;
    string SL;
};

SACH inBook()
{
    SACH book;
    cout<<endl<<"Ma sach: ";
    getline(cin, book.MaSach);
    cout<<endl<<"Ten Sach: ";
    getline(cin,book.TenSach);
    cout<<endl<<"Tac Gia: ";
    getline(cin,book.TacGia);
    cout<<"So luong: ";
    cin>>book.SL;
    return book;
}

void outBook(SACH book)
{
    cout<<endl<<"Ma sach: "<<book.MaSach<<endl;
    cout<<"Ten sach: "<<book.TenSach<<endl;
    cout<<"Tac gia: "<<book.TacGia<<endl;
    cout<<"So luong: "<<book.SL<<endl;
    cout<<"--------------------------------------"<<endl;
}

void FindBook(SACH *book,int slBook)
{   
    cin.ignore(1);
    cout<<endl<<"--->Nhap ten sach: ";
    string nameBook;
    getline(cin,nameBook);
    cout<<endl<<"---------------------Ket qua tim kiem---------------------"<<endl;
    int check = 0;
    for(int i = 0;i<slBook;i++)
    {   
        if(book[i].TenSach == nameBook)
        {
            outBook(book[i]);
            check = 1;                      
        }
    }

    if(check == 0)
    {
        cout<<"Khong co cuon sach nao duoc tim thay (X_x)";
    }

}

int main()
{
    int slBook = 0;
    SACH listBook[100];
    int chose = 0;
    do
    {   
        cout<<endl<<"[1]-Them mot dau sach."<<endl;
        cout<<"[2]-Tim kiem."<<endl;
        cout<<"[3]-Cap nhat so luong sach."<<endl;
        cout<<"[0]-ket thuc."<<endl;
        cin >> chose;
        switch (chose)
        {
        case 0:
        {   
            break;
        }
        case 1:
        {
            cout<<"Them mot dau sach: ";
            cin.ignore(1);
            listBook[slBook++] = inBook();
            break;
        }
        case 2:
        {
            cout<<endl<<"Tim kiem: ";
            FindBook(listBook,slBook);
            break;
        }
        case 3:
        {
            cout<<endl<<" ====>Tong so luong sach trong thu vien: "<<slBook;
            break;
        }
        }
    } while (chose);
}