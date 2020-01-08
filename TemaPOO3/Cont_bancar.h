#ifndef CONT_BANCAR_H_INCLUDED
#define CONT_BANCAR_H_INCLUDED
#include "Detinator.h"
#include <iostream>
#include <tuple>

using Date=std::tuple<int,int,int>;
class Cont_bancar
{
protected:
    Detinator m_detinator;
    Date m_data_deschiderii;
    double m_sold{0.0};
public:
    void copy_date(const Date&);
    bool readFail(std::istream&);
    std::istream& read_date(std::istream&,Date&);
    std::istream& read_sold(std::istream&,double&);

    virtual std::istream& read_cont(std::istream&)=0;
    virtual std::ostream& display_cont(std::ostream&)const=0;
    friend std::istream& operator>>(std::istream&,Cont_bancar&);
    friend std::ostream& operator<<(std::ostream&,Cont_bancar&);
};

void read_n_conturi(Cont_bancar**&v,int n);
void display_n_conturi(Cont_bancar**v,int n);

#endif // CONT_BANCAR_H_INCLUDED
