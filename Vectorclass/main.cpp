#include "functions.h"


int main()
{   studentas pavyzdys;
    pavyzdys.setVardas("Skubis");
    pavyzdys.setPavarde("doo");
    pavyzdys.setEgz(10);
    pavyzdys.setPaz(7);
    pavyzdys.setPaz(8);
    studentas pavyzdys2(pavyzdys);
    studentas pavyzdys3;
    pavyzdys3 = pavyzdys2; 
    studentas pavyzdys4 = std::move(pavyzdys2);
    studentas naujokas;
    naujokas = std::move(pavyzdys3);
    cout << naujokas << endl;
    cout << pavyzdys3 << endl;
    pavyzdys.randominfo();
    studentas naujokas1;
    cout << "Iveskite varda, pavarde, egzamino pazymi"<<endl;
    cin >> naujokas1;
    cout << naujokas1<< endl;
    
    vectorclass<studentas> mas; ///creating vector<studentas>;
    studentas tempas; ///creating temporary class;
    vectorclass<studentas> blgj; ///creating vector<studentas>;
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
            tempas.getPaz().clear();
            cout << "------------------------------------------------------------------------------" <<endl;
            cout << "Baigti darba spausk n, testi - bet koks klavisas: " << endl;
            cout << "------------------------------------------------------------------------------" <<endl;
            cin >> uzkl;
        }while (uzkl!='n' && uzkl!='N');  
    } else if(rink == 'f' || rink == 'F')
            {
                string pavad;
                cout <<" Pasirinkite failą: " << endl;
                system("dir /b sar*.txt");
                cin >> pavad;
                
                eil_po_eil(pavad, tempas, mas, laikas);
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

    sort(mas.begin(), mas.end(), equality); ///data sorting by name/lastname;  If "equality" function returns "False", it let's us know, that the "First" argument shouldn't be placed before "Second" argument, arguments would be swaped;
    skirstymas(mas, ats, blgj, laikas); ///sorting students to good and bad ones;
    spausd(mas, ats, "stiprus.txt", laikas); ///printing data to file;
    spausd(blgj, ats, "apsileide.txt", laikas); ///printing data to file;
    cout << "Programos trukmės laikas: " << laikas << "s. \n";

    for(auto &i : mas) i.getPaz().clear(); ///cleaning up data from vectors;
    mas.clear();
    for(auto &i : blgj) i.getPaz().clear(); ///cleaning up data from vectors;
    blgj.clear();
    
}