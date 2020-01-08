#include "Cont_de_economii.h"
#include <iostream>

Cont_de_economii::Cont_de_economii(const Cont_de_economii&cont)
{
    using namespace std;
    m_detinator=cont.m_detinator;
    copy_date(cont.m_data_deschiderii);
    m_sold=cont.m_sold;
    m_rata_dobanzii=cont.m_rata_dobanzii;
    m_tipul_dobanzii=cont.m_tipul_dobanzii;
}

void Cont_de_economii::depunere(double val)
{
    using namespace std;
    time_t t=time(nullptr);
    tm *time_Ptr=localtime(&t);
    m_sold+=val;
    Date current_date=make_tuple(time_Ptr->tm_mday, time_Ptr->tm_mon+1, time_Ptr->tm_year+1900);
    m_istoric_sold.push_back(make_pair(current_date, m_sold));
}
int Cont_de_economii::getCurrentYear()const
{
    time_t t=time(nullptr);
    tm *time_Ptr=localtime(&t);
    int year=time_Ptr->tm_year+1900; // current year
    return year;
}
double Cont_de_economii::getDobanda()const
{
    using namespace std;
    int n=getCurrentYear()-( get<2>(m_data_deschiderii) ); // durata contului in ani
    double dobanda_simpla=m_sold*m_rata_dobanzii*n;
    return dobanda_simpla;
}
std::istream& Cont_de_economii::read_rata_dobanzii(std::istream&in,double&dobanda)
{
    using namespace std;
    in.clear();
    in.ignore(32767, '\n');
    while(1)
    {
        cout<<"\nIntrodu rata dobanzii ( nr subunitar ): ";
        in>>dobanda;
        if(readFail(in))
        {
            continue;
        }
        if(dobanda<0 || dobanda>=1)
        {
            continue;
        }
        break;
    }
    return in;
}
std::istream& Cont_de_economii::read_tipul_dobanzii(std::istream&in,std::string&tip_dobanda)
{
    using namespace std;
    in.clear();
    in.ignore(32767, '\n');
    int op{0};
    while(1)
    {
        cout<<"\nSelecteaza tipul dobanzii: \n1->pe 3 luni\n2->pe 6 luni\n3->pe 1 an\noptiune: ";
        in>>op;
        if(readFail(in))
        {
            continue;
        }
        if( (op!=1) && (op!=2) && (op!=3 ))
        {
            continue;
        }
        if(op==1) { tip_dobanda="3 luni"; }
        if(op==2) { tip_dobanda="6 luni"; }
        if(op==3) { tip_dobanda="1 an"; }
        break;
    }
    return in;
}
std::istream& Cont_de_economii::read_cont(std::istream&in)
{
    std::cout<<"\nTitularul contului:\n";
    in>>m_detinator;
    read_date(in,m_data_deschiderii);
    read_sold(in,m_sold);
    read_tipul_dobanzii(in,m_tipul_dobanzii);
    read_rata_dobanzii(in,m_rata_dobanzii);
    m_istoric_sold.push_back(make_pair(m_data_deschiderii, m_sold));
    return in;
}
std::ostream& Cont_de_economii::display_cont(std::ostream&out)const
{
    using namespace std;
    out<<"\nTitularul contului: \n"<<m_detinator<<'\n'<<"Data deschiderii: "<<get<0>(m_data_deschiderii)<<' '
        <<get<1>(m_data_deschiderii)<<' '<<get<2>(m_data_deschiderii)<<'\n';
    out<<"Sold: "<<m_sold<<'\n'<<"Rata dobanzii: "<<m_rata_dobanzii<<' '
        <<"( pe "<<m_tipul_dobanzii<<" )\n"<<"Valoarea curenta a dobanzii: "<<getDobanda()<<'\n';
    out<<"\nIstoric actualizare sold \n";
    for(const auto&it:m_istoric_sold)
    {
       out<<"Actualizare sold: "<<it.second<<" ( in data de "<<get<0>(it.first)<<' '<<get<1>(it.first)<<' '<<get<2>(it.first)<<" )\n";
    }
    return out;
}
