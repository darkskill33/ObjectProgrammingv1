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
        //constructor
        studentas() {
            vardas = "Skubis";
            pavarde = "Dooo";
            egz = 0;
            gal = 0;
            med = 0;
            lygin = 0;
        }

        //copy constructor
        studentas(const studentas& other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            paz = other.paz;
            egz = other.egz;
            gal = other.gal;
            med = other.med;
            lygin = other.lygin;
        }

        //move constructor
        studentas(studentas&& other) noexcept{
            vardas = std::move(other.vardas);
            pavarde = std::move(other.pavarde);
            paz = std::move(other.paz);
            egz = std::move(other.egz);
            gal = std::move(other.gal);
            med = std::move(other.med);
            lygin = std::move(other.lygin);
        }

        //copy assignment
        studentas& operator=(const studentas& sign) {

            if(this != &sign)
            {
                vardas = sign.vardas;
                pavarde = sign.pavarde;
                paz = sign.paz;
                egz = sign.egz;
                gal = sign.gal;
                med = sign.med;
                lygin = sign.lygin;
            }
            return *this;
        }

        //move assignment
        studentas& operator=(studentas&& sign) noexcept{
            if(this != &sign) {
                vardas = std::move(sign.vardas);
                pavarde = std::move(sign.pavarde);
                paz = std::move(sign.paz);
                egz = std::move(sign.egz);
                gal = std::move(sign.gal);
                med = std::move(sign.med);
                lygin = std::move(sign.lygin);
            }
            return *this;
        }



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