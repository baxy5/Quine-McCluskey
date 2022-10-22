#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<int> ABR(vector<int> array,int numberOfOnes, vector<int> sortedOnes) {
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 0) {
			cout << setw(10);
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << setw(10);
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 1 || array[i] == 2 || array[i] == 4 || array[i] == 8) {
			cout << setw(10);
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << setw(10);
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 3 || array[i] == 5 || array[i] == 6 || array[i] == 9 || array[i] == 10 || array[i] == 12) {
			cout << setw(10);
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << setw(10);
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 7 || array[i] == 11 || array[i] == 13 || array[i] == 14) {
			cout << setw(10);
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << setw(10);
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 15) {
			cout << setw(10);
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}

	return sortedOnes;
}
void BRT(int numberOfOnes, string BR[], vector<int> miOnes) {
	for (int i = 0; i < numberOfOnes; i++) {
		cout << setw(10);
		cout << BR[miOnes[i]] << ": " << miOnes[i] << endl;
	}
}

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
	cout << endl << endl << "BR:" << endl;
	cout << "----------------------" << endl;
	BRT(numberOfOnes, BR, miOnes);

	// Quantity of 1s
	cout << endl << endl << "1s Quantity:" << endl;
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
		cout << setw(10);
		cout << miOnes[i] << ": " << Q << endl;
	}

	// ABR Sorting -> Ascending Binary Representation
	sort(miOnes.begin(), miOnes.end());
	vector<int> sortedOnes;
	cout << endl << endl <<  "ABR:" << endl;
	cout << "----------------------" << endl;
	sortedOnes = ABR(miOnes, numberOfOnes, sortedOnes);

	// Simplification => checking distance
	

	

	system("pause");
	return 0;
}