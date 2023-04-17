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


| Failo generavimo laiko priklausomybė nuo failo dydžio |         |          |          |         |          |
|-------------------------------------------------------|---------|----------|----------|---------|----------|
| Failo dydis                                           | 1000    | 10000    | 100000   | 1000000 | 10000000 |
| Laikas (s)                                            | 0,00491 | 0,038901 | 0,490742 | 3,93846 | 39,9915  |


| Failo vykdymo laiko priklausomybė nuo mokinių skaičiaus |          |          |          |          |          |
|:-------------------------------------------------------:|----------|----------|----------|----------|----------|
| Failo dydis:                                            | 1000     | 10000    | 100000   | 1000000  | 10000000 |
|            ------------------                           |   ----   |   ----   |   ----   |   ----   |   ----   |
| Failo nuskaitymas (s)                                   | 0,005713 | 0,225245 | 0,957342 | 2,55829  | 16,4509  |
| Failo suskirstymas (s)                                  | 0,001508 | 0,291981 | 1,54404  | 3,11065  | 10,2709  |
| Grupių rūšiavimas (s)                                   | 0,000791 | 0,0097   | 0,126932 | 1,68492  | 21,3313  |
| Grupės stiprus.txt išvedimas (s)                        | 0,031365 | 0,004505 | 0,039839 | 0,387609 | 3,88838  |
| Grupės apsileide.txt išvedimas (s)                      | 0,022317 | 0,003321 | 0,030168 | 0,273538 | 2,75437  |
| Programos trukmė (s)                                    | 0,061694 | 0,534752 | 2,69832  | 8,01502  | 54,6958  |


## Versija v0.5

Šioje versijoje testuojama skirtingų konteinerių sparta (Vector, Deque, List):
- Sukurtos trys programos su skirtingais konteineriu tipais;
- Išmatuotos programų veikimo spartos pagal failo nuskaitymą, rūšiavimą, suskirstymą į dvi dalis;


Naudojamo kompiuterio (su kurio buvo atliekami testai) konfiguracijos:
- CPU Intel i5-8500 3.00GHZ
- GPU Nvidia GeForce GTX 1050 Ti
- RAM 8GB
- SSD 128GB

Rezultatai:

-DEQUE laikai
| Dydis/Laikas | Nuskaitymas | Rūšiavimas | Skirstymas | Iš viso: |
|--------------|-------------|------------|------------|----------|
| 1000         | 0.004317    | 0.002456   | 0.001292   | 0.008065 |
| 10000        | 0.015438    | 0.039839   | 0.012412   | 0.067689 |
| 100000       | 0.231829    | 0.450965   | 0.151605   | 0.834399 |
| 1000000      | 1.46521     | 5.40646    | 1.11423    | 7.98591  |
| 10000000     | 29.5312     | 65.1683    | 369.947    | 464.646  |

-LIST laikai
| Dydis/Laikas | Nuskaitymas | Rūšiavimas | Skirstymas | Iš viso: |
|--------------|-------------|------------|------------|----------|
| 1000         | 0.005088    | 0.000285   | 0.001607   | 0.00698  |
| 10000        | 0.017831    | 0.002757   | 0.006546   | 0.027134 |
| 100000       | 0.571809    | 0.039673   | 0.284875   | 0.896357 |
| 1000000      | 2.05224     | 0.482547   | 0.964355   | 3.49914  |
| 10000000     | 14.8531     | 5.71986    | 21.895     | 42.468   |

-VECTOR laikai
| Dydis/Laikas | Nuskaitymas | Rūšiavimas | Skirstymas | Iš viso: |
|--------------|-------------|------------|------------|----------|
| 1000         | 0.003396    | 0.000902   | 0.000605   | 0.004903 |
| 10000        | 0.018882    | 0.014363   | 0.00334    | 0.036585 |
| 100000       | 0.207026    | 0.171451   | 0.044294   | 0.422771 |
| 1000000      | 0.899791    | 2.08785    | 0.340913   | 3.32856  |
| 10000000     | 8.20936     | 25.4069    | 4.72837    | 38.3446  |


## Versija v1.0
Šioje versijoje testuojamas skirtingų strategijų taikymo sparta konteineriams(Vector, Deque, List):
- 1 Strategija: 
Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".
**Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu.**

*Studentų konteinerio skirstymo rezultatai 1 strategija su duomenų failų "sarasas1000000.txt":*
| Skirstymas | sarasas1000000 |
|------------|----------------|
| Deque      | 1.11423        |
| List       | 0.964355       |
| Vector     | 0.340913       |

- 2 Strategija:
Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai".
**Atminties atveju tai efektyviau, tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.**

*Studentų konteinerio skirstymo rezultatai 2 strategija su duomenų failų "sarasas1000000.txt":*
| Skirstymas | sarasas1000000 |
|------------|----------------|
| Deque      | 0.728905       |
| List       | 0.743333       |
| Vector     | 0.246679       |
