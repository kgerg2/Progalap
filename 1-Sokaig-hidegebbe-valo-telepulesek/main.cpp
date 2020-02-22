/*
  Készítette: Kovács Gergely Zsolt
  Neptun: X8B97C
  E-mail: x8b97c@inf.elte.hu
  Feladat: „ProgAlap beadandó feladatok” téma „Sokáig hidegebbé váló települések” feladat
*/
#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

const int MinN = 1;
const int MaxN = 1000;
const int MinM = 1;
const int MaxM = 1000;
const int MinH = -50;
const int MaxH = 50;

bool HelyesN(int x)
{
    bool helyes = x >= MinN && x <= MaxN;
    if(!helyes) cerr << "Hibas telepulesszam. [" << MinN << ".." << MaxN << "] intervallumban kell lennie." << endl;
    return helyes;
}

bool HelyesM(int x)
{
    bool helyes = x >= MinM && x <= MaxM;
    if(!helyes) cerr << "Hibas napszam. [" << MinM << ".." << MaxM << "] intervallumban kell lennie." << endl;
    return helyes;
}

bool HelyesH(int x)
{
    bool helyes = x >= MinH && x <= MaxH;
    if(!helyes) cerr << "Hibas homerseklet. [" << MinH << ".." << MaxH << "] intervallumban kell lennie." << endl;
    return helyes;
}

int Beolvas(string Uzenet, bool Ellenorzo(int))
{
    int x;
    bool helyes;
    do
    {
        cerr << Uzenet; //ez a biro-s változatban kommentelve szerepel
        cin >> x;
        helyes = true;
        if (cin.fail() || !isspace(cin.peek()))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            helyes = false;
        }
        if (helyes)
        {
            helyes = Ellenorzo(x);
        }
    } while (!helyes);
    return x;
}

void Kiir(int T, int Hul[MaxN])
{
    cerr << "A telepulesek szama: ";
    cout << T;
    cerr << endl << "A telepulesek: ";
    for (int i = 1; i <= T; i++)
    {
        cout << " " << Hul[i-1];
    }
    cout << endl;
}

void Eldob(int db){
    int x;
    for (int i = 1; i <= db; i++)
    {
        cin >> x;
    }
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void BillreVar(){
    system("pause");
}

int main()
{
    int Hul[1000], T, N, M, Kezdet, Elozo, Uj;
    N = Beolvas("Telepulesek szama: ", HelyesN);
    M = Beolvas("Napok szama: ", HelyesM);
    T = 0;
    for (int i = 1; i <= N; i++)
    {
        Elozo = -50;
        Kezdet = 1;
        int j = 1;
        while (j <= M && j - Kezdet < 8)
        {
            Uj = Beolvas("Homerseklet: ", HelyesH);
            if (Uj >= Elozo)
            {
                Kezdet = j;
            }
            Elozo = Uj;
            j++;
        }
        Eldob(M-j+1);
        if (j - Kezdet == 8)
        {
            T++;
            Hul[T-1] = i;
        }
    }
    Kiir(T, Hul);
    BillreVar();
    return 0;
}
