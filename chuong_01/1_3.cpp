#include<iostream>
using namespace std;

struct TIME 
{
    int gio,phut,giay;
};

void nhap(TIME &time)
{
    cin>>time.gio>>time.phut>>time.giay;
}

int ktraTime(TIME time)
{
    if(time.gio >=0&&time.gio <24 &&time.phut>=0 &&time.phut <60 && time.giay >=0 &&time.giay < 60) return 1;
    return 0;
}

void xuat(TIME time)
{
    cout<<time.gio<<":"<<time.phut<<":"<<time.giay;
}

TIME distime(TIME time1,TIME time2)
{   

    int Giay = 0;
    TIME disTime ;
    Giay =  time2.gio*3600 + time2.phut*60 + time2.giay 
    -(time1.gio*3600 + time1.phut*60 + time1.giay);
    if(Giay<0){
        Giay = -Giay;
    }
    disTime.gio = Giay/3600;
    Giay = Giay - (Giay/3600)*3600;
    disTime.phut = Giay/60;
    Giay = Giay - (Giay/60)*60;
    disTime.giay = Giay;
    return disTime;
}

int main()
{
    TIME time1,time2;
    cout<<"Nhap gio/phut/giay: ";
    nhap(time1);
    if(!ktraTime(time1))
    {
        cout<<"Thoi  gian ban nhap khong hop le, hay nhap lai.";
        return 0;
    }
    cout<<"Gio/phut/giay ban da nhap :";
    xuat(time1);
    cout<<endl<<"Nhap gio/phut/giay: ";
    nhap(time2);
    if(!ktraTime(time2))
    {
        cout<<"Thoi  gian ban nhap khong hop le, hay nhap lai.";
        return 0;
    }
    cout<<"Thoi gian giua hai moc thoi gian da nhap: ";
    cout<<distime(time1,time2).gio<<":"<<distime(time1,time2).phut<<":"<<distime(time1,time2).giay;
}
