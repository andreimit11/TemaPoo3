#include <iostream>
#include "Detinator.h"
#include "Cont_bancar.h"
#include "Cont_de_economii.h"
#include "Cont_curent.h"
#include "GestionareConturi.h"





int main()
{
    using namespace std;
    Cont_bancar **v;
    int n;
    cout<<"n="; cin>>n;
    read_n_conturi(v, n);
    display_n_conturi(v,n);
    return 0;
}
