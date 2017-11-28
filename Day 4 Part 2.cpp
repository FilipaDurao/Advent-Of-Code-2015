/*
 * Day 4 Part 2.cpp
 *
 *  Created on: 28/11/2017
 *      Author: filipa
 */


#include <iostream>
#include "md5.h"


using namespace std;

bool checkIf6Zeros(string hashed){
	if(hashed.substr(0,6) == "000000"){
		return true;
	}

	else
		return false;
}

int main(){

	string input = "bgvyzdsv";
	string character;
	int counter = 0;
	unsigned int index;


	while (true){

		character = input;

		character += to_string(counter);

		if (checkIf6Zeros(md5(character))){
			cout << counter;
			break;
		}

		else{
			index = character.find_last_of(to_string(counter));
			character.erase(index, to_string(counter).size());
		}

		counter++;
	}

}

