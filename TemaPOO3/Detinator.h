#ifndef DETINATOR_H_INCLUDED
#define DETINATOR_H_INCLUDED
#include <iostream>
#include <tuple>
#include <string>
#include <cctype>

using Date=std::tuple<int,int,int>;
class Detinator
{
private:
    std::string m_nume;
    std::string m_prenume;
    std::string m_numar_de_telefon;
    Date m_data_nasterii=std::make_tuple(1,1,1900);
public:
    Detinator():m_nume(""), m_prenume(""),m_numar_de_telefon("") {}
    Detinator(const Detinator&);
    void copy_date(const Date&);
    bool readFail(std::istream&);
    std::istream& readDate(std::istream&,Date&);
    bool validare_nr_tel(std::string&);
    std::istream& readNrTelefon(std::istream&,std::string&);
    friend std::istream& operator>>(std::istream&,Detinator&);
    friend std::ostream& operator<<(std::ostream&,const Detinator&);
};

#endif // DETINATOR_H_INCLUDED
