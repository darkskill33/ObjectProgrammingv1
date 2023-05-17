#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "Mylib.h"
#include "vectorclass.h"

class zmogus ///base class zmogus
{
    protected:
        string vardas; ///student name
        string pavarde; /// student last name
    
    public: 

    zmogus() /// constructor
    {
        vardas = "Mike";
        pavarde = "Pukuotukas";
    }

    virtual void setVardas(string& v) { vardas = v; }
    virtual void setPavarde(string& p) { pavarde = p; }
    virtual void randominfo() = 0;

    virtual ~zmogus() {};

};

class studentas : public zmogus ///derived class studentas
{
    private:
        vector<int> paz; ///grades
        double egz; ///exam grade
        double gal; ///grade sum
        double med; ///median
        double lygin;/// final grade

    public:
        
        studentas() : zmogus() { ///constructor
            setVardas("Skubis");
            pavarde = "Doo";
            egz = 0;
            gal = 0;
            med = 0;
            lygin = 0;
        }

        
        studentas(const studentas& other) {///copy constructor
            vardas = other.vardas;
            pavarde = other.pavarde;
            paz = other.paz;
            egz = other.egz;
            gal = other.gal;
            med = other.med;
            lygin = other.lygin;
        }

       
        studentas(studentas&& other) noexcept{ ///move constructor
            vardas = other.vardas;
            pavarde = other.pavarde;
            paz = std::move(other.paz);
            egz = other.egz;
            gal = other.gal;
            med = other.med;
            lygin = other.lygin;
            
            
            other.vardas = "";
            other.pavarde = "";
            other.egz = 0;
            other.gal = 0;
            other.med = 0;
            other.lygin = 0;

        }

        
        studentas& operator=(const studentas& sign) {///copy assignment
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

        
        studentas& operator=(studentas&& sign) noexcept{///move assignment
            if(this != &sign) {
                vardas = std::move(sign.vardas);
                pavarde = std::move(sign.pavarde);
                paz = std::move(sign.paz);
                std::swap(egz, sign.egz);
                gal = std::move(sign.gal);
                med = std::move(sign.med);
                lygin = std::move(sign.lygin);
                sign.~studentas();
            }
            return *this;
        }

        ///input operator
	    friend istream &operator>>(istream& input, studentas& studentas ) { 
        input >> studentas.vardas >> studentas.pavarde >> studentas.egz;
        return input;
        }            

        ///output operator
        friend ostream &operator<<(ostream& output, const studentas& studentas) { 
        output << studentas.vardas<< " " << studentas.pavarde << " " << studentas.egz;
        return output;
      }


    
        void setVardas(string v) { vardas = v; } ///setter
        void setPavarde(string p) { pavarde = p; } ///setter
        void setPaz(int x); ///setter
        void clearPaz() {paz.clear(); } ///setter
        void setEgz(double x) { egz = x; } ///setter
        void setGal(double x) { gal = x; } ///setter
        void setMed(double x) { med = x; } ///setter
        void setLygin(double x) {lygin = x; } ///setter

        inline string getVardas() const { return vardas; } ///getter
        inline string getPavarde() const { return pavarde; } ///getter
        inline vector<int> getPaz() const { return  paz; } ///getter
        inline double getEgz() const { return egz; } ///getter
        inline double getGal() const { return gal; } ///getter
        inline double getMed() const { return med; } ///getter
        inline double getLygin() const { return lygin; } ///getter


        void randominfo() ///random info about student
        {
            cout << getPavarde() << " " << getVardas() << " " << getEgz() << endl;
        }

        ~studentas() {clearPaz();} ///destructor

};

bool isnumber(string str); ///check if string is number;
bool equality(studentas &x, studentas &y); ///bool for sorting by name;
bool grading(studentas &x, studentas &y); ///bool for sorting by grades;
bool lowerthanfive(studentas &x); ///bool for sorting students;
bool greaterthanfive(studentas &x); ///bool for sorting students;
void mediana(studentas &temp, int n); ///mediana search function;
void pild(studentas& temp); ///function to insert data by hand;
void eil_po_eil(string read_vardas, studentas& temp, vectorclass<studentas> &mas, double &laikas); ///read data from file;
void generate(string pavadinimas, int size); ///function for student file generating;
void skirstymas(vectorclass<studentas> &mas, char ats, vectorclass<studentas> &blgj, double &laikas); ///sorting students to good and bad ones;
void spausd(vectorclass<studentas> &mas, char ats, string file_name, double &laikas); ///printing data to file;

#endif