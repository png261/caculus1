#include <iostream>
#include <math.h> 

#define MROW 3
#define MCOL 4

using namespace std;

void guass(double M[MROW][MCOL]) {
    for(int base_row = 0; base_row < MROW - 1; base_row++) {
        for(int row = base_row + 1; row < MROW; row++) {
               double ration = M[row][base_row] / M[base_row][base_row];
               for(int col = 0; col < MCOL; col++) {
                    M[row][col] -= M[base_row][col] * ration;
               }
        }
    }

    for(int row = 0; row < MROW; row ++) {
        double division = M[row][row];
        for(int col = 0; col < MCOL; col++) {
            M[row][col] /= division;
        }
    }
}

void jordan(double M[MROW][MCOL]) {
    for(int row = MROW - 2; row >= 0; row--) {
        for(int reduce_col = MCOL - 2; reduce_col > row; reduce_col--) {
            double ration = M[row][reduce_col] / M[reduce_col][reduce_col];
            for(int col = 0; col < MCOL; col++) {
                M[row][col] -= M[reduce_col][col] * ration;
            }
        }
    }
}

void inputM(double M[MROW][MCOL]) {
    for(int row = 0; row < MROW; row ++) {
        for(int col = 0; col < MCOL; col++) {
            cin>>M[row][col];
        }
    }
}

void printM(double M[MROW][MCOL]) {
    for(int row = 0; row < MROW; row ++) {
        for(int col = 0; col < MCOL; col++) {
            cout<<M[row][col]<<" ";
        }
        cout<<endl;
    }
}

void pResult(double M[MROW][MCOL]) {
    for(int row = 0; row < MROW; row++) {
        for(int col = 0; col < MCOL; col++) {
            if(isinf(M[row][col])){
                    cout<<"No solution";
                    return;
            }

            if(isnan(M[row][col])){
                    cout<<"INF";
                    return;
            }
        }
    }

    for(int row = 0; row < MROW; row++) {
        printf("%.3f ", M[row][MCOL - 1]);
    }
}

int main() {
    double M[MROW][MCOL];  

    inputM(M);
    guass(M);
    jordan(M);
    pResult(M);
}
