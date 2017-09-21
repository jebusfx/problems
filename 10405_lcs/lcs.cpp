#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s1;
	while(getline(cin, s1))
	{
		string s2;
		getline(cin, s2);
		int lenS1 = s1.length() + 1;
		int lenS2 = s2.length() + 1;
		int lcs[lenS1][lenS2];
		int i,j;
		for(i = 0; i < lenS1; i++)
			lcs[i][0] = 0;
		for(i = 0; i < lenS2; i++)
			lcs[0][i] = 0;
		for(i = 1; i < lenS1; i++)
			for(j = 1; j < lenS2; j++)
				lcs[i][j] = s1[i - 1] == s2[j - 1] ? lcs[i - 1][j - 1] + 1 : max(lcs[i - 1][j], lcs[i][j - 1]);
		printf("%d\n", lcs[lenS1 - 1][lenS2 - 1]);
	}
	return 0;
}