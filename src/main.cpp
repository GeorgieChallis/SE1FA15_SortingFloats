
#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>

using namespace std;

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
	int rand3;
	if (rand1 > rand2) { rand3 = (rand1 / rand2); }
	else { rand3 = (rand2 / rand3); }

	cout << rand1 << " " << rand2 << " " << rand3 << " " << endl;
	
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

	double temp;			//For bubblesort
	int i, j, flag;	// For bubblesort

	double time;
	clock_t start; 

	vector<float> vec = { 1.2f, 3.6f, 0.99f, 5, 2.1f};  //Enter values to be sorted

	cout << "List of " << vec.size() << " elements:" << endl;
	cout << "\nInput: ";
	for (i = 0; i < vec.size(); i++) // Print all values of vec input
		cout << vec[i] << " ";

	start = clock(); // Start time count for algorithm

	if (vec.size() > 1) { //Check for vec of 0 or 1
		for (i = 0; i < vec.size(); i++) {
			flag = 0; //flag remains 0 if no swaps made
			for (j = 0; j < vec.size() - 1; j++) {
				if (isnan(vec[j])) {
					auto it = vec.begin() + j;
					rotate(it, it + 1, vec.end());
				}

				if (vec[j] > vec[j + 1]) { 
					temp = vec[j + 1];	  
					vec[j + 1] = vec[j];	
					vec[j] = temp;		
					flag = 1; //swap made, so continue
				}
			}
			if (flag == 0) break; //no swaps = vec is sorted
		}
	}
	//time = (clock() - start) / (double)CLOCKS_PER_SEC; // Calculate time taken

	cout << "\nOutput: ";
	for (i = 0; i < vec.size(); i++) // Print all values of sorted vec
		cout << vec[i] << " ";
	cout << endl; 
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<float> vec2 = { 1.2f, 3.6f, 0.99f, 5, 2.1f, 9.8f, 0.0009f, 5.54f, 3.18f, 37};
	
	cout << "\nList of " << vec2.size() << " elements:" << endl;
	cout << "\nInput: ";
	
	for (i = 0; i < vec2.size(); i++) // Print all values of vec input
	{cout << vec2[i] << " ";}

	if (vec2.size() > 1) { //Check for vec of 0 or 1
		for (i = 0; i < vec2.size(); i++) {
			flag = 0; //flag remains 0 if no swaps made
			for (j = 0; j < vec2.size() - 1; j++) {
				if (isnan(vec2[j])) {
					auto it = vec2.begin() + j;
					rotate(it, it + 1, vec2.end());
				}

				if (vec2[j] > vec2[j + 1]) {
					temp = vec2[j + 1];
					vec2[j + 1] = vec2[j];
					vec2[j] = temp;
					flag = 1; //swap made, so continue
				}
			}
			if (flag == 0) break; //no swaps = vec is sorted
		}
	}

		cout << "\nOutput: ";
		for (i = 0; i < vec2.size(); i++) // Print all values of sorted vec
			cout << vec2[i] << " ";
		cout << endl;

		vector<float> vec3 = { 1.2f, 3.6f, 0.99f, 5, 2.1f, 9.8f, 0.0009f, 5.54f, 3.18f, 37, 12.1f, -0.0f, 4.444f, 0.008f, 6.66f };

		cout << "\nList of " << vec3.size() << " elements:" << endl;
		cout << "\nInput: ";
		for (i = 0; i < vec3.size(); i++) // Print all values of vec input
		{
			cout << vec3[i] << " ";
		}

		if (vec3.size() > 1) { //Check for vec of 0 or 1
			for (i = 0; i < vec3.size(); i++) {
				flag = 0; //flag remains 0 if no swaps made
				for (j = 0; j < vec3.size() - 1; j++) {
					if (isnan(vec3[j])) {
						auto it = vec3.begin() + j;
						rotate(it, it + 1, vec3.end());
					}

					if (vec3[j] > vec3[j + 1]) {
						temp = vec3[j + 1];
						vec3[j + 1] = vec3[j];
						vec3[j] = temp;
						flag = 1; //swap made, so continue
					}
				}
				if (flag == 0) break; //no swaps = vec is sorted
			}
		}

			cout << "\nOutput: ";
			for (i = 0; i < vec3.size(); i++) // Print all values of sorted vec
				cout << vec3[i] << " ";
			cout << endl;

			return 0;
		}
