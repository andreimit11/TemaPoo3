#include "Cont_curent.h"

Cont_curent::Cont_curent(const Cont_curent&cont)
{
    m_detinator=cont.m_detinator;
    copy_date(cont.m_data_deschiderii);
    m_sold=cont.m_sold;
    m_nr_tranzactii_gratuite=cont.m_nr_tranzactii_gratuite;
    m_comision_retrageri=cont.m_comision_retrageri;
}

void Cont_curent::depunere(double val)
{
    m_sold+=val;
}
void Cont_curent::retragere_numerar(double val)
{
    try
    {
        if((m_sold < val) || (m_nr_tranzactii_gratuite==0 && m_sold <(val+m_comision_retrageri*val) ))
            throw "fonduri insuficiente";
        if(m_nr_tranzactii_gratuite > 0)
        {
            m_sold-=val;
            m_nr_tranzactii_gratuite--;
        }
        else
        if(m_nr_tranzactii_gratuite==0)
        {
            m_sold-=(val+m_comision_retrageri*val);
        }
    }
    catch(const char*eror)
    {
        std::cout<<"\nError: "<<eror<<'\n';
    }
}
std::istream& Cont_curent::read_commision(std::istream&in,double&comision)
{
    using namespace std;
    in.clear();
    in.ignore(32767, '\n');
    while(1)
    {
        std::cout<<"\nValoare comision la retrageri( nr subunitar ): ";
        in>>comision;
        if(readFail(in))
        {
            continue;
        }
        if(comision<0 || comision>=1)
        {
            continue;
        }
        break;
    }
    return in;
}
std::istream& Cont_curent::read_nr_tranzactii(std::istream&in,int&nr)
{
    using namespace std;
    in.clear();
    in.ignore(32767, '\n');
    while(1)
    {
        std::cout<<"\nIntrodu nr tranzactii gratuite: ";
        in>>nr;
        if(readFail(in))
        {
            continue;
        }
        if(nr<0)
        {
            continue;
        }
        break;
    }
    return in;
}
std::istream& Cont_curent::read_cont(std::istream&in)
{
    std::cout<<"\nTitularul contului:\n";
    in>>m_detinator;
    read_date(in,m_data_deschiderii);
    read_sold(in,m_sold);
    read_nr_tranzactii(in,m_nr_tranzactii_gratuite);
    read_commision(in,m_comision_retrageri);
    return in;
}
std::ostream& Cont_curent::display_cont(std::ostream&out)const
{
    using namespace std;
    out<<"\nTitularul contului: \n"<<m_detinator<<'\n'<<"Data deschiderii: "<<get<0>(m_data_deschiderii)<<' '
        <<get<1>(m_data_deschiderii)<<' '<<get<2>(m_data_deschiderii)<<'\n'<<"Sold: "<<m_sold<<'\n'
        <<"Nr tranzactii gratuite: "<<m_nr_tranzactii_gratuite<<"\nComision retrageri: "<<m_comision_retrageri<<'\n';
    return out;
}
