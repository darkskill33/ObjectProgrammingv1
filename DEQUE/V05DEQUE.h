#ifndef V05DEQUE_H_INCLUDED
#define V05DEQUE_H_INCLUDED

#include "Mylib.h"

struct studentas //struct
{
    string vardas, pavarde;
    deque<int> paz;
    double egz;
    double gal = 0;
    double med;
    double lygin;
};

bool isnumber(string str); //check if string is number;
bool equality(studentas &x, studentas &y); //bool for sorting by name;
bool grading(studentas &x, studentas &y); //bool for sorting by grades;
void mediana(studentas &temp, int n); //mediana search function;
void pild(studentas& temp); //function to insert data by hand;
void eil_po_eil(string read_vardas, studentas& temp, deque<studentas> &mas, double &laikas); //read data from file;
void generate(string pavadinimas, int size); //function for student file generating;
void skirstymas(deque<studentas> &mas, char ats, deque<studentas> &mldc, deque<studentas> &blgj, double &laikas); //sorting students to good and bad ones;
void spausd(deque<studentas> &mas, char ats, string file_name, double &laikas); //printing data to file;


#endif