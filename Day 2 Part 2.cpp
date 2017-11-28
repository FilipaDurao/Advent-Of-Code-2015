/*
 * Day 2 Part 2.cpp
 *
 *  Created on: 28/11/2017
 *      Author: filipa
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int getMax(int side1, int side2){

	if(side1 > side2)
		return side1;

	else if(side2 > side1)
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

		int maxSide = getMax(getMax(l,w), h);

		if(maxSide == l){
			counter += 2*w+2*h;
		}
		else if(maxSide == w){
			counter += 2*l+2*h;
		}
		else{
			counter += 2*l+2*w;
		}

		counter += l*w*h;

	}

	cout << counter;

}


