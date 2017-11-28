/*
 * Day 3 Part 2.cpp
 *
 *  Created on: 28/11/2017
 *      Author: filipa
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

pair<int, int> advancePosition(char symbol, pair<int, int> currentPos){

	int el1, el2;

	switch(symbol){

	case '^':
		el1 = currentPos.first;
		el2 = currentPos.second+1;
		break;

	case '>':
		el1 = currentPos.first+1;
		el2 = currentPos.second;
		break;

	case 'v':
		el1 = currentPos.first;
		el2 = currentPos.second-1;
		break;

	case '<':
		el1 = currentPos.first-1;
		el2 = currentPos.second;
		break;

	}

	return make_pair(el1, el2);
}


bool existsInVector(vector<pair<int, int>> positions, pair<int, int> newPos){

	for(unsigned int i = 0; i < positions.size(); i++){
		if(positions.at(i) == newPos){
			return false;
		}
	}

	return true;
}


int main(){

	ifstream in_stream("Input Day 3.txt");

	string input;

	getline(in_stream, input);

	vector<pair<int, int>> positions;
	positions.push_back(make_pair(0,0));

	vector<pair<int, int>> allPositions;
	allPositions.push_back(make_pair(0,0));
	int index = 0;

	vector<pair<int, int>> positions2;
	positions.push_back(make_pair(0,0));


	bool exists;

	for(unsigned int i = 0; i < input.size(); i++){

		// If its Santa
		if(i%2 == 0){
			// Ver posicao seguinte a partir do local anteriormente visitado
			pair<int, int> newPair = advancePosition(input[i], allPositions.at(index));

			// Ver se ja foi visitado
			exists = existsInVector(positions, newPair);

			// Colocar no vetor dos visitados
			allPositions.push_back(newPair);

			// Por no vetor dos locais visitados
			if(exists){
				positions.push_back(newPair);
			}

			index++;
		}

		// If its Robot-Santa
		else{
			// Ver posicao seguinte a partir do local anteriormente visitado
			pair<int, int> newPair = advancePosition(input[i], allPositions.at(index));

			// Ver se ja foi visitado
			exists = existsInVector(positions2, newPair);

			// Colocar no vetor dos visitados
			allPositions.push_back(newPair);

			// Por no vetor dos locais visitados
			if(exists){
				positions2.push_back(newPair);
			}

			index++;
		}
	}

	cout << positions.size() + positions2.size();

}


