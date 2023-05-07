#include "functions.h"

int main()
{   studentas pavyzdys;
    pavyzdys.setVardas("Skubis");
    pavyzdys.setPavarde("doo");
    pavyzdys.setEgz(10);
    pavyzdys.setPaz(7);
    pavyzdys.setPaz(8);
    studentas copy_c = pavyzdys;
    studentas move_a(copy_c);
    cout << move_a.getVardas() << " " <<  move_a.getPavarde() << " " << move_a.getEgz() << endl;
    zmogus zmogus;

    vector<studentas> mas;
    studentas tempas;
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

    sort(mas.begin(), mas.end(), equality); //data sorting by name/lastname;  If "equality" function returns "False", it let's us know, that the "First" argument shouldn't be placed before "Second" argument, arguments would be swaped;
    skirstymas(mas, ats, blgj, laikas);
    spausd(mas, ats, "stiprus.txt", laikas); //printing data to file;
    spausd(blgj, ats, "apsileide.txt", laikas); //printing data to file;
    cout << "Programos trukmės laikas: " << laikas << "s. \n";

    for(auto &i : mas) i.getPaz().clear();
    mas.clear();
    for(auto &i : blgj) i.getPaz().clear();
    blgj.clear();
    
}