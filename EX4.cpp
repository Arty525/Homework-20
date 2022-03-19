#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

std::ifstream readBank;
std::ofstream writeBank;

void add(std::vector<int> bills) {

}
void withdrawal(int cash) {
	
}

int main() {
	std::vector<int> bills = { 100, 200, 500, 1000, 2000, 5000 };
	std::string operation;
	int cash;

	srand(time(nullptr));

	std::cout << "What operation do you want to perform? withdraw/replenish: ";
	std::cin >> operation;

	if (operation == "+") add(bills);

	if (operation == "-") {
		std::cout << "Enter summ: ";
		std::cin >> cash;

		withdrawal(cash);
	}
	if (operation == "read") {
		int number;
		std::ifstream file("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX4\\bank.bin", std::ios::binary);
		while (!file.eof()) {
			file.read((char*)&number, sizeof(number));
			std::cout << number << std::endl;
		}
		file.close();
	}
	return main();
}
