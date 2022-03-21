#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

std::ifstream readBank;
std::ofstream writeBank;

void add(std::vector<int> bills) {
	int count = 0;
	int bill;

	readBank.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX4\\bank.bin", std::ios::binary);
	while (!readBank.eof()) {
		readBank.read((char*)&bill, sizeof(bill));
		count += readBank.gcount();
	}
	readBank.close();

	if (count < 4000) {
		writeBank.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX4\\bank.bin", std::ios::app);
		while (count < 4000) {
			int random = bills[rand() % 6];
			writeBank.write((char*)&random, sizeof(random));
			count += sizeof(random);
		}
		writeBank.close();
	}


}

void out(int cash) {
	int bill;
	int zero = 0;
	int summ = 0;

	readBank.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX4\\bank.bin", std::ios::binary);
	writeBank.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX4\\buffer.bin", std::ios::binary);
	while (!readBank.eof()) {
		readBank.read((char*)&bill, sizeof(bill));
		if ((cash - summ - bill >= 0 || (cash - summ) % bill == 0) && summ != cash) {
			writeBank.write((char*)&zero, 0);
			summ += bill;

		}
		else {
			writeBank.write((char*)&bill, sizeof(bill));
		}
	}
	readBank.close();
	writeBank.close();

	readBank.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX4\\buffer.bin", std::ios::binary);
	writeBank.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX4\\bank.bin", std::ios::binary);
	while (!readBank.eof() - 1) {
		readBank.read((char*)&bill, sizeof(bill));
		writeBank.write((char*)&bill, sizeof(bill));
	}
	readBank.close();
	writeBank.close();
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

		out(cash);
	}
	return 0;
}
