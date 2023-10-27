#include<iostream>
#include <string>

int fuja(const std:: string& glavni , const std:: string& pod) {
	int brojac = 0;
	int podstringduzina = pod.length();
	for (int i = 0; i <= glavni.length() - podstringduzina; i++) {
		if (glavni.substr(i, podstringduzina) == pod) {
			brojac++;
		}
	}
	return brojac;
}

int main() {
	std::string glavni = "pojmapojam pojma pojam pojma";
	std::string pod = "pojma";
	int rez = fuja(glavni, pod);
	std::cout << rez << std::endl;
	return 0;
}