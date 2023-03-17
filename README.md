# ObjectProgramming
All projects related to my University "Object Programming" class will be stored in this repository.

## Versija v0.1
- Mokinių  galutinių pažymių vidurkio/medianos skaičiavimo programa.
- Leidžianti atsitiktinai generuoti mokinio pažymius arba įvesti pažymius ranka.

Formulė galutinio pažymio skaičiavimui: 
## Galutinis = 0.4 * Mediana(arba Vidurkis) + 0.6 * Egzaminas

## Versija v0.2
- Pridėtas pasirinkimas skaityti duomenis iš failo.
- Greičiau rušiuojami duomenys (mokiniai pagal vardą/pavardę). (v0.2.1)
- Greitesnis pažymių rūšiavimas. (v0.2.1)
- Pakoreguota spausdinimo funkcija. (v0.2.2)

## Versija v0.3
- Kur tikslinga - panaudotos struktūros
- Funkcijos, nauji duomenų tipai (struct’ūros) perkeltos į antraštinius (angl. header (*.h)) failus.
- Sukurtas Makefile.
- Panaudotas išimčių valdymas (angl. Exception Handling) skaitant failą, kurio nėra.
- Pakoreguotas Makefile, tinkantis programos laiko skaičiavimui. (v0.3.1)

## Versija v0.4
- Generuojami failai norimam studentų skaičiui gauti.
- Surūšiuoti (padalinti) studentai į dvi kategorijas (stipruolius ir apsileidusius) atsižvelgiant į jų galutinį pažymį.
- Surūšiuoti studentai išvesti į du naujus failus.
- Atlikta programos veikimo greičio (spartos) analizė.


-------------------------------------------------------------------------
|       Failo generavimo laiko priklausomybė nuo mokinių skaičiaus      |
-------------------------------------------------------------------------
| Mokinių skaičius | 1000    | 10000    | 100000   | 1000000 | 10000000 |
-------------------------------------------------------------------------
| Laikas (s)       | 0,00491 | 0,038901 | 0,490742 | 3,93846 | 39,9915  |
-------------------------------------------------------------------------


---------------------------------------------------------------------------------------------
|                  Failo vykdymo laiko priklausomybė nuo mokinių skaičiaus                  |
---------------------------------------------------------------------------------------------
| Failo dydis:                       | 1000     | 10000    | 100000   | 1000000  | 10000000 |
---------------------------------------------------------------------------------------------
| Failo nuskaitymas (s)              | 0,005713 | 0,225245 | 0,957342 | 2,55829  | 16,4509  |
---------------------------------------------------------------------------------------------
| Failo suskirstymas (s)             | 0,001508 | 0,291981 | 1,54404  | 3,11065  | 10,2709  |
---------------------------------------------------------------------------------------------
| Grupių rūšiavimas (s)              | 0,000791 | 0,0097   | 0,126932 | 1,68492  | 21,3313  |
---------------------------------------------------------------------------------------------
| Grupės stiprus.txt išvedimas (s)   | 0,031365 | 0,004505 | 0,039839 | 0,387609 | 3,88838  |
---------------------------------------------------------------------------------------------
| Grupės apsileide.txt išvedimas (s) | 0,022317 | 0,003321 | 0,030168 | 0,273538 | 2,75437  |
---------------------------------------------------------------------------------------------
| Programos trukmė (s)               | 0,061694 | 0,534752 | 2,69832  | 8,01502  | 54,6958  |
---------------------------------------------------------------------------------------------

| Failo vykdymo laiko priklausomybė nuo mokinių skaičiaus |          |          |          |          |          |
|:-------------------------------------------------------:|----------|----------|----------|----------|----------|
| Failo dydis:                                            | 1000     | 10000    | 100000   | 1000000  | 10000000 |
|:-------------------------------------------------------:|----------|----------|----------|----------|----------|
| Failo nuskaitymas (s)                                   | 0,005713 | 0,225245 | 0,957342 | 2,55829  | 16,4509  |
| Failo suskirstymas (s)                                  | 0,001508 | 0,291981 | 1,54404  | 3,11065  | 10,2709  |
| Grupių rūšiavimas (s)                                   | 0,000791 | 0,0097   | 0,126932 | 1,68492  | 21,3313  |
| Grupės stiprus.txt išvedimas (s)                        | 0,031365 | 0,004505 | 0,039839 | 0,387609 | 3,88838  |
| Grupės apsileide.txt išvedimas (s)                      | 0,022317 | 0,003321 | 0,030168 | 0,273538 | 2,75437  |
| Programos trukmė (s)                                    | 0,061694 | 0,534752 | 2,69832  | 8,01502  | 54,6958  |
