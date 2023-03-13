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
    if(x.pavarde == y.pavarde) 
    {
        return x.pavarde < y.pavarde;
    } else return x.vardas < y.vardas;
}


bool grading(studentas &x, studentas &y)
{
    return x.lygin > y.lygin;
}

void mediana(studentas &temp, int n) //mediana search function;
{
    sort(temp.paz.begin(), temp.paz.end()); //sorting grades (descending);
    float mid1, mid2;
    if(n == 2*(n/2))
    {
        mid1 = temp.paz[n/2 - 1];
        mid2 = temp.paz[n/2];
        temp.med = (mid1+mid2)/2;
    } 
    else 
    {
        mid1 = temp.paz[n/2];
        temp.med = mid1;
    }
}

void pild(studentas& temp) //function to insert data by hand;
{
    cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;
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
                if(temp.paz.size() == 0)
                {
                    temp.paz.push_back(check_nd);
                    break;
                } else break;
            } else if(check_nd > 0 && check_nd <=10)
                    {
                        temp.paz.push_back(check_nd);
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
                    temp.egz = check_nd;
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
                temp.paz.push_back(c);
            }
            cout << endl;
            cout << "Generuojamas egzamino pažymys: " << endl;
            int c = (rand()%10)+1; //generating random exam grade;
            cout << c << endl;
            temp.egz = c;
        } 
}

void eil_po_eil(string read_vardas, studentas& temp, vector<studentas> &mas, double laikas) //read data from file;
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
        cout << "Nėrastas failas: " << pvd << endl;
        cout << "Paleiskite programa is naujo pasitikrine, ar egzistuoja toks failas Jūsų direktorijoje.." << endl;
        exit(0);
    }
 
    getline(open_f, eil);
    times = count(eil.begin(), eil.end(), 'N'); //counting a number of homework;
    while (open_f)
    { 
      if (!open_f.eof()) 
        {
            open_f >> temp.vardas >> temp.pavarde;
            for(int i = 0; i < times; i++)
            {
                int a;
                open_f >> a;
                temp.paz.push_back(a);
            }
            int a;
            open_f >> a; 
            temp.egz = a;
            mas.push_back(temp);
            temp.paz.resize(0);
        }   else break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Failo nuskaitymas užtruko: "<< diff.count() << " s." << endl;   
    laikas += diff.count();
}
/*
void spausd(vector<studentas> &mas, char ats) //printing data to file;
{
    ofstream fr ("rezultatai.txt");
    fr << "------------------------------------------------------------------------------" <<endl;
    fr  << left << setw(16) << "Vardas"  << left << setw(25) << "Pavardė " << left << setw(20)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
    fr << "------------------------------------------------------------------------------" <<endl;

    for(auto &k : mas)
    {
        fr  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
        for(int i = 0; i < k.paz.size(); i++)
        {
            k.gal += k.paz[i];
        } 
    
        if (ats == 'G' || ats == 'g')
        {
            double kint = (0.4*k.gal/(double)k.paz.size() +  k.egz*0.6);
            fr << left << setw(20)  << setprecision(2) << fixed << kint  << " - " << endl;  
        }

        if(ats == 'M' || ats == 'm')
        {
            mediana(k, k.paz.size());
            fr << left << setw(20)  << " - " << (0.4*k.med + k.egz*0.6)<< endl;
        }
    }
}
*/
// void spausd(vector<studentas> &mas, char ats) //printing data to file;
// {
//     auto start = std::chrono::high_resolution_clock::now(); auto st=start;
//     ofstream fs ("stropus.txt");
//     ofstream fr ("apsileide.txt");
//     fr << "------------------------------------------------------------------------------" <<endl;
//     fr  << left << setw(16) << "Vardas"  << left << setw(25) << "Pavardė " << left << setw(20)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
//     fr << "------------------------------------------------------------------------------" <<endl;

//     fs << "------------------------------------------------------------------------------" <<endl;
//     fs  << left << setw(16) << "Vardas"  << left << setw(25) << "Pavardė " << left << setw(20)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
//     fs << "------------------------------------------------------------------------------" <<endl;

//     for(auto &k : mas)
//     {
//         //fr  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
//         for(int i = 0; i < k.paz.size(); i++)
//         {
//             k.gal += k.paz[i];
//         } 
    
//         if (ats == 'G' || ats == 'g')
//         {
//             double kint = (0.4*k.gal/(double)k.paz.size() +  k.egz*0.6);
//             if(kint < 5)
//             {
//                 fr  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
//                 fr << left << setw(20)  << setprecision(2) << fixed << kint  << " - " << endl;  
//             } else 
//                 {
//                     fs  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
//                     fs << left << setw(20)  << setprecision(2) << fixed << kint  << " - " << endl;
//                 }
//         }

//         if(ats == 'M' || ats == 'm')
//         {
//             mediana(k, k.paz.size());
//             double kint = (0.4*k.med + k.egz*0.6);
//             if(kint < 5)
//             {
//                 fr  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
//                 fr << left << setw(20)   << " - "  << fixed << setprecision(2) << kint << endl;  
//             } else 
//                 {
//                     fs  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
//                     fs << left << setw(20) << " - "  << fixed << setprecision(2) << kint  << endl;
//                 }
//         }
//     }
//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> diff = end-start; // Skirtumas (s)
//     cout << "Failo rūšiavimas į dvi grupes ir išvedimas į du failus užtruko: "<< diff.count() << " s." << endl;  
// }


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

