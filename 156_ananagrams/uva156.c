#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAX_LETTERS
#define MAX_LETTERS 21
#endif

#ifndef MAX_CHARS
#define MAX_CHARS 81
#endif

#ifndef MAX_WORDS
#define MAX_WORDS 100000
#endif

int cmp_word(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int cmp(const void *a, const void *b)
{
	return *(const char *)a - *(const char *)b;
}

void str_tolower(char* str){
	int i;
	for(i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]);
	}
	return;
}

int* get_uniques(char swords [MAX_WORDS][MAX_LETTERS], int nwords, int* nuniques){
	int i, j, found = 0;
	int* uniques = (int*)malloc(sizeof(int)*MAX_WORDS);
	for(i = 0; i < nwords; i++){
		found = 0;
		for(j = 0; j < nwords; j++){
			if(i != j && strcmp(swords[i], swords[j]) == 0){
				found = 1;
				break;
			}
		}
		if(!found)
			uniques[(*nuniques)++] = i;
	}
	return uniques;
}

int main(int argc, char const *argv[])
{
	char line[MAX_CHARS];
	char swords[MAX_WORDS][MAX_LETTERS];
	char words[MAX_WORDS][MAX_LETTERS];
	int nwords = 0;
	/* fgets to avoid buffer overflow */
	while(fgets(line, MAX_CHARS, stdin) != NULL){
		if(line[0] == '#')
			break;
		/* split */
		char* token = strtok(line, " \n");		
		while(token != NULL){
			strncpy(words[nwords], token, MAX_LETTERS);
			str_tolower(token);
			/* sort to find duplicates */
			qsort(token, strlen(token), sizeof(char), cmp);
			strncpy(swords[nwords], token, MAX_LETTERS);			
			token = strtok(NULL, " \n");
			nwords++;
		}		
		free(token);
	}
	int i, nuniques = 0;
	/* get anagrams */
	int* uniques = get_uniques(swords, nwords, &nuniques);
	/* array to output sorted */
	char **result = (char**)malloc(sizeof(char**) * nuniques);
	for(i = 0; i < nuniques; i++){
		result[i] = (char*)malloc(sizeof(char*) * MAX_LETTERS);
		strncpy(result[i], words[uniques[i]], MAX_LETTERS);
	}
	qsort(result, nuniques, sizeof(char*), cmp_word);
	for(i = 0; i < nuniques; i++)
		printf("%s\n", result[i]);
	free(uniques);
	free(result);
	return 0;
}
