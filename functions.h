#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "Mylib.h"

class zmogus
{
    protected:
        string vardas, pavarde;
    
    public: 

    zmogus()
    {
        vardas = "Mike";
        pavarde = "Pukuotukas";
    }

    virtual void setVardas(string& v) { vardas = v; }
    virtual void setPavarde(string& p) { pavarde = p; }
    virtual void setPaz(int x) = 0;

    virtual ~zmogus() {};

};

class studentas : public zmogus//class
{
    private:
        vector<int> paz;
        double egz;
        double gal; //paz suma
        double med;
        double lygin; //galutinis ivertis

    public:
        //constructor
        studentas() : zmogus() {
            setVardas("Skubis");
            pavarde = "Doo";
            egz = 0;
            gal = 0;
            med = 0;
            lygin = 0;
        }

        //copy constructor
        studentas(const studentas& other) {
            cout << "COPY CONSTRUCTOR" << endl;
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
            cout << "MOVE CONSTRUCTOR" << endl;
            vardas = other.vardas;
            pavarde = other.pavarde;
            paz = std::move(other.paz);
            egz = other.egz;
            gal = other.gal;
            med = other.med;
            lygin = other.lygin;
            other.~studentas();
        }

        //copy assignment
        studentas& operator=(const studentas& sign) {
            cout << "copy assignment" << endl;
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
            cout << "move assignment" << endl;
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

        //input operator
	    friend istream &operator>>(istream& input, studentas& studentas ) { 
        input >> studentas.vardas >> studentas.pavarde >> studentas.egz;
        return input;
        }            

        //output operator
        friend ostream &operator<<(ostream& output, const studentas& studentas) { 
        output << studentas.vardas<< " " << studentas.pavarde << " " << studentas.egz;
        return output;
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