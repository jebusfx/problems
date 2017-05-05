#include <stdio.h>
#include <string.h>

#ifndef MAX_LETTERS
#define MAX_LETTERS 52
#endif

#ifndef NDIRS
#define NDIRS 8
#endif

char grid[MAX_LETTERS][MAX_LETTERS];

void str_tolower(char* str)
{
	int i;
	for(i = 0; i < strlen(str); i++)
		*(str + i) = tolower(*(str + i));
	return;
}

void str_strip(char* str)
{
	int i;	
	for(i = 0;i < strlen(str) && str[i] != '\n'; i++);
	*(str + i) = '\0';	
}

void processCounters(int dir, int *i,int *j)
{
	switch(dir)
	{
		case 0:
			(*i)--;
			(*j)--;
			break;
		case 1:
			(*i)--;
			break;
		case 2:
			(*i)--;
			(*j)++;
			break;
		case 3:
			(*j)--;
			break;
		case 4:
			(*j)++;
			break;
		case 5:
			(*i)++;
			(*j)--;
			break;
		case 6:
			(*i)++;
			break;
		case 7:
			(*i)++;
			(*j)++;
			break;
	}
	return;
}

int search(char* word, int startI, int startJ, int n, int m)
{
	int wordCounter, dir, i, j;
	for (dir = 0; dir < NDIRS; ++dir)
	{
		for (wordCounter = 0, i = startI, j = startJ; i < n && j < m && i >= 0 && j >=0 && word[wordCounter] == grid[i][j] && word[wordCounter] != '\n'; wordCounter++, processCounters(dir,&i,&j));
		if(wordCounter == strlen(word))
			return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int ncase;
	scanf("%d\n", &ncase);
	while(ncase--){
		int i,j,k,n,m,nwords;
		scanf("%d %d\n",&n,&m);
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < m;j++)
			{
				if(j==m)
					scanf("%c",&grid[i][j]);
				else
					scanf("%c\n",&grid[i][j]);
				grid[i][j] = tolower(grid[i][j]);
			}
		}
		scanf("%d\n",&nwords);
		char words[nwords][MAX_LETTERS];
		for (i = 0; i < nwords; ++i)
		{
			fgets(words[i], MAX_LETTERS, stdin);
			str_tolower(words[i]);
			str_strip(words[i]);
		}
		int found = 0;
		for (k = 0; k < nwords; ++k)
		{
			found = 0;
			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < m; ++j)
				{
					if(words[k][0] == grid[i][j])
					{
						if(search(words[k], i, j, n, m))
						{							
							found = 1;
							break;
						}
					}
				}
				if(found)
				{
					printf("%d %d\n", i+1, j+1);
					break;
				}
			}
		}
		memset(grid, 0, MAX_LETTERS*MAX_LETTERS);
		if(ncase)
			printf("\n");
	}
	return 0;
}
