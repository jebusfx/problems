#include <algorithm>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX	1000000

using namespace std;

int arr[MAX], lis[MAX], lis_id[MAX];
int lis_cnt;

int get_bound(int elem)
{
	int temp[lis_cnt];
	for(int i = 0; i < lis_cnt; i++)
	{
		temp[i] = arr[lis[i]];
	}
	return lower_bound(temp, temp + lis_cnt, elem) - temp;
}

int print_list(int index)
{
	int result = lis_id[index];
	if(result == -1)
		printf("%d\n", arr[index]);
	else
	{
		print_list(lis_id[index]);
		printf("%d\n", arr[index]);
	}
}

int get_last_elem_lis()
{
	if(lis_cnt == 0)
	{
		return INT_MIN;
	}
	else
	{
		return arr[lis[lis_cnt - 1]];
	}
}

int main(int argc, char const *argv[])
{
	int i = 0;
	memset(lis_id, -1, MAX*sizeof(int));
	lis[0] = INT_MAX;
	lis_cnt = 1;
	while(scanf("%d\n", &arr[i]) != EOF)
	{
		if(lis[0] == INT_MAX || arr[i] < arr[lis[0]])
		{
			lis[0] = i;
		}
		else if(arr[i] > get_last_elem_lis())
		{
			lis[lis_cnt] = i;
			lis_id[i] = lis[lis_cnt - 1];
			lis_cnt++;
		}
		else
		{
			int ceiling = get_bound(arr[i]);
			lis[ceiling] = i;
			lis_id[i] = lis[ceiling - 1];
		}
		i++;
	}
	printf("%d\n-\n", lis_cnt);
	print_list(lis[lis_cnt - 1]);
	return 0;
}
