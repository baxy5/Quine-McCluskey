#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string BR[16] = {
	"0000",
	"0001",
	"0010",
	"0011",
	"0100",
	"0101",
	"0110",
	"0111",
	"1000",
	"1001",
	"1010",
	"1011",
	"1100",
	"1101",
	"1110",
	"1111"
	};

	// Request the outputs on 1 from Mi. table
	int numberOfOnes;
	vector<int> miOnes;
	int input;

	cout << "Please give me the number of '1' from the Mi. table: ";
	cin >> numberOfOnes;
	cout << endl;

	for (int i = 0; i < numberOfOnes; i++) {
		do {
			cin >> input;
			if (input < 0 || input > 15) {
				cout << "Wrong number, try again!" << endl;
			}
		} while (input < 0 || input > 15);
		miOnes.push_back(input);
	}

	// Clear console
	system("cls");

	// Show Quine-McCluskey function
	cout << "Q(ABCD):{";
	for (int i = 0; i < numberOfOnes; i++) {
		cout << miOnes[i];
		if (i != numberOfOnes - 1) {
			cout << ", ";
		}
	}
	cout << "}" << endl;

	// Binary Representation Table
	cout << endl << "BR:" << endl;
	cout << "----------------------" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		cout << BR[miOnes[i]] << ": " << miOnes[i] << endl;
	}

	// Quantity of 1s
	cout << endl << "1s Quantity:" << endl;
	cout << "----------------------" << endl;
	vector<int> BRQ;
	int Q;
	for (int i = 0; i < numberOfOnes; i++) {
		Q = 0;
		for (int j = 0; j < 4; j++) {
			if (BR[miOnes[i]][j] == '1') {
				Q++;
			}
		}
		BRQ.push_back(Q);
		cout << miOnes[i] << ": " << Q << endl;
	}

	cout << "----------------------------" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		cout << miOnes[i] << ":" << BRQ[i] << endl;
	}

	// ABR -> Ascending Binary Representation


	system("pause");
	return 0;
}