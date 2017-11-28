/*
 * Day 1 Parts 1 and 2.cpp
 *
 *  Created on: 27/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main (){

	ifstream in_stream("Input Day 1.txt");

	string input;
	int counter = 0;

	getline(in_stream, input);

	for(unsigned int i = 0; i < input.size(); i++){

		if(input[i] == '('){
			counter++;
		}

		else if(input[i] == ')'){
			counter--;
		}

		// This is for Part 2, comment this if for part 1!
		if(counter == -1){
			cout << i+1 << endl;
			break;
		}
	}


	cout<< counter;
}

