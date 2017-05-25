#include "bmaPreprocessing.cpp"


/* Compile with g++ 
g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

void tester(char mychar){
	int systemAnswer = Last(mychar);
	cout << "Systems answer for: " << mychar << " is:"<< systemAnswer << "\n";
	//cout << "Correct answer is:" << myanswer ;
}

void test(string samplepattern){
	calculateLast(samplepattern);
	cout <<"\n";
	cout << "#########################################################################" << "\n";
	cout << "Test : pattern is:" << samplepattern  << "\n";
	cout << "#########################################################################" << "\n";
	for (int k = 0; k < No_Of_Chars; k++) {
		tester((char) k);
	}
	
}

int main()
{
	test("");
	cout <<"**********************************************" <<"\n";
	cout << "All the characters of the alphabetArray should be -1"  << "\n";
	test("abcdefghijklmnopqrstuvwxyz");
	cout <<"**********************************************" <<"\n";
	cout << "answers should be from a=0 to z=25" << "\n";
	test("a a a a a a b a");
	cout <<"**********************************************" <<"\n";
	cout << "a = 14 ,b = 12 , \" \" =  13" << "\n";
	test("!@#$&*9)(''''':''''");
	cout <<"**********************************************" <<"\n";
	cout << "! = 0 , @ = 1 , # = 2 , $ = 3 , & = 4 , * = 5 , 9 = 6 , ) = 7 , ( = 8 , ' = 18 , : = 14"  << "\n";
	test("0000000_000000000000000_000000000_0000 00000");
	cout <<"**********************************************" <<"\n";
	cout << "0 = 43, _ = 33, \" \" = 38" << "\n"; 
	return 0;

	/* we can check any pattern by calling this test function */
}