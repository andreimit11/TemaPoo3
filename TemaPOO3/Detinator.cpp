#include "Detinator.h"
#include <iostream>

void Detinator::copy_date(const Date&data)
{
    using namespace std;
    get<0>(m_data_nasterii)=get<0>(data);
    get<1>(m_data_nasterii)=get<1>(data);
    get<2>(m_data_nasterii)=get<2>(data);
}
Detinator::Detinator(const Detinator&d)
{
    m_nume=d.m_nume;
    m_prenume=d.m_prenume;
    m_numar_de_telefon=d.m_numar_de_telefon;
    copy_date(d.m_data_nasterii);
}
bool Detinator::readFail(std::istream&in)
{
    if(in.fail())
    {
        in.clear();
        in.ignore(32767, '\n');
        return true;
    }
    return false;
}
std::istream& Detinator::readDate(std::istream&in,Date&data)
{
    using namespace std;
    in.clear();
    in.ignore(32767, '\n');
    int zi, luna, an;
    while(1)
    {
        cout<<"\nIntrodu data nasterii: \n";
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
bool Detinator::validare_nr_tel(std::string&nr_tel)
{
    if(nr_tel.length()!=12)// +SPACES
    {
        return false;
    }
    int n=nr_tel.length();
    for(int i=0; i<n; ++i)
    {
        if(isdigit(nr_tel[i]))
            continue;
        if(isspace(nr_tel[i]))
        {
            continue;
        }
        return false;
    }
    return true;
}
std::istream& Detinator::readNrTelefon(std::istream&in,std::string&nr_tel)
{
    using namespace std;
    in.clear();
    in.ignore(32767, '\n');
    while(1)
    {
        cout<<"Introdu nr de telefon +4(#### ### ### ): ";
        getline(in, nr_tel);
        if(validare_nr_tel(nr_tel))
        {
            break;
        }
        std::cout<<"Nr de telefon trebuie sa contina numai cifre ( 10 cifre , fara prefix)\n";
    }
    return in;
}
std::istream& operator>>(std::istream&in,Detinator&detinator)
{
    std::cout<<"Nume: ";
    in>>detinator.m_nume;
    std::cout<<"Prenume: ";
    in>>detinator.m_prenume;
    detinator.readDate(in, detinator.m_data_nasterii);
    detinator.readNrTelefon(in, detinator.m_numar_de_telefon);
    return in;
}
std::ostream& operator<<(std::ostream&out,const Detinator&detinator)
{
    using namespace std;
    out<<"Nume : "<<detinator.m_nume<<"\nPrenume: "<<detinator.m_prenume<<'\n';
    out<<"Data nasterii: "<<get<0>(detinator.m_data_nasterii)<<' '
        <<get<1>(detinator.m_data_nasterii)<<' '<<get<2>(detinator.m_data_nasterii)<<'\n';
    out<<"Nr telefon: "<<detinator.m_numar_de_telefon<<'\n';
    return out;
}
