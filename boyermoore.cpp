#include <string.h>
#include <iostream>
using namespace std;

int max(int x, int y) {
	return (x > y)? x:y;
}

void preProcessiong(char *str,int size, int badchar[128]){
	int i;
	for (i = 0; i < 128; i++) {
		badchar[i] = -1;	
	}
	for (i = 0; i < size; ++i) {
		badchar[(int) str[i]] = i;
	}

}

void search(char *txt, char *pat){
	int m = strlen(pat);
	int n = strlen(txt);
	int badchar[128];
	preProcessiong(pat,m,badchar);

	int s = 0;
	while(s <= (n-m)){
		int j = m-1;
		while(j >= 0 && pat[j] == txt[s+j]){
			j--;
		}


		if (j < 0){     cout << "Pattern occurs at shift:" <<  s << '\n' ;

			s += (s+m < n) ? m-badchar[txt[s+m]] : 1;
		}
		else 
			s += max(1, j - badchar[txt[s+j]]);
		
	}
}
int main(){
	char txt[] = "ABAAABCD";
	char pat[] = "ABC";
	search(txt,pat);
	return 0;
}

