#include "Mylib.h"

struct studentas
{
    string vardas, pavarde;
    int *paz;
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

void pild(studentas &temp, int &times)
{
    cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;

    int cs = 10000, ns;
    int mas[cs];
    string check;
    times = 0;

    char pas;
    cout << "Jei norite atsitiktinai sugeneruoti pažymius ir egzamino rezultatą, įveskite (k), jei duomenis įvesite pats, įveskite (s): " << endl;
    do
    {
        cin >> pas;
    } while (pas != 's' && pas != 'S' && pas != 'k' && pas != 'K' );

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
                if(times == 0)
                {
                    mas[times] = check_nd;
                    break;
                } else break;
            } else if(check_nd > 0 && check_nd <=10)
                    {
                        mas[times] = check_nd;
                        times++;
                    }
        }
        temp.paz = new int[times + 1];
        copy(mas, mas+times, temp.paz);

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
            times = (rand()%10)+1;
            cout << "TIMES: " << times << endl;
            for (int i = 0; i < times; i++)
            {
                int c = (rand()%10)+1; 
                cout << c << " ";
                mas[i] = c; 
            }
            temp.paz = new int[times+1];
            copy(mas, mas+times, temp.paz);
            cout << endl;
            cout << "Generuojamas egzamino pažymys: " << endl;
            int c = (rand()%10)+1;
            cout << c << endl;
            temp.egz = c;
        }   


}

void spausd(studentas &temp, int pazsk, char ats)
{
    cout  << left << setw(10) << temp.vardas  << left << setw(14) << temp.pavarde;
    for(int i = 0; i < pazsk; i++)
    {
        temp.gal += temp.paz[i];
    } 
    
    if (ats == 'G' || ats == 'g')
    {
        double kint = (0.4*temp.gal/(double)pazsk +  temp.egz*0.6);
        cout << left << setw(19)  << setprecision(2) << fixed << kint << endl;  
    }

    if(ats == 'M' || ats == 'm')
    {
        mediana(temp, pazsk);
        cout << left << setw(19)  << temp.med << endl;
    }
    delete [] temp.paz;
}

int main ()
{
int pazsk = 0;
int nr = 0;
studentas *mas;
mas = new studentas [10000];
char uzkl = 'n';
do
{
    pild(mas[nr], pazsk);
    cout << "------------------------------------------------------------------------------" <<endl;
    cout << "Baigti darba spausk n, testi - bet koks klavisas: " << endl;
    cout << "------------------------------------------------------------------------------" <<endl;
    nr++;
    cin >> uzkl;
} while (uzkl!='n' && uzkl!='N');

studentas *temp = new studentas [nr];
copy(mas, mas + nr, temp);
delete [] mas;
nr++;
mas = new studentas [nr];
copy(temp, temp + nr - 1, mas);

char ats;  
cout << "Jei norite matyti:" << endl;  
cout << "Galutinį pažymį, rašykite (G)" << endl;
cout << "Mediana, rašykite (M)" << endl;
cin >> ats;
cout << endl;
cout << "------------------------------------------------------------------------------" <<endl;
cout  << left << setw(10) << "Vardas"  << left << setw(14) << "Pavardė " << left << setw(12)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
cout << "------------------------------------------------------------------------------" <<endl;

for (int i = 0; i < nr; i++) spausd(mas[i], pazsk, ats);
delete [] temp; 
pild(mas[nr - 1], pazsk); 
}
