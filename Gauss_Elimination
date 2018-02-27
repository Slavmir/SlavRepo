#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

//nX - ilosc niewiadomych
//MX - macierz kwadratowa [nX x nX]
//eX - macierz rozszerzona (z X)

bool gauss_elimination(int nX, double **MX, double *eX); //prototyp
const double epsi = 1e-12; //stala porownawcza

int main()
{
    double **MX, *eX;
    int nX=0;
    std::cout <<"Podaj liczbe niewiadomych X: ";
    std::cin >> nX;
    //inicjalizacja i wypelnianie tablic
    MX = new double *[nX+1];
    eX = new double [nX];
        for (int i=0; i<nX; i++)
            MX[i] = new double [nX+1];

    //wypelniam macierz MX pseud.los. liczbami
    for (int i=0; i<nX; i++)
        for (int j=0; j<=nX; j++)
            MX[i][j] = (unsigned)rand()%99+1;

    //TEST -- wydruk tablicy
    for (int i=0; i<nX; i++){
    for (int j=0; j<nX+1; j++){
            std::cout << MX[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    //TEST KONIEC

    std::cout << "Eliminacja Gaussa: " << std::endl;
    if (gauss_elimination(nX, MX, eX)){
        for (int i=0; i<nX; i++)
            std::cout << "X:" << i+1 << " = " << std::setw(6) << eX[i] << std::endl;
    }
    else{
        std::cout << std::endl;
        std::cout << "Dzielnik = 0" << std::endl;
    }
    //

    //usuwanie alokowanej pamieci na tablice
    for (int i=0; i<nX; i++)
        delete MX[i];
    delete [] MX;
    delete [] eX;
    //
    return (0);
}
bool gauss_elimination(int nX, double **MX, double *eX){
        double m, s;
        //ETAP 1 - "Eliminacja wspolczynnikow"
        for (int i=0; i<nX-1; i++){
            for (int j=i+1; j<nX; j++){
                if(fabs(MX[i][i]) < epsi)
                    return false;
                m = -MX[j][i]/MX[i][i];
                for (int k=i+1; k<=nX; k++)
                    MX[j][k] += m * MX[i][k];
                }
        }
        //2 "Postepowanie Odwrotne" wyliczam niewiadome nX Etap
        for (int i=nX-1; i>=0; i--){
            s = MX[i][nX];
            for (int j=nX-1; j>=i+1; j--)
                s -= MX[i][j] * eX[j];
            if (fabs(MX[i][i]) < epsi)
                return false;
            eX[i] = s/MX[i][i];
        }
        return true;
}
