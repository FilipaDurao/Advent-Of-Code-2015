/*
 * Day 2 Part 1.cpp
 *
 *  Created on: 27/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int getMin(int side1, int side2){

	if(side1 < side2)
		return side1;

	else if(side2 < side1)
		return side2;

	else
		return side1;
}


int main() {

	vector<string> inputs;

	ifstream in_stream("Input Day 2.txt");

	string input;

	while(!in_stream.eof()){
		getline(in_stream, input);
		inputs.push_back(input);
	}

	int counter = 0;

	for(unsigned int i = 0; i < inputs.size(); i++){

		int l = stoi(inputs.at(i).substr(0, inputs.at(i).find_first_of('x')));
		inputs.at(i).erase(0, inputs.at(i).find_first_of('x')+1);

		int w = stoi(inputs.at(i).substr(0, inputs.at(i).find_first_of('x')));
		inputs.at(i).erase(0, inputs.at(i).find_first_of('x')+1);

		int h = stoi(inputs.at(i).substr(0, inputs.at(i).find_first_of('x')));
		inputs.at(i).erase(0, inputs.at(i).find_first_of('x')+1);

		int area = 2*l*w + 2*w*h + 2*h*l;
		int side1 = l*w;
		int side2 = l*h;
		int side3 = w*h;

		counter += area + getMin(getMin(side1, side2), side3);

	}

	cout << counter;

}























