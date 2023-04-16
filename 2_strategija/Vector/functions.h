#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "Mylib.h"

struct studentas //struct
{
    string vardas, pavarde;
    vector<int> paz;
    double egz;
    double gal;
    double med;
    double lygin;
};

bool isnumber(string str); //check if string is number;
bool equality(studentas &x, studentas &y); //bool for sorting by name;
bool grading(studentas &x, studentas &y); //bool for sorting by grades;
bool lowerthanfive(studentas &x); //bool for sorting students;
bool greaterthanfive(studentas &x); //bool for sorting students;
void mediana(studentas &temp, int n); //mediana search function;
void pild(studentas& temp); //function to insert data by hand;
void eil_po_eil(string read_vardas, studentas& temp, vector<studentas> &mas, double &laikas); //read data from file;
void generate(string pavadinimas, int size); //function for student file generating;
void skirstymas(vector<studentas> &mas, char ats, vector<studentas> &blgj, double &laikas); //sorting students to good and bad ones;
void spausd(vector<studentas> &mas, char ats, string file_name, double &laikas); //printing data to file;

#endif