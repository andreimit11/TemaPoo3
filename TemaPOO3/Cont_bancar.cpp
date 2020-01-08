#include "Cont_bancar.h"
#include "Cont_de_economii.h"
#include "Cont_curent.h"
#include <iostream>

void read_n_conturi(Cont_bancar**&v,int n)
{
    using namespace std;
    if(n<1)
        return;
    v=new Cont_bancar*[n];
    string op;
    for(int i=0; i<n; i++)
    {
        cout<<"Give the tipe of the account(1->cont curent/2->cont_de_economii): ";
        cin>>op;
        try
        {
            if(op!="1" && op!="2")
            {
                v[i]=nullptr;
                throw -1;
            }
            if(op=="1")
            {
                v[i]=new Cont_curent;
                cin>>*dynamic_cast<Cont_curent*>(v[i]);
            }
            if(op=="2")
            {
                v[i]=new Cont_de_economii;
                cin>>*dynamic_cast<Cont_de_economii*>(v[i]);
            }
        }
        catch(int x)
        {
            cout<<"Invalid account type\n";
            return;
        }
    }
}

void display_n_conturi(Cont_bancar**v,int n)
{
    using namespace std;
    if(v==nullptr || v[0]==nullptr)
        return;
    cout<<"Afisare conturi bancare: \n";
    for(int i=0; i<n; i++)
    {
        try
        {
            if((dynamic_cast<Cont_curent*>(v[i])==nullptr) && (dynamic_cast<Cont_de_economii*>(v[i])==nullptr))
                throw -1;
            if(dynamic_cast<Cont_curent*>(v[i]))
            {
                cout<<"\nCont "<<i+1<<": Cont curent\n";
                cout<<*dynamic_cast<Cont_curent*>(v[i]);
            }
            else if(dynamic_cast<Cont_de_economii*>(v[i]))
            {
                cout<<"\nCont "<<i+1<<": Cont de economii\n";
                cout<<*dynamic_cast<Cont_de_economii*>(v[i]);
            }
        }
        catch(int x)
        {
            return;
        }
    }
}

void Cont_bancar::copy_date(const Date&data)
{
    using namespace std;
    get<0>(m_data_deschiderii)=get<0>(data);
    get<1>(m_data_deschiderii)=get<1>(data);
    get<2>(m_data_deschiderii)=get<2>(data);
}

bool Cont_bancar::readFail(std::istream&in)
{
    if(in.fail())
    {
        in.clear();
        in.ignore(32767, '\n');
        return true;
    }
    return false;
}
std::istream& Cont_bancar::read_date(std::istream&in,Date&data)
{
    using namespace std;
    in.clear();
    int zi, luna, an;
    while(1)
    {
        cout<<"\nIntrodu data deschiderii contului. \n";
        std::cout<<"zi: ";
        in>>zi;
        std::cout<<"luna: ";
        in>>luna;
        std::cout<<"an: ";
        in>>an;
        if(readFail(in))
        {
            continue;
        }
        if(zi<0|| zi>31 || luna<=0 || luna>12 ||an<1900 || an>2020)
        {
            continue;
        }
        data=make_tuple(zi,luna,an);
        break;
    }
    return in;
}
std::istream& Cont_bancar::read_sold(std::istream&in,double&sold)
{
    using namespace std;
    in.clear();
    in.ignore(32767, '\n');
    while(1)
    {
        cout<<"\nIntrodu soldul curent: ";
        in>>sold;
        if(readFail(in))
        {
            continue;
        }
        break;
    }
    return in;
}
std::istream& operator>>(std::istream&in,Cont_bancar&cont)
{
    return cont.read_cont(in);
}
std::ostream& operator<<(std::ostream&out,Cont_bancar&cont)
{
    return cont.display_cont(out);
}
