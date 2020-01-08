#ifndef CONT_CURENT_H_INCLUDED
#define CONT_CURENT_H_INCLUDED
#include "Cont_bancar.h"
#include <iostream>

using Date=std::tuple<int,int,int>;
class Cont_curent:public Cont_bancar
{
private:
    int m_nr_tranzactii_gratuite{0};
    double m_comision_retrageri{0.0};
public:
    Cont_curent(){}
    Cont_curent(const Cont_curent&);
    void depunere(double);
    void retragere_numerar(double);
    std::istream& read_commision(std::istream&,double&);
    std::istream& read_nr_tranzactii(std::istream&,int&);
    virtual std::istream& read_cont(std::istream&) override;
    virtual std::ostream& display_cont(std::ostream&)const override;
};

#endif // CONT_CURENT_H_INCLUDED
