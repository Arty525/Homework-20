#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream fishing;
	std::string fish;
	std::string caught;
	int count = 0;

	std::cout << "Choose your fish: ";
	std::cin >> fish;

	fishing.open("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX3\\river.txt");
	while (getline(fishing, caught)) {
		if (caught == fish) {
			std::ofstream basket("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX3\\basket.txt", std::ios::app);
			basket << caught << std::endl;
			++count;
		}
	}

	std::cout << "You are caught " << count << " fishes." << std::endl;
}