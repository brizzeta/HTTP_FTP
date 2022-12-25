#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#pragma comment(lib, "urlmon.lib")
using namespace std;

string finds[8] = { "\"ccy\"", "\"base_ccy\"", "\"buy\"", "\"sale\"", "\"ccy\"", "\"base_ccy\"", "\"buy\"", "\"sale\"" };

int main() {
	string srcURL = "https://api.privatbank.ua:443/p24api/pubinfo?json&exchange&coursid=5";
	string destFile = "exchange.txt";

	if (S_OK == URLDownloadToFileA(NULL, srcURL.c_str(), destFile.c_str(), 0, NULL)) {
		cout << "Saved in " << destFile << endl;
	}
	else cout << "Cannot be save.\n";

	string buff;
	ifstream in("exchange.txt");

	if (!in.is_open()) {
		cout << "Cannot open the file.\n";
	}

	in >> buff;
	in.close();
	string NewBuff;

	for (short i = 0; i < 8; i++) {
		short index = buff.find(finds[i]);
		if (index == -1) {
			NewBuff += "Not found.\n";
		}
		else {
			short j = index;
			while (buff != ",") {
				NewBuff += buff[j];
			}
		}
	}
	cout << endl << NewBuff << endl;
}