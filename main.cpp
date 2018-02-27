#include "pre_proc.hpp"

int main(int argc, char ** argv)
{
            std::cout.unsetf(std::ios::floatfield);
            std::cout.precision(3);
            std::cout.setf(std::ios::fixed, std::ios::floatfield);

            int chr[lop][n*m],chp[lop][n*m], twr[lop];
            float fp[lop], t[lpp], maximum, minimum, avg, stdDev, temp[lpp], suma_temp;
            int bz, popCnt=0;
            srand(time(NULL));

            for (int i=0; i<lpp; i++){
                zainicjuj_najlepszego_X_i_moze_cos_jeszcze_rbz();
                gen_pierwsza_populacje(chr);
                ocen_osobnikow_populacji(chr, fp);
                do
                {
                    popCnt++;
                    selekcja_osobnikow_na_rodzicow(fp, twr);
                    krzyzujOsobniki(chr, twr, chp);
                    mutacja(chp);
                    sukcesja(chp, chr);
                    ocen_osobnikow_populacji(chr, fp);
                }while(bz>rbz);
                t[i] = nfp;
                }
                zwroc_najlepszego();
        // obliczyc - max, min, srednia, stddev dla t
        //MAXIMUM
        for (int i=0; i<lpp; i++){
            if(maximum<t[i]){
                maximum = t[i];
            }
        }
        cout << "Maksimum: " << maximum << endl;
        //MINIMUM
        minimum = maximum;
        for (int i=0; i<lpp; i++){
            if(minimum > t[i]){
                minimum = t[i];
            }
        }
        cout << "Minimum: " << minimum << endl;
        //SREDNIA
        for (int i=0; i<lpp; i++){
            avg = avg + t[i];
        }
        avg = avg/lpp;
        cout << "Srednia z t[i] = " << avg << endl;

        //standard deviaion
        for (int i=0; i<lpp; i++){
            temp[i] = t[i] - avg;
        }
                for (int i=0; i<lpp; i++)
                    temp[i] = potegowanie(temp[i], 2);

                    suma_temp = 0;
                    for (int i=0; i<lpp; i++)
                        suma_temp = suma_temp + temp[i];

                stdDev = sqrt(suma_temp/lpp);
                cout << "Odch.std: " << stdDev << std::endl;

        return(0);
}
// FUNCTIONS
float ksi_fnct(){
    return (float)rand()/RAND_MAX;
}

float potegowanie(float x, float y){
        float tmp = x;
        for (int i=1; i<y; ++i)
            tmp *= x;
        return tmp;
}

float f(float x[n]){
    	// x=17.30764054	f1=17.29320809	f2=34.58641619	f3=51.87962428
        float s = 0;
        for (int i=0; i<n; i++)
            s = s + x[i] * sin(x[i]) * sin(x[i]);
        return s;
}

void zainicjuj_najlepszego_X_i_moze_cos_jeszcze_rbz(void){
    for (int i=0; i<n; i++)
        nx[i] = xmin[i];
    nfp = f(nx);
    rbz = 0;
}

void gen_pierwsza_populacje(int chr[lop][n*m]){
        for (int i=0; i<lop; i++){
            for (int j=0; j<n*m; j++){
                chr[i][j] = rand()%2;
            }
        }
}

void drukuj_1sza_pop(int chr[lop][n*m]){
        for (int i=0; i<lop; i++){
            for (int j =0; j<n*m; j++){
                cout << chr[i][j];
            }
            cout << endl;
        }
}

void ocen_osobnikow_populacji(int chr[lop][n*m], float fp[lop]){
    int gp, gl;
    float wd, p2;
    float x[n];

    int pnfp=nfp; //poprzednia najlepsza funkcja przystposowania na wejsciu to nfp

    for (int j=0; j<lop; j++){
        for (int i=0; i<n; i++){
            p2 = 1;
            wd = 0;
            gp = (i+1) * m -1;
            gl = i * m;
            for (int k=gp; k>=gl; k--){
                wd = wd + chr[j][k] * p2;
                p2 = 2 * p2;
            }
            x[i] = xmin[i] + (xmax[1] - xmin[i]) * wd/(p2 -1);
        }
        fp[j] = f(x);
        if (fp[j]>nfp){
            nfp=fp[j]; //nfp - najlepsza funkcja przystosowania
            for (int i=0; i<n; i++)
                nx[i]= x[i];
        }
    }
    if (pnfp==nfp)
        rbz++; //rzeczywisyty licznik iteracji bez zmian
    else
        rbz = 0;
}

void selekcja_osobnikow_na_rodzicow(float fp[lop], int twr[lop]){
        int i1, i2;
        for (int i=0; i<lop; i++){
            i1 = rand()%lop;
            i2 = rand()%lop;
        if (fp[i1]>fp[i2])
            twr[i] = i1;
        else
            twr[i] = i2;
        }
}

void krzyzujOsobniki(int chr[lop][n*m], int twr[lop], int chp[lop][n*m]){
        int i1, i2, l = lop, p1, p2, r1, r2, pc;
        float xi = ksi_fnct();
        for (int i=0; i<lop/2; i++){
            i1 = rand()%1;
            r1 = twr[i1];
            twr[i1] = twr[l-1];
            l--;
            i2 = rand()%1;
            r2 = twr[i2];
            twr[i2] = twr[l-1];
            l--;
            p1 = 2 * i;
            p2 = 2 * i + 1;

            if (xi< pk){
                pc = rand()%(n*m-1);
                for (int k=0; k<=pc; k++){
                    chp[p1][k]=chr[r1][k];
                    chp[p2][k]=chr[r2][k];
                }
                for (int k=pc+1; k<n*m; k++){
                    chp[p1][k] = chr[r2][k];
                    chp[p2][k] = chr[r1][k];
                }
            }
            else{
                for (int k=0; k<=n*m; k++){
                    chp[p1][k] = chr[r1][k];
                    chp[p2][k] = chp[r2][k];
                }
            }
        }
}

void drukuj_populacje_potomna(int chp[lop][n*m]){
    for (int i=0; i<lop; i++){
        for (int j=0; j<n*m; j++){
                cout << chp[i][j];
            }
            cout << endl;
        }
    }

void mutacja(int chp[lop][n*m]){
        float xi = ksi_fnct();
        for (int i=0; i<lop; i++){
            for (int j=0; j<n*m; j++){
                if(xi < pm){
                    if(chp[i][j] == 1)
                        chp[i][j] = 0;
                    else
                        chp[i][j] = 1;
                }
            }
        }
    }
void sukcesja(int chp[lop][n*m], int chr[lop][n*m]){
    for (int i=0; i<lop; i++){
        for (int j=0; j<n*m; j++){
            chr[i][j] = chp[i][j];
        }
    }
}

void zwroc_najlepszego(void){
    cout << nfp << endl;
    for (int i=0; i<n; i++)
        cout << nx[i] << " " << endl;
}
