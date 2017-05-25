#include <iostream>
using namespace std;

#define No_Of_Chars 128    //Assumption: Only Ascii characters in the pattern
int alphabetArray[No_Of_Chars];

void calculateLast(string pattern) {
	int patternLength = pattern.length();
	for (int i = 0; i < No_Of_Chars; i++) {
		alphabetArray[i] = -1;
	}

	for (int j = 0; j < patternLength; j++){
		alphabetArray[(int)pattern[j]] = j;
	}

}

int Last(char c){
	return alphabetArray[(int) c];
}


