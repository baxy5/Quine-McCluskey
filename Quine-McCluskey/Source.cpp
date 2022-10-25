#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

// BRTable => Find decimal's binary representation, and displays in a table.
// ABR => Arrange our decimal's ascendingly by 1s.
// coutFunction => Display our function.
// getGroup => Groups("súlyszám"), get the key value's group.

void BRTable(int numberOfOnes, string BR[], vector<int> miOnes) {
	for (int i = 0; i < numberOfOnes; i++) {
		cout << BR[miOnes[i]] << ": " << miOnes[i] << endl;
	}
}
vector<int> ABR(vector<int> array,int numberOfOnes, vector<int> sortedOnes) {
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 0) {
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 1 || array[i] == 2 || array[i] == 4 || array[i] == 8) {
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 3 || array[i] == 5 || array[i] == 6 || array[i] == 9 || array[i] == 10 || array[i] == 12) {
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 7 || array[i] == 11 || array[i] == 13 || array[i] == 14) {
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}
	cout << "-" << endl;
	for (int i = 0; i < numberOfOnes; i++) {
		if (array[i] == 15) {
			cout << array[i] << endl;
			sortedOnes.push_back(array[i]);
		}
	}

	return sortedOnes;
}
void coutFunction(int numberOfOnes, vector<int> array) {
	cout << "Q(ABCD):{";
	for (int i = 0; i < numberOfOnes; i++) {
		cout << array[i];
		if (i != numberOfOnes - 1) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}
int getGroup(int groups[5][6], int key) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			if (key == groups[i][j]) {
				return i;
			}
		}
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
	}; // Binary Representation
	int groups[5][6] = { {0}, {1,2,4,8} ,{3,5,6,9,10,12}, {7,11,13}, {15} };

	// Request the outputs on 1 from Minterm table
	int numberOfOnes;
	vector<int> miOnes;
	int input;

	cout << "Please give me the sum of '1' from the Mi. table: ";
	cin >> numberOfOnes;
	cout << endl;

	cout << "Please give me the outputs on 1 from the Minterm table: ";
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

	// Write out the Quine-McCluskey function
	coutFunction(numberOfOnes, miOnes);
	
	// Binary Representation Table
	cout << endl << endl << "BR:" << endl;
	cout << "----------------------" << endl;
	BRTable(numberOfOnes, BR, miOnes);

	// Quantity of 1s
	vector<int> BRQ; // Binary Representation Quantity
	int Q; // Quantity
	cout << endl << endl << "1s Quantity:" << endl;
	cout << "----------------------" << endl;
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
	
	// ABR Sorting -> Ascending Binary Representation
	sort(miOnes.begin(), miOnes.end());
	vector<int> sortedOnes;
	cout << endl << endl <<  "ABR:" << endl;
	cout << "----------------------" << endl;
	sortedOnes = ABR(miOnes, numberOfOnes, sortedOnes);

	// Simplification => checking distance (I.stage)
	cout << endl << endl << "I.stage:" << endl;
	cout << "----------------------" << endl;
	vector<int> stageOneDistances;
	for (int i = 0; i < numberOfOnes; i++) {

		// Getting the number's group
		int group = getGroup(groups, sortedOnes[i]);

		// getting distances
		for (int j = 1; j < numberOfOnes; j++) {
			int nextNumberGroup = getGroup(groups, sortedOnes[j]);

			// checking groups
			if (group < nextNumberGroup) {

				// check if its bigger or not
				if (sortedOnes[i] < sortedOnes[j]) {

					// checking if number is power of two
					int distance = sortedOnes[j] - sortedOnes[i];
					double distanceLog = log(distance) / log(2);
					double isPowerOfTwo = fmod(distanceLog, 1);
					if (isPowerOfTwo == 0) {
						cout << sortedOnes[i] << "," << sortedOnes[j] << "(" << distance << ")" << endl;
						stageOneDistances.push_back(sortedOnes[i]);
						stageOneDistances.push_back(sortedOnes[j]);
						stageOneDistances.push_back(distance);
					}
				}

			}
		}
	}

	// II.stage
	cout << endl << endl << "II.stage:" << endl;
	cout << "----------------------" << endl;
	vector<int> stageTwoDistances;
	for (int i = 2; i < stageOneDistances.size(); i+=3) {
		
		// first number's group
		int group = getGroup(groups, stageOneDistances[i-2]);

		for (int j = i+3; j < stageOneDistances.size(); j += 3) {

			// checking if the distance is the same
			if (stageOneDistances[i] == stageOneDistances[j]) {

				// Getting the number's group
				// next number's group
				int nextNumberGroup = getGroup(groups, stageOneDistances[j-2]);

				if(group < nextNumberGroup){

					// checking if the second distance's number is power of 2
					int distance = abs(stageOneDistances[i - 2] - stageOneDistances[j - 2]);
					double distanceLog = log(distance) / log(2);
					double isPowerOfTwo = fmod(distanceLog, 1);
					if (isPowerOfTwo == 0) {
						cout << stageOneDistances[i - 2] << "," << stageOneDistances[i - 1] << ",";
						cout << stageOneDistances[j - 2] << "," << stageOneDistances[j - 1] << "(";
						cout << stageOneDistances[i] << "," << abs(stageOneDistances[i - 2] - stageOneDistances[j - 2]) << ")" << endl;
						stageTwoDistances.push_back(stageOneDistances[i - 2]);
						stageTwoDistances.push_back(stageOneDistances[i - 1]);
						stageTwoDistances.push_back(stageOneDistances[j - 2]);
						stageTwoDistances.push_back(stageOneDistances[j - 1]);
						stageTwoDistances.push_back(stageOneDistances[i]);
						stageTwoDistances.push_back(abs(stageOneDistances[i - 2] - stageOneDistances[j - 2]));
					}
				}
			}
		}
	}
	
	// III.stage
	cout << endl << endl << "III.stage:" << endl;
	cout << "----------------------" << endl;
	for (int i = 4; i < stageTwoDistances.size(); i += 6) {

		// first number's group
		int group = getGroup(groups, stageTwoDistances[i - 2]);

		for (int j = i + 6; j < stageTwoDistances.size(); j += 6) {

			// checking if the distance is the same
			if (stageTwoDistances[i] == stageTwoDistances[j] && stageTwoDistances[i+1] == stageTwoDistances[j+1]) {

				// Getting the number's group
				// next number's group
				int nextNumberGroup = getGroup(groups, stageTwoDistances[j - 2]);

				if (group < nextNumberGroup) {

					// checking if the second distance's number is power of 2
					int distance = abs(stageTwoDistances[i - 2] - stageTwoDistances[j - 2]);
					double distanceLog = log(distance) / log(2);
					double isPowerOfTwo = fmod(distanceLog, 1);
					if (isPowerOfTwo == 0) {
						cout << stageTwoDistances[i - 4] << "," << stageTwoDistances[i - 3] << "," << stageTwoDistances[i - 2] << ",";
						cout << stageTwoDistances[i - 1] << ",";
						cout << stageTwoDistances[j - 4] << "," << stageTwoDistances[j - 3] << "," << stageTwoDistances[j - 2] << ",";
						cout << stageTwoDistances[j - 1] << "(";
						cout << stageTwoDistances[i] << "," << stageTwoDistances[i + 1] << "," << abs(stageTwoDistances[i - 2] - stageTwoDistances[j - 2]) << ")";
						cout << endl;
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}