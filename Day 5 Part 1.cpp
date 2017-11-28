/*
 * Day 5 Part 1.cpp
 *
 *  Created on: 28/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool checkNaughtyStrings(string input){

	for(unsigned int i = 0; i < input.size() - 1; i++){
		if(  ((input.at(i) == 'a') && (input.at(i+1) == 'b')) || ((input.at(i) == 'c') && (input.at(i+1) == 'd'))  || ((input.at(i) == 'p') && (input.at(i+1) == 'q')) || ((input.at(i) == 'x') && (input.at(i+1) == 'y'))  ){
			return true;
		}
	}

	return false;
}

bool checkVowels(string input){

	int counter = 0;

	for(unsigned int i = 0; i < input.size(); i++){
		if( (input.at(i) == 'a') || (input.at(i) == 'e') || (input.at(i) == 'i') || (input.at(i) == 'o') || (input.at(i) == 'u') ){
			counter++;
		}
	}

	if(counter >= 3){
		return true;
	}

	else
		return false;
}

bool check2InARow(string input){

	for(unsigned int i = 0; i < input.size() - 1; i++){
		if(input.at(i) == input.at(i+1)){
			return true;
		}
	}
	return false;
}


int main() {

	ifstream in_stream("Input Day 5.txt");

	string input;
	vector<string> inputs;

	while(!in_stream.eof()){
		getline(in_stream, input);
		inputs.push_back(input);
	}

	bool isNaughty;
	bool isNice;

	int niceCounter = 0;

	for(unsigned int i = 0; i < inputs.size(); i++){

		isNaughty = checkNaughtyStrings(inputs.at(i));

		if(isNaughty){
			continue;
		}

		else{

			isNice = (checkVowels(inputs.at(i)) && check2InARow(inputs.at(i)));

			if(isNice)
				niceCounter++;

		}

	}

	cout << niceCounter;

	return 0;
}






















