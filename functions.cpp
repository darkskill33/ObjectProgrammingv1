#include "functions.h"

bool isnumber(string str) //check if string is number;
{
    for(int i = 0; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

bool equality(studentas &x, studentas &y)
{
    if(x.getPavarde() == y.getPavarde()) 
    {
        return x.getPavarde() < y.getPavarde();
    } else return x.getVardas() < y.getVardas();
}

bool grading(studentas &x, studentas &y)
{
    return x.getLygin() > y.getLygin();
}

bool lowerthanfive(studentas &x)
{
    return x.getLygin() < 5;
}

bool greaterthanfive(studentas &x)
{
    return x.getLygin() > 5;
}

void studentas::setPaz(int x)
{
    paz.reserve(paz.size()+1);
    paz.push_back(x); 
}

void mediana(studentas &temp, int n) //mediana search function;
{
    
    vector<int> kopija_paz = temp.getPaz();
    sort(kopija_paz.begin(), kopija_paz.end()); //sorting grades (descending);
    float mid1, mid2;
    if(n == 2*(n/2))
    {
        mid1 = kopija_paz[n/2 - 1];
        mid2 = kopija_paz[n/2];
        temp.setMed((mid1+mid2)/2);
    } 
    else 
    {
        mid1 = kopija_paz[n/2 - 1];
        temp.setMed(mid1);
    }
}

void pild(studentas& temp) //function to insert data by hand;
{
    string a, b;
    cout << "Iveskite varda ir pavarde: "; cin >> a >> b;
    temp.setVardas(a);
    temp.setPavarde(b);
    char pas;
    cout << "Jei norite atsitiktinai sugeneruoti pažymius ir egzamino rezultatą, įveskite (k), jei duomenis įvesite pats, įveskite (s): " << endl;
    do
    {
        cin >> pas;
    } while (pas != 's' && pas != 'S' && pas != 'k' && pas != 'K' );

    string check;
    if (pas == 's' || pas == 'S')
    {
        cout << "Iveskite pazymius (norint nebevesti pažymiu rašykite: '0' ): ";
        while(true)
        {
            cin >> check;
            if(!isnumber(check)) 
            {
                cout << "Iveskite SKAICIU [1; 10] be simboliu ar raidziu. Į intervalą nepatenkantys skaičiai nebus apdorojami" << endl;
                continue;
            }

            int check_nd = stoi(check);
        
            if(check_nd == 0)
            {
                if(temp.getPaz().size() == 0)
                {
                    temp.setPaz(check_nd);
                    break;
                } else break;
            } else if(check_nd > 0 && check_nd <=10)
                    {
                        temp.setPaz(check_nd);
                    } else if(check_nd < 0 || check_nd > 10)
                        {
                            cout << "Iveskite SKAICIU intervale [1; 10]: " << endl;
                            continue;
                        }
        }

        cout << "Iveskite egzamino paz.: ";
        while(true)
        {
            cin >> check;
            if(!isnumber(check)) 
            {
                cout << "Iveskite SKAICIU [1; 10] be simboliu ar raidziu. Į intervalą nepatenkantys skaičiai nebus abdorojami" << endl;
                continue;
            }

            int check_nd = stoi(check);
            if(check_nd > 0 && check_nd <=10)
                {
                    temp.setEgz(check_nd);
                } else if(check_nd < 0 || check_nd > 10)
                        {
                            cout << "Iveskite SKAICIU intervale: [1; 10]" << endl;
                            continue;
                        }
            break;
        }

    } else if(pas == 'k' || pas == 'K')
        { 
            cout << "Generuojami pažymiai: " << endl;
            srand(time(0));
            int a = (rand()%10)+1; //generating amount of random numbers
            for (int i = 0; i < a; i++)
            {
                int c = (rand()%10)+1; //generating random numbers;
                cout << c << " ";
                temp.setPaz(c);
            }
            cout << endl;
            cout << "Generuojamas egzamino pažymys: " << endl;
            int c = (rand()%10)+1; //generating random exam grade;
            cout << c << endl;
            temp.setEgz(c);
        } 
}

void eil_po_eil(string read_vardas, studentas& temp, vector<studentas> &mas, double &laikas) //read data from file;
{
    string eil, zod, skaic;
    int times;
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    ifstream open_f; //(read_vardas)
    try
    {
        open_f.open(read_vardas);
        if(open_f.fail())
        throw read_vardas;
    }
    catch(string pvd)
    {
        cout << "Nerastas failas: " << pvd << endl;
        cout << "Paleiskite programa is naujo pasitikrine, ar egzistuoja toks failas Jūsų direktorijoje.." << endl;
        exit(0);
    }
 
    getline(open_f, eil);
    times = count(eil.begin(), eil.end(), 'N'); //counting a number of homework;
    while (open_f)
    { 
      if (!open_f.eof()) 
        {
            string zodis;
            open_f >> zodis;
            temp.setVardas(zodis);
            open_f >> zodis;
            temp.setPavarde(zodis);
            temp.setGal(0);
            int gal = 0;
            for(int i = 0; i < times; i++)
            {
                int a;
                open_f >> a;
                temp.setPaz(a);
                gal += a;
            }
            temp.setGal(gal);
            int a;
            open_f >> a; 
            temp.setEgz(a);
            mas.push_back(temp);
            temp.clearPaz();
        }   else break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Failo nuskaitymas užtruko: "<< diff.count() << " s." << endl;   
    laikas += diff.count();
}

void generate(string pavadinimas, int size)
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    ofstream fs (pavadinimas);
    srand(time(0));
    int pazym_sk = (rand()%20)+1; //generating random homework grades number. NOW ITS [1; 20];
    //(start) Creating top line (vardas pavarde ND* Egz.);
    fs  << left << setw(16) << "Vardas"  << left << setw(14) << "Pavarde" << left << setw(20) << " ";
    for(int i = 1; i <= pazym_sk; i++)
    {
        fs << left << setw(10) << ("ND" + std::to_string(i));
    }
    fs << left << setw(10) << "Egz." << endl;
    //(finish) Creating top line (vardas pavarde ND* Egz.);

    //Generating student names and grades;
    for(int i = 1; i <= size; i++)
    {
        fs  << left << setw(16) << ("Vardas" + std::to_string(i))  << left << setw(14) << ("Pavarde" + std::to_string(i)) << left << setw(20) << " ";
        
        for(int j = 0; j < pazym_sk; j++)
        {
            fs << left << setw(10) << (rand()%10)+1; //generating random grades;
        }
        fs << left << setw(10) << (rand()%10)+1 << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Failo generavimas užtruko: "<< diff.count() << " s." << endl; 
}

void skirstymas(vector<studentas> &mas, char ats, vector<studentas> &blgj, double &laikas) //sorting students to good and bad ones;
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;

    for(auto &k : mas)
    {
        if (ats == 'G' || ats == 'g')
        {
            double kint = (0.4*k.getGal()/(double)k.getPaz().size() +  k.getEgz()*0.6);
            k.setLygin(kint);
        }

        if(ats == 'M' || ats == 'm')
        {
            mediana(k, k.getPaz().size());
            double kint = (0.4*k.getMed() + k.getEgz()*0.6);
            k.setLygin(kint);
        }         
    }
    
    remove_copy_if(mas.begin(), mas.end(), std::back_inserter(blgj), greaterthanfive); 
    mas.erase(remove_if(mas.begin(), mas.end(), lowerthanfive), mas.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Failo suskirstymas į vargšus ir šaunuolius užtruko: "<< diff.count() << " s." << endl;
    laikas += diff.count();
    
    sort(mas.begin(), mas.end(), grading);
    sort(blgj.begin(), blgj.end(), grading);
}

void spausd(vector<studentas> &mas, char ats, string file_name, double &laikas) //printing data to file;
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    ofstream fr (file_name);
    fr << "------------------------------------------------------------------------------" <<endl;
    fr << left << setw(16) << "Vardas"  << left << setw(25) << "Pavardė " << left << setw(20)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
    fr << "------------------------------------------------------------------------------" <<endl;
    string skirt = " - ";
    for(auto &k : mas)
    {
        if (ats == 'G' || ats == 'g')
        {
            char eilut[100];
            sprintf(eilut, "%-16s%-25s%-20.2lf%-5s\n", k.getVardas().c_str(), k.getPavarde().c_str(), k.getLygin(), skirt.c_str());
            fr << eilut;
        }

        if(ats == 'M' || ats == 'm')
        {
            char eilut[100];
            sprintf(eilut, "%-16s%-25s%-20s%-5.2lf\n", k.getVardas().c_str(), k.getPavarde().c_str(), skirt.c_str(), k.getLygin());
            fr << eilut;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Grupės " << file_name << " išvedimas į failą užtruko: "<< diff.count() << " s." << endl;  
    laikas += diff.count();
   
}