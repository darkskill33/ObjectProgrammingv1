#ifndef V03VEC_H_INCLUDED
#define V03VEC_H_INCLUDED


#include "Mylib.h"


struct studentas //struct
{
    string vardas, pavarde;
    vector<int> paz;
    double egz;
    double gal;
    double med;
};

bool isnumber(string str); //check if string is number;
bool equality(studentas &x, studentas &y);
void mediana(studentas &temp, int n);
void pild(studentas& temp);
void eil_po_eil(string read_vardas, studentas& temp, vector<studentas> &mas);
void spausd(vector<studentas> &mas, char ats);

#endif 