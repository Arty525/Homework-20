#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
	int width;
	int height;

	srand(time(nullptr));

	cout << "Enter width and height: ";
	cin >> width >> height;

	ofstream picture("D:\\RTY\\GITHUB\\Repositories\\homework-20\\EX2\\pic.txt");
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			picture << rand() % 2;
		}
		picture << endl;
	}
	picture.close();

	return 0;
}