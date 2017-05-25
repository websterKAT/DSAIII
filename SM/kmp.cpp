#include <iostream>
#include <string.h>
using namespace std;

void preProcessiong(char *pat,int *prefix,int m){
	int len = 0;
	prefix[0] = 0;

	int i = 1;
	while(i < m){
		if(pat[i] == pat[len]){
			len++;
			prefix[i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = prefix[len-1];
			}
			else{
				prefix[i] = 0;
				i++;
			}
		}
	}
	/*for (int i = 0; i < m; ++i)
	{
		cout << prefix[i];
	} */
	
}

void kmp(char *txt, char *pat){
	int n = strlen(txt);
	int m = strlen(pat);
	int pres[m];
	preProcessiong(pat,pres,m);
	int i=0;
	int j=0;
	while(i < n){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}
		if(j == m){
			cout << "pattern found at:" << (i-j) << "\n";
		}
		else if(i < n && pat[j] != txt[i]){
			if(j != 0){
				j = pres[j-1];
			}
			else{
				i = i+1;
			}
		}
	}
}
	
int main()
{
	char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    kmp(txt,pat);
    return 0;
}