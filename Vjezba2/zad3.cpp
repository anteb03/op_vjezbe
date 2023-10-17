#include<iostream>

struct Vector{
   int* elementi; 
   int logicnavel;
   int fizickavel;
   void vector_new(int n) {
        elementi = new int[n];
        logicnavel = 0; 
        fizickavel = n; 
    }
    void vector_delete() {
        delete[] elementi;
    }
    void vector_push_back(int value) {
        if (logicnavel == fizickavel) {
            int* noviel = new int[fizickavel * 2];
            for (int i = 0; i < logicnavel; i++) {
                noviel[i] = elementi[i];
            }
            delete[] elementi;
            elementi = noviel;
            fizickavel *= 2;
        }
        elementi[logicnavel] = value;
        logicnavel++;
    }
    void vector_pop_back() {
        if (logicnavel > 0) {
            logicnavel--;
        }
    }
    void vector_front(int& rez) {
        if (logicnavel > 0) {
            rez = elementi[0];
        } else {
            rez = -1;
        }
    }
    void vector_back(int& rez) {
        if (logicnavel > 0) {
            rez = elementi[logicnavel - 1];
        } else {
            rez = -1;
        }
    }
    int vector_size() {
        return logicnavel;
    }
};

int main(){
    Vector vector;
    int n,a;
    std::cout << "Unesi broj elemenata:" << '\n';
    std::cin >> n;
    vector.vector_new(n);
    std::cout << "Unesi elemente:" << '\n';
	for (int i = 0;i < n;i++) {
		std::cin >> a;
		vector.vector_push_back(a);
	}
	
	int vel = vector.vector_size();
    std::cout << "Velicina vektora je:" << vel << '\n';
    int frontvel;
    vector.vector_front(frontvel);
    std::cout << "Prvi clan vektora je:" << frontvel << '\n';
    int backval;
    vector.vector_back(backval);
    std::cout << "Zadnji clan vektora je:" << backval << '\n';
    vector.vector_pop_back();
    vector.vector_push_back(5);
    vel = vector.vector_size();
    std::cout << "Velicina vektora nakon dodavanja clana je:" << vel << '\n';
    vector.vector_back(backval);
    std::cout << "Zadnji clan vektora je:" << backval << '\n';
    vector.vector_delete();
    vector.vector_back(backval);
    std::cout << "Zadnji clan vektora nakon brisanja je " << backval << '\n';
}