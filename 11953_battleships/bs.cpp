#include <limits.h>
#include <map>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

char grid[101][101];
map<pair<int,int>,bool > visited;

//true vertical
//false horizontal
bool is_vertical(pair<int,int> root,int n){
	int x = root.first - 1;
	if(x > -1){
		if(grid[x][root.second] == 'x' || grid[x][root.second] == '@')
			return false;
	}
	x = root.first + 1;
	if(x < n){
		if(grid[x][root.second] == 'x' || grid[x][root.second] == '@')
			return false;
	}

	int y = root.second - 1;
	if(y > -1){
		if(grid[root.first][y] == 'x' || grid[root.first][y] == '@')
			return true;
	}
	y = root.second + 1;
	if(y < n){
		if(grid[root.first][y] == 'x' || grid[root.first][y] == '@')
			return true;
	}
}

pair<int,int> next_movement(bool is_vert,pair<int,int> root, int n, int direction){
	pair<int,int> next;
	int x,y;
	if(is_vert){
		switch(direction){
			case 1:
				y = root.second - 1;
				if(y < 0)
					y = INT_MAX;
				next = make_pair(root.first,y);	
				break;
			case 2:
				y = root.second + 1;
				if(y >= n)
					y = INT_MAX;
				next = make_pair(root.first,y);	
				break;			
		}
	}else{
		switch(direction){
			case 1:
				x = root.first - 1;
				if(x < 0)
					x = INT_MAX;
				next = make_pair(x,root.second);
				break;
			case 2:
				x = root.first + 1;
				if(x >= n)
					x = INT_MAX;
				next = make_pair(x,root.second);
				break;			
		}
	}
	return next;
}

int flood_fill(pair<int,int> root, int n){
	int direction;
	if(grid[root.first][root.second] != 'x')
		return 0;
	queue<pair<int,int> > q;
	pair<int,int> current,temp;
	q.push(root);	
	bool vertical = is_vertical(root,n);
	while(!q.empty()){
		current = q.front();
		q.pop();
		visited[current] = true;
		if(grid[current.first][current.second] == 'x' || grid[current.first][current.second] == '@'){
			grid[current.first][current.second] = '@';
			for(direction = 1; direction<=2; direction++){
				temp = next_movement(vertical,current,n,direction);
				if(temp.first != INT_MAX && temp.second != INT_MAX){
					if(visited[temp] == false && (grid[temp.first][temp.second] == 'x' || grid[temp.first][temp.second] == '@'))
						q.push(temp);
				}					
			}				
		}
	}
	return 1;
}

int main(){
	int ntest_cases,i,j,k,n,nships;
	vector<pair<int,int> > possible_ships;
	pair<int,int> temp;
	scanf("%d\n",&ntest_cases);
	for(i = 1; i <= ntest_cases; i++){
		scanf("%d\n",&n);
		nships = 0;
		memset(grid,'\0',sizeof(grid[0][0]) * 101 * 101);
		for(j = 0; j < n; j++){
			for(k = 0; k < n; k++){
				if(k == n - 1)
					scanf("%c\n",&grid[j][k]);
				else
					scanf("%c",&grid[j][k]);				
				if(grid[j][k] == 'x'){					
					temp = make_pair(j,k);
					possible_ships.push_back(temp);
				}					
			}
		}
		for(j = 0; j < possible_ships.size(); j++){
			nships += flood_fill(possible_ships[j],n);
		}
		printf("Case %d: %d\n",i,nships);
		possible_ships.clear();
		visited.clear();
	}
	return 0;
}
