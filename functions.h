#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "Mylib.h"


class studentas //class
{
    private:
        string vardas, pavarde;
        vector<int> paz;
        double egz;
        double gal; //paz suma
        double med;
        double lygin; //galutinis ivertis
    public:
        //setter
        void setVardas(string v) { vardas = v; }
        void setPavarde(string p) { pavarde = p; }
        void setPaz(int x);
        void clearPaz() {paz.clear(); }
        void setEgz(double x) { egz = x; }
        void setGal(double x) { gal = x; }
        void setMed(double x) { med = x; }
        void setLygin(double x) {lygin = x; }
        //getter
        inline string getVardas() const { return vardas; }
        inline string getPavarde() const { return pavarde; }
        inline vector<int> getPaz() const { return  paz; }
        inline double getEgz() const { return egz; }
        inline double getGal() const { return gal; }
        inline double getMed() const { return med; }
        inline double getLygin() const { return lygin; }
        ~studentas() {clearPaz();} //destruktorius

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