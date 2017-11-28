/*
 * Day 5 Part 2.cpp
 *
 *  Created on: 28/11/2017
 *      Author: filipa
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool checkForAba(string input){
	for(unsigned int i = 0; i < input.size() - 2; i++){
		if(input.at(i) == input.at(i+2)){
			return true;
		}
	}
	return false;
}

bool checkForRep(string input){

	string toCheck;

	while(true){

		toCheck = input.substr(0,2);
		input.erase(0,2);

		if(input.size() <= 0){
			break;
		}

		for(unsigned int i = 0; i < input.size()-1; i++){
			if( (input.at(i) == toCheck.at(0)) && (input.at(i+1) == toCheck.at(1))){
				return true;
			}
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


	bool isNice;
	int niceCounter = 0;

	for(unsigned int i = 0; i < inputs.size(); i++){

		isNice = (checkForAba(inputs.at(i)) && checkForRep(inputs.at(i)));

		if(!isNice){
			niceCounter++;
		}

	}

	cout << niceCounter;

}

