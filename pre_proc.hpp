#ifndef PRE_PROC_HPP_INCLUDED
#define PRE_PROC_HPP_INCLUDED

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;
/**
 n - liczba atrybutow rozwiazania
 x[n] - jednowymiarowa tablica atrybutow rozwiazania (rozwiazanie)
 f(x) - funkcja przystosowania
 m - liczba genow wykorzystana do zakodowania jednego atrybutu rozwiazania
 xmin[n] - jednowymiarowa tablica minimalnych wartosci atrybutow rozwiazania
 xmax[n] - jednowymiarowa tablica maksymalnych wartosci atrybutow rozwiazania
 lop - liczba osobnikow populacji
 chr[lop][n*m] - dwuwymiarowa tablica chromosomow rodzicielskich
 chp[lop][n*m] - dwuwymiarowa tablica chromosomow potomnch
 twr[lop] - tablica wskaznikow na rodzicow
 pm - prawdopodobienstwo mtacji
 pk - prawdopodobienstwo krzyzowania
 bz - liczba bez zmian najlepszego rozwiazania
*/
const int n = 2;
const int m = 24;
const int lop = 100;
const float pk = 0.99;
const float pm = 0.05;
const int bz = 40;
const int lpp = 30;

float xmin[n] = {0,0};
float xmax[n] = {20, 20};
float nfp, nx[n]; //nx -- najlepsze X'y z wartosci f(x) funkcji przystosowania
int rbz;

//#define ksi01() (float)rand()/RAND_MAX - zastapione funkcja ...
float f(float x[n]); //prototyp funkcja przystosowania
float ksi_fnct(); //prttp dla ksi
float potegowanie(float x, float y); //pow dla float
void gen_pierwsza_populacje(int chr[lop][n*m]); //prttp generuj 1 generacje
void drukuj_1sza_pop(int chr[lop][n*m]); //prttp
void drukuj_populacje_potomna(int chp[lop][n*m]); //prttp
void ocen_osobnikow_populacji(int chr[lop][n*m], float fp[lop]); //prototyp ocena osbnikow populacji
void selekcja_osobnikow_na_rodzicow(float fp[lop], int twr[lop]); //prototyp selekcja
void krzyzujOsobniki(int chr[lop][n*m], int twr[lop], int chp[lop][n*m]); //prttp krzyzowanie
void mutacja(int chp[lop][n*m]); //prttp
void sukcesja(int chp[lop][n*m], int chr[lop][n*m]); //prototyp do sukcesji
void zainicjuj_najlepszego_X_i_moze_cos_jeszcze_rbz(void); //prttp
void zwroc_najlepszego(void); //prttp

#endif // PRE_PROC_HPP_INCLUDED
