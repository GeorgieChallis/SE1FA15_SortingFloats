#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>

#include  "CustomFloat.h"

using namespace std;

union makeFloat { //Union to change parts of float via ints
    struct {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    };
    float fl;
};

time_t clockVar;

vector<float>SortAll(vector<float> &input);

int main() {
    time(&clockVar);
    srand((unsigned int)clockVar); //use rand() for random value
    
    cout << "==========================================================================" << endl;
    cout << "\t SE1FA15 - Assignment 1: Sorting Floating Point Numbers in C++" << endl;
    cout << "==========================================================================" << endl << endl;
    cout << "--- Q1: 'Sort' an empty list ---";
    vector<float> vec = {};
    vector<float> sorted_vec = SortAll(vec);

//Q2
    cout << "--- Q2: 'Sort' a list of one element ---";
    vec.push_back(5.5f);
    sorted_vec = SortAll(vec);

//Q3
    cout << "\n\n--- Q3: Sort lists of different sizes ---";
        //a: List of 5 values
    vec = { 1.2f, 3.6f, .99f, 5, 2.1f };  //Enter values to be sorted
    sorted_vec = SortAll(vec);
        //b: List of 10 values
    vector<float> vec2 = { 1.2f, 3.6f, .99f, 5, 2.1f, 9.8f, 0.0009f, 5.54f, 3.18f, 37 };
    vector<float> sorted_vec2 = SortAll(vec2);
        //c: List of 15 values
    vector<float> vec3 = { 1.2f, 3.6f, .99f, 5, 2.1f, 9.8f, 0.0009f, 5.54f, 3.18f, 37, 12.1f, -0.0f, 4.444f, 0.008f, 6.66f };
    vector<float> sorted_vec3 = SortAll(vec3);

//Q4
    cout << "\n\n--- Q4: Generate a minus zero floating point object that is not identical to zero ---";
    
    CustomFloat PosZero("PosZero", 0, 0, 0);
    CustomFloat NegZero("NegZero", 0, 0, 1);
    PosZero.Print();
    NegZero.Print();

// Q5 and Q6: Generate on Not a Number (NaN)
    cout << "\n\n--- Q5/Q6: Generate multiple different Not a Numbers (NaNs) ---";
    CustomFloat PosNaN("N1", rand(), 0xff, 0);
    CustomFloat NegNaN("N2", rand(), 0xff, 1);
    CustomFloat N3("N3", rand(), 0xff, rand()%2);
    CustomFloat N4("N4", rand(), 0xff, rand()%2);
    
    CustomFloat PosInf("Inf", 8388608, 0xff, 0);
    CustomFloat NegInf("-Inf", 8388608, 0xff,1);
        
    PosNaN.Print();
    NegNaN.Print();
    N3.Print();
    N4.Print();
    
    cin.get();
}

vector<float>SortAll(vector<float> &input) {
    double temp;    //For bubblesort
    int i, j, flag;    // For bubblesort

    double time;
    clock_t start;

    cout << "\nList of " << input.size() << " elements:" << endl;
    if (input.size() < 1) {
        cout << endl;
        return input;
    }
    else {
        cout << "Input: ";
        for (i = 0; i < input.size(); i++) // Print all values of vec input
            cout << input[i] << " ";

        //start = clock(); // Start time count for algorithm
        
        if (input.size() < 2) return input; //Check for vec of 0 or 1
        
        long size = input.size();
        for (i = 0; i < size; i++) {
            flag = 0; //flag remains 0 if no swaps made
            for (j = 0; j < size - 1; j++) {
                if (isnan(input[j])) {
                    auto it = input.begin() + j;
                    rotate(it, it + 1, input.end());
                    size--;
                }
                
                else if (input[j] == 0 && input[j+1] == 0) {
                    if (signbit(input[j])){ // If Negative Zero, swap
                        temp = input[j + 1];
                        input[j + 1] = input[j];
                        input[j] = temp;
                        flag = 1; //swap made, so continue
                    }
                }

                else if (input[j] > input[j + 1]) {
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

