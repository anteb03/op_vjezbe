#include <iostream>
#include <string>
using namespace std;

class Food {
private:
	int static Counter;

public:
	Food() {
		Counter++;
	}

	static int counter() {
		return Counter;
	}

	~Food() {
		Counter--;
	}
};

int get_counter() {
	return Food::counter();
}

int Food::Counter = 0;


class VirtualPet {
private:
	string Ime;
	string Vrsta;
	int Bodovi = 0;
	string Status;
	int BrojPorcija = 0;

public:
	VirtualPet(string ime, string vrsta, string status, int bodovi = 0) {
		this->Ime = ime;
		this->Vrsta = vrsta;
		this->Bodovi = bodovi;
		this->Status = status;
	}

	bool operator==(const VirtualPet& pet) const {
		return (Ime == pet.Ime && Vrsta == pet.Vrsta && Bodovi == pet.Bodovi && Status == pet.Status);
	}

	bool operator!=(const VirtualPet& pet) const {
		return !(*this == pet);
	}

	VirtualPet operator+(VirtualPet pet) {
		return *this = pet;
	}

	VirtualPet operator++() {
		BrojPorcija++;
		Bodovi -= 5;
		return *this;
	}

	VirtualPet operator++(int) {
		return ++(*this);
	}

	bool operator<(VirtualPet pet) {
		return Bodovi < pet.Bodovi;
	}

	bool operator<=(VirtualPet pet) {
		return Bodovi <= pet.Bodovi;
	}

	bool operator>(VirtualPet pet) {
		return Bodovi > pet.Bodovi;
	}

	bool operator>=(VirtualPet pet) {
		return Bodovi >= pet.Bodovi;
	}

	friend ostream& operator<<(ostream& out, VirtualPet pet) {
		out << pet.Ime << "\t" << pet.Vrsta << "\t" << pet.Status << "\t" << pet.Bodovi << "\t" << pet.BrojPorcija;
		return out;
	}
};

int main() {
	Food food1;
	Food food2;
	cout << get_counter() << " porcije";
	cout << endl;
	
	VirtualPet pet1("Mau", "Macka", "Sretan", 100);
	VirtualPet pet2("Mau", "Macka", "Sretan", 100);
	pet1++;
	pet2++;
	pet2++;
	if (pet1 == pet2) {
		cout << "Ljubimci su jednaki" << endl;
	}
	else if (pet1 != pet2) {
		cout << "Ljubimci su razliciti" << endl;
	}

	if (pet1 < pet2) {
		cout << "Ljubimac 1 je manje sretan od Ljubimca 2." << endl;
	}
	else if (pet1 > pet2) {
		cout << "Ljubimac 1 je sretniji od Ljubimca 2." << endl;
	}
	else {
		cout << "Ljubimci su jednako sretni" << endl; 
	}
	cout << pet1 << endl;
	cout << pet2;
	return 0;
}