void skirstymas(vector<studentas> &mas, char ats, vector<studentas> &mldc, vector<studentas> &blgj, double &laikas) //sorting students to good and bad ones;
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    for(auto &k : mas)
    {
        for(int i = 0; i < k.paz.size(); i++)
        {
            k.gal += k.paz[i];
        } 

        if (ats == 'G' || ats == 'g')
        {
            double kint = (0.4*k.gal/(double)k.paz.size() +  k.egz*0.6);
            k.lygin = kint;
            //k.paz.erase(k.paz.begin(), k.paz.end());
            if(kint < 5)
            {
                blgj.push_back(k);
            } else 
                {
                    mldc.push_back(k);
                }
    
        }

        if(ats == 'M' || ats == 'm')
        {
            mediana(k, k.paz.size());
            double kint = (0.4*k.med + k.egz*0.6);
            k.lygin = kint;
            //k.paz.erase(k.paz.begin(), k.paz.end());
            if(kint < 5)
            {
                blgj.push_back(k);
            } else 
                {
                    mldc.push_back(k);
                }
        }        
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Failo suskirstymas į vargšus ir šaunuolius užtruko: "<< diff.count() << " s." << endl;
    laikas += diff.count();

    start = std::chrono::high_resolution_clock::now();
    sort(mldc.begin(), mldc.end(), grading); //data sorting by grades;    
    sort(blgj.begin(), blgj.end(), grading); //data sorting by grades;   

    end = std::chrono::high_resolution_clock::now();
    diff = end-start; // Skirtumas (s)
    cout << "Grupių rūšiavimas vargšai ir šaunuoliai užtruko: "<< diff.count() << " s." << endl;
    laikas += diff.count();

}

void spausd(vector<studentas> &mas, char ats, string file_name, double &laikas) //printing data to file;
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    ofstream fr (file_name);
    fr << "------------------------------------------------------------------------------" <<endl;
    fr << left << setw(16) << "Vardas"  << left << setw(25) << "Pavardė " << left << setw(20)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
    fr << "------------------------------------------------------------------------------" <<endl;

    for(auto &k : mas)
    {
        if (ats == 'G' || ats == 'g')
        {
            fr  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
            fr << left << setw(20)  << setprecision(2) << fixed << k.lygin  << " - " << endl;
        }

        if(ats == 'M' || ats == 'm')
        {
            fr  << left << setw(16) << k.vardas  << left << setw(25) << k.pavarde;
            fr << left << setw(20)   << " - "  << fixed << setprecision(2) << k.lygin << endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Grupės " << file_name << " išvedimas į failą užtruko: "<< diff.count() << " s." << endl;  
    laikas += diff.count();
}

int main()
{   
    vector<studentas> mas;
    studentas tempas;
    vector<studentas> mldc;
    vector<studentas> blgj;
    double laikas = 0;
    char rink;
    cout << "Jei norite:" << endl;
    do
    {
        cout << "nuskaityti duomenis iš failo, įveskite (f). " << endl;
        cout << "įvesti duomenis ranka, įveskite (r). " << endl;
        cout << "sugeneruoti duomenų failą (s). " << endl;
        cin >> rink; 
    } while (rink != 'r' && rink != 'R' && rink != 'f' && rink != 'F' && rink != 's' && rink != 'S');
    
    

    if(rink == 'r' || rink == 'R')
    {
        char uzkl = 'n';
        do{
            pild(tempas);
            mas.push_back(tempas);
            tempas.paz.clear();
            cout << "------------------------------------------------------------------------------" <<endl;
            cout << "Baigti darba spausk n, testi - bet koks klavisas: " << endl;
            cout << "------------------------------------------------------------------------------" <<endl;
            cin >> uzkl;
        }while (uzkl!='n' && uzkl!='N');  
    } else if(rink == 'f' || rink == 'F')
            {
                eil_po_eil("sarasas10000000.txt", tempas, mas, laikas);
            } else if (rink == 's' || rink == 'S')
                {
                    int size;
                    cout << "Įveskite norimo sąrašo dydį: "; cin >> size;
                    generate("sarasas10000000.txt", size);
                    cout << "Duomenų failas sugeneruotas! Pasitikrinkite savo folderį!";
                    exit(0);
                }
    

    
    char ats;  
    do
    {
        cout << "Galutinį pažymį(Vidurkis), rašykite (G)" << endl;
        cout << "Galutinį pažymį(Mediana), rašykite (M)" << endl;
        cin >> ats;
        cout << endl;
    } while (ats != 'g' && ats != 'G' && ats != 'm' && ats != 'M');

    sort(mas.begin(), mas.end(), equality); //data sorting by name/lastname;  If "equality" function returns "False", it let's us know, that the "First" argument shouldn't be placed before "Second" argument, arguments would be swaped;
    skirstymas(mas, ats, mldc, blgj, laikas);
    spausd(mldc, ats, "stiprus.txt", laikas); //printing data to file;
    spausd(blgj, ats, "apsileide.txt", laikas); //printing data to file;
    cout << "Programos trukmės laikas: " << laikas << "s. \n";
    for(auto &i : mas) i.paz.clear();
    mas.clear();
    for(auto &i : mldc) i.paz.clear();
    mldc.clear();
    for(auto &i : blgj) i.paz.clear();
    blgj.clear();

    cout << "Pasitikrinkite savo rezultatų failą!" << endl;
}




