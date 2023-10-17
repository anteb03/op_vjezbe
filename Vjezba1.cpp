#include <iostream>
#include <iomanip>
int main()
{
bool flag;
std::cout << "unesi " << true << " - " << false << std::endl;
std::cin >> flag;
std::cout << std::boolalpha << flag << std::endl;
int a = 21;
std::cout << "hex " << std::hex << a << std::endl;
std::cout << "dec " << std::dec << a << std::endl;
std::cout << "oct " << std::oct << a << std::endl;
double pi = 3.141592;
std::cout << "pi = " << std::scientific << std::uppercase;
std::cout << std::setprecision(7) << std::setw(20) << std::setfill('0');
std::cout << pi << std::endl;
}
