
#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>

using namespace std;

vector<float>SortAll(vector<float>);

union makeFloat { //Union to change parts of float via ints
	struct {
		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	};
	float fl;
};

int main() {
	time_t clockVar;
	time(&clockVar);
	srand((unsigned int)clockVar); //use rand() for random value

	int rand1 = rand();
	int rand2 = rand();
	int rand3 = rand();
	
	if (rand1 > rand2)  rand3 = (rand1 / rand2); 
	else  rand3 = (rand2 / rand3); 

	//cout << rand1 << " " << rand2 << " " << rand3 << " " << endl;

	makeFloat PosNaN; //Generate a positive NaN
	PosNaN.exponent = 0xff; //0xff for NaN/inf
	PosNaN.mantissa = rand(); // 1 to 4194303 for qNan, 4194304 to 8388607 for sNan, 0 and 8388608 is inf
	PosNaN.sign = 0;

	makeFloat NegNaN; //Generate a negative NaN
	NegNaN.exponent = 0xff;
	NegNaN.mantissa = rand();
	NegNaN.sign = 1;

	makeFloat PosZero = { 0 }; //Create +0
	PosZero.sign = 0;

	makeFloat NegZero = { 0 }; //Create -0
	NegZero.sign = 1;

	cout << "\t\t SE1FA15 - Assignment 1: Sorting Floating Point Numbers in C++" << endl << endl;
	//Q1: 'Sort' an empty list
	vector<float> vec = {};  
	vector<float> sorted_vec = SortAll(vec);

	//Q2: 'Sort' a list of one element
	vec.push_back(5.5f);
	sorted_vec = SortAll(vec);


	vec = { 1.2f, 3.6f, 0.99f, 5, 2.1f };  //Enter values to be sorted
	sorted_vec = SortAll(vec);
	
	vector<float> vec2 = { 1.2f, 3.6f, 0.99f, 5, 2.1f, 9.8f, 0.0009f, 5.54f, 3.18f, 37 };
	vector<float> sorted_vec2 = SortAll(vec2);

	vector<float> vec3 = { 1.2f, 3.6f, 0.99f, 5, 2.1f, 9.8f, 0.0009f, 5.54f, 3.18f, 37, 12.1f, -0.0f, 4.444f, 0.008f, 6.66f };
	vector<float> sorted_vec3 = SortAll(vec3);

	cin.get();
}

vector<float>SortAll(vector<float> input) {
	double temp;	//For bubblesort
	int i, j, flag;	// For bubblesort

	double time;
	clock_t start;

	cout << "\nList of " << input.size() << " elements:" << endl;
	if (input.size() < 2) {
		cout << endl;
		return input;
	}
	else {
		cout << "Input: ";
		for (i = 0; i < input.size(); i++) // Print all values of vec input
			cout << input[i] << " ";

		//start = clock(); // Start time count for algorithm
		if (input.size() > 1) { //Check for vec of 0 or 1
			for (i = 0; i < input.size(); i++) {
				flag = 0; //flag remains 0 if no swaps made
				for (j = 0; j < input.size() - 1; j++) {
					if (isnan(input[j])) {
						auto it = input.begin() + j;
						rotate(it, it + 1, input.end());
					}

					if (input[j] > input[j + 1]) {
						temp = input[j + 1];
						input[j + 1] = input[j];
						input[j] = temp;
						flag = 1; //swap made, so continue
					}
				}
				if (flag == 0) break; //no swaps = vec is sorted
				//time = (clock() - start) / (double)CLOCKS_PER_SEC; // Calculate time taken
			}

			cout << "\nOutput: ";
			for (i = 0; i < input.size(); i++) // Print all values of sorted vec
				cout << input[i] << " ";
			cout << endl;
		}
		return input;
	}
}
