#ifndef CONT_DE_ECONOMII_H_INCLUDED
#define CONT_DE_ECONOMII_H_INCLUDED
#include "Cont_bancar.h"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <ctime>


using Date=std::tuple<int,int,int>;
class Cont_de_economii:public Cont_bancar
{
private:
    std::vector<std::pair<Date, double>> m_istoric_sold;
    double m_rata_dobanzii{0.1};
    std::string m_tipul_dobanzii;
public:
    Cont_de_economii(){}
    Cont_de_economii(const Cont_de_economii&);
    std::string get_tipul_dobanzii() { return m_tipul_dobanzii; }
    std::istream& read_rata_dobanzii(std::istream&,double&);
    std::istream& read_tipul_dobanzii(std::istream&,std::string&);
    int getCurrentYear()const;
    double getDobanda()const; // calculeaza dobanda simpla
    void depunere(double);

    virtual std::istream& read_cont(std::istream&) override;
    virtual std::ostream& display_cont(std::ostream&)const override;

};

#endif // CONT_DE_ECONOMII_H_INCLUDED
