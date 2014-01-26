/*
 * Main.cpp
 *
 *  Created on: Jan 12, 2014
 *      Author: aj9027
 */



#include <iostream>
#include <vector>
#include <ctime>
#include "RandomNumberGenerator.h"

using namespace std;

void bubbleSort(vector<int> &);
vector<int> mergeSort(vector<int>);
vector<int> merge(vector<int> & A, vector<int> & B);

int main() {
	cout << "Alogirithms 0.0.1" << endl;
	int numberCount;
	int low, high;
	int repitions;
	int algorithmChoice;

	cout << "How many numbers: " << endl;
	cin >> numberCount;

	cout << "Number range: " << endl;
	cin >> low >> high;

	cout << "Sorting algorithm: " << endl;
	cin >> algorithmChoice;

	/** /
	cout << "Repitions: " << endl;
	cin >> repitions;
	/**/

	vector<int> numbers;
	RandomNumberGenerator randomGenerator(low, high);
	srand((unsigned)time(NULL));

	// generate all the random numbers
	for (int index = 0; index < numberCount; index++ ) {
		numbers.push_back(randomGenerator.generate());
	}

	/**/ 	// display the list pre sort
	cout << "Pre Sorted List:" << endl;
	for (vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
		cout << *itr << '\t';
	}
	cout << endl;
	long startTime = time(NULL);
	switch (algorithmChoice) {
		case 1:
			cout << "Bubble Sort";
			bubbleSort(numbers);
			break;
		case 2:
			cout << "Merge sort";
			numbers = mergeSort(numbers);
			break;
		default:
			cout << "No correspondind sort";
			break;
	}
	cout << " in " << time(NULL) - startTime << "seconds." << endl;

	/**/ 	// display the list post sort
	cout << "Sorted List:" << endl;
	for (vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
			cout << *itr << '\t';
		}
	/**/
}



vector<int> mergeSort(vector<int> numbers) {

	int length = numbers.size();

	if (length <=1) {
		return numbers;
	}

	vector<int> left, right;
	int middle = length / 2;
	// divide
	left.insert(left.begin(), numbers.begin(), numbers.begin() + middle);
	for (vector<int>::iterator itr = numbers.begin() + middle; itr < numbers.end(); itr++) {
			right.push_back((*itr));
	}

	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}

vector<int> merge(vector<int>& A, vector<int>& B) {
	vector<int> sorted;
	while (A.size() > 0 || B.size() > 0) {
		if (A.size() > 0 && B.size() > 0) {
			if (A.at(0) <= B.at(0)) {
				sorted.push_back(A.at(0));
				A.erase(A.begin(), A.begin() + 1);
			} else {
				sorted.push_back(B.at(0));
				B.erase(B.begin(), B.begin() + 1);
			}
		}
		else if (A.size() > 0) {
			sorted.push_back(A.at(0));
			A.erase(A.begin(), A.begin() + 1);
		}
		else if (B.size() > 0) {
			sorted.push_back(B.at(0));
			B.erase(B.begin(), B.begin() + 1);
		}
	}
	return sorted;
}

void bubbleSort(vector<int> & numbers) {
	int length = numbers.size();
	bool swapped;
	do {
		swapped = false;
		for (int index = 0; index < length - 1; index++) {
			if (numbers.at(index) > numbers.at(index + 1)) {
				int temp = numbers.at(index);
				numbers.at(index) = numbers.at(index + 1);
				numbers.at(index + 1) = temp;
				swapped = true;
				/** / 	// show steps in sorting operation
				for (vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
							cout << *itr << '\t';
						}
				cout << endl;
				/**/
			}
		}
	} while (swapped);
}


