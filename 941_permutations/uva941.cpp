#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

#define MAX 21

using namespace std;

char res[MAX];
int resCount;
unsigned long long int  factorials[MAX];

void factorial()
{
	factorials[0] = 1;
	factorials[1] = 1;
	for(int i = 2; i < MAX; i++)
	{
		factorials[i] = i * factorials[i - 1];
	}
}

void solve(string word, unsigned long long int q)
{
	int n = word.length();
	if(n == 1)
		res[resCount++] = word[0];
	else
	{
		unsigned long long int x = factorials[n - 1];
		unsigned long long int y = q/x;
		res[resCount++] = word[y];
		word.erase(y, 1);
		solve(word, q % factorials[n - 1]);
	}
}

int main(int argc, char const *argv[])
{
	int t, n;
	unsigned long long int q;
	scanf("%d\n", &t);
	factorial();
	while(t--)
	{
		string word;
		cin >> word;
		sort(word.begin(), word.end());
		scanf("%llu\n", &q);
		memset(res, 0, MAX);
		resCount = 0;
		solve(word, q);
		res[resCount] = '\0';
		printf("%s\n", res);
	}
	return 0;
}
