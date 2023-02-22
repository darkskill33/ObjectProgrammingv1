#include "Mylib.h"

struct studentas
{
    string vardas, pavarde;
    vector<int> paz;
    double egz;
    double gal;
    double med;
};

bool isnumber(string str)
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

void sort(studentas &temp, int n)
{
    for (int i = 0; i < n; i++)
    {  
        for (int j = i + 1 ; j < n; j++)
        {
            if(temp.paz[i] < temp.paz[j])
            {
                swap(temp.paz[i], temp.paz[j]);
            }
        }
    }
}

void mediana(studentas &temp, int n)
{
    sort(temp, n);
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

void pild(studentas& temp)
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
                cout << "Iveskite SKAICIU [1; 10] be simboliu ar raidziu. Į intervalą nepatenkantys skaičiai nebus abdorojami" << endl;
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
            int a = (rand()%10)+1;
            for (int i = 0; i < a; i++)
            {
                int c = (rand()%10)+1; 
                cout << c << " ";
                temp.paz.push_back(c);
            }
            cout << endl;
            cout << "Generuojamas egzamino pažymys: " << endl;
            int c = (rand()%10)+1;
            cout << c << endl;
            temp.egz = c;
        } 
}

void spausd(studentas& temp, char ats)
{
    cout  << left << setw(10) << temp.vardas  << left << setw(14) << temp.pavarde;
    for(int i = 0; i < temp.paz.size(); i++)
    {
        temp.gal += temp.paz[i];
    } 
    
    if (ats == 'G' || ats == 'g')
    {
        double kint = (0.4*temp.gal/(double)temp.paz.size() +  temp.egz*0.6);
        cout << left << setw(19)  << setprecision(2) << fixed << kint  << " - " << endl;  
    }

    if(ats == 'M' || ats == 'm')
    {
        mediana(temp, temp.paz.size());
        cout << left << setw(19)  << " - " << (0.4*temp.med + temp.egz*0.6)<< endl;
    }
}

int main()
{
    vector<studentas> mas;
    studentas tempas;
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

    char ats;  
    cout << "Jei norite matyti:" << endl;  
    cout << "Galutinį pažymį(Vidurkis), rašykite (G)" << endl;
    cout << "Galutinį pažymį(Mediana), rašykite (M)" << endl;
    cin >> ats;
    cout << endl;
    cout << "------------------------------------------------------------------------------" <<endl;
    cout  << left << setw(10) << "Vardas"  << left << setw(14) << "Pavardė " << left << setw(12)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
    cout << "------------------------------------------------------------------------------" <<endl;

    for(auto &i : mas) spausd(i, ats);
    for(auto &i : mas) i.paz.clear();
    mas.clear();
}
