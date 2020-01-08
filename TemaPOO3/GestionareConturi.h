#ifndef GESTIONARECONTURI_H_INCLUDED
#define GESTIONARECONTURI_H_INCLUDED
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Cont_de_economii.h"
using namespace std;

template <class T>
class GestionareConturi;
template <class T>
ostream& operator<<(ostream&,GestionareConturi<T>&);

template <class T>
class GestionareConturi
{
private:
    int m_index_cont{0};
    T tip_cont;
    unordered_map<int, T> operatii_cont;
public:
    GestionareConturi()
    {
    }
    GestionareConturi& operator+=(T&);
    friend ostream& operator<<<>(ostream&, GestionareConturi&);
};
template <class T>
GestionareConturi<T>& GestionareConturi<T>::operator+=(T&cont)
{
    m_index_cont++;
    operatii_cont[m_index_cont]=cont;
    return *this;
}
template <class T>
ostream& operator<<(ostream&out, GestionareConturi<T>&g)
{
    for(auto&it:g.operatii_cont)
    {
        out<<"\nCont_id: "<<(it.first)<<(it.second)<<'\n';
    }
    return out;
}

// Specializare a clasei template
template <>
class GestionareConturi<Cont_de_economii>
{
private:
    int m_index_cont{0};
    Cont_de_economii tip_cont;
    unordered_map<int, Cont_de_economii> operatii_cont;
public:
    GestionareConturi()
    {
    }
    GestionareConturi operator+=(Cont_de_economii&cont)
    {
        m_index_cont++;
        operatii_cont[m_index_cont]=cont;
        return *this;
    }
    friend ostream& operator<<<>(ostream&, GestionareConturi&);
};



#endif // GESTIONARECONTURI_H_INCLUDED
