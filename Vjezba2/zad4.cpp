#include<iostream>
#include <iomanip>

struct Matrix{
    int red;
    int stup;
    float** pod;
};

void unos(Matrix& matrica){
    std::cout << "Unesite broj redova (m): ";
    std::cin >> matrica.red;
    std::cout << "Unesite broj stupaca (n): ";
    std::cin >> matrica.stup;
    
    matrica.pod = new float*[matrica.red];
    for (int i = 0; i < matrica.red; i++) {
        matrica.pod[i] = new float[matrica.stup];
        for (int j = 0; j < matrica.stup; j++) {
            std::cout << "Unesite element matrice (" << i << ", " << j << "): ";
            std::cin >> matrica.pod[i][j];
        }
    }
}

void generiraj(Matrix& matrica, float a, float b){
    std::cout << "Unesite broj redova za generiranje automatske matrice(m): ";
    std::cin >> matrica.red;
    std::cout << "Unesite broj stupaca za generiranje automatske matrice(n): ";
    std::cin >> matrica.stup;
    
    matrica.pod = new float*[matrica.red];
    for (int i = 0; i < matrica.red; i++) {
        matrica.pod[i] = new float[matrica.stup];
        for (int j = 0; j < matrica.stup; j++) {
            float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            matrica.pod[i][j] = a + random * (b - a);
        }
    }
}

void ispis(Matrix& matrica){
    for (int i = 0; i < matrica.red; i++) {
        for (int j = 0; j < matrica.stup; j++) {
            std::cout << std::fixed << std::setprecision(4) << matrica.pod[i][j];
            if (j < matrica.stup - 1) {
                std::cout << "\t";  
            }
        }
        std::cout << std::endl;  
    }
}

void zbroj(Matrix& matrica1, Matrix& matrica2, Matrix& rezultat) {
    if (matrica1.red != matrica2.red || matrica1.stup != matrica2.stup) {
        std::cout << "Matrice nisu istih dimenzija i ne mogu se zbrojiti." << std::endl;
        return;
    }

    rezultat.red = matrica1.red;
    rezultat.stup = matrica1.stup;
    rezultat.pod = new float*[rezultat.red];

    for (int i = 0; i < rezultat.red; i++) {
        rezultat.pod[i] = new float[rezultat.stup];
        for (int j = 0; j < rezultat.stup; j++) {
            rezultat.pod[i][j] = matrica1.pod[i][j] + matrica2.pod[i][j];
        }
    }
}
void razlika(Matrix& matrica1, Matrix& matrica2, Matrix& rezultat2) {
    if (matrica1.red != matrica2.red || matrica1.stup != matrica2.stup) {
        std::cout << "Matrice nisu istih dimenzija i ne mogu se oduzeti." << std::endl;
        return;
    }

    rezultat2.red = matrica1.red;
    rezultat2.stup = matrica1.stup;
    rezultat2.pod = new float*[rezultat2.red];

    for (int i = 0; i < rezultat2.red; i++) {
        rezultat2.pod[i] = new float[rezultat2.stup];
        for (int j = 0; j < rezultat2.stup; j++) {
            rezultat2.pod[i][j] = matrica1.pod[i][j] - matrica2.pod[i][j];
        }
    }
}

void mnozenje(Matrix& matrica1, Matrix& matrica2, Matrix& rezultat3){
    if (matrica1.stup != matrica2.red && matrica1.red != matrica2.stup) {
        std::cout << "Matrice se ne mogu množiti jer broj stupaca prve matrice nije jednak broju redova druge matrice ili obrnuto." << std::endl;
        return;
    }

    rezultat3.red = matrica1.red;
    rezultat3.stup = matrica2.stup;
    rezultat3.pod = new float*[rezultat3.red];

    for (int i = 0; i < rezultat3.red; i++) {
        rezultat3.pod[i] = new float[rezultat3.stup];
        for (int j = 0; j < rezultat3.stup; j++) {
            rezultat3.pod[i][j] = 0.0;
            for (int k = 0; k < matrica1.stup; k++) {
                rezultat3.pod[i][j] += matrica1.pod[i][k] * matrica2.pod[k][j];
            }
        }
    } 
}

void transponiraj(Matrix& matrica, Matrix& transponirana) {
    transponirana.red = matrica.stup;
    transponirana.stup = matrica.red;
    transponirana.pod = new float*[transponirana.red];

    for (int i = 0; i < transponirana.red; i++) {
        transponirana.pod[i] = new float[transponirana.stup];
        for (int j = 0; j < transponirana.stup; j++) {
            transponirana.pod[i][j] = matrica.pod[j][i];
        }
    }
}

void oslobadanjememorije(Matrix& matrica) {
    for (int i = 0; i < matrica.red; i++) {
        delete[] matrica.pod[i];
    }
    delete[] matrica.pod;
}

int main(){
    Matrix A,B,C,rezultat,rezultat2,rezultat3,transponirana;
    std::cout << "Unos prve matrice:"<< std::endl;
    unos(A);
    std::cout << "Unos druge matrice:"<< std::endl;
    unos(B);
    std::cout << "Unos treće automatske matrice:"<< std::endl;
    generiraj(C,1.0,6.0);
    std::cout << "Prva matrica"<< std::endl;
    ispis(A);
    std::cout << "Druga matrica"<< std::endl;
    ispis(B);
    std::cout << "Treća automatska matrica"<< std::endl;
    ispis(C);
    std::cout << "Zbroj prve i druge:"<< std::endl;
    zbroj(A,B,rezultat);
    ispis(rezultat);
    std::cout << "Razlika prve i druge:"<< std::endl;
    razlika(A,B,rezultat2);
    ispis(rezultat2);
    std::cout << "Umnožak prve i druge:"<< std::endl;
    mnozenje(A,B,rezultat3);
    ispis(rezultat3);
    std::cout << "Transponirana prva matrica:"<< std::endl;
    transponiraj(A,transponirana);
    ispis(transponirana);
    oslobadanjememorije(A);
    oslobadanjememorije(B);
    oslobadanjememorije(C);
    oslobadanjememorije(rezultat);
    oslobadanjememorije(rezultat2);
    oslobadanjememorije(rezultat3);
    oslobadanjememorije(transponirana);
    return 0;
}
