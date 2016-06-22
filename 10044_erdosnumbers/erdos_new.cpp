#include <algorithm>
#include <limits.h>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <stdio.h>
#include <queue>

using namespace std;

map<string,string> authors;
map<string,string> author_parent;
map<string,int> author_level;
set<string> author_set;
set<string>::iterator sit;

regex reg_name("[a-zA-Z]+,[ ]*([a-zA-z][\\.]*)+");
regex_iterator<string::iterator> rend;	

void bfs(string root){	
	queue<string> q;
	string current;	
	for(sit = author_set.begin(); sit != author_set.end(); ++sit)
		author_level[*sit] = INT_MAX;		
	
	author_level[root] = 0;
	q.push(root);
	while(!q.empty()){
		current = q.front();
		q.pop();
		regex_iterator<string::iterator> rit (authors[current].begin(), authors[current].end(),reg_name);
		while(rit != rend){
			if(author_level[rit->str()] == INT_MAX){
				author_level[rit->str()] = author_level[current] + 1;
				author_parent[rit->str()] = current;
				q.push(rit->str());
			}
			++rit;
		}
	}
}

int main(){	
	int nscenarios,n,p,result,count_scenario = 1;
	string name,papers,author;
	regex_iterator<string::iterator> rit;
	regex_iterator<string::iterator> aux_rit;
	scanf("%d",&nscenarios);	
	while(nscenarios--){
		scanf("%d%d\n",&p,&n);
		while(p--){
			getline(cin,papers);			
			rit = regex_iterator<string::iterator> (papers.begin(), papers.end(),reg_name);
			while(rit != rend){				
				author_set.insert(rit->str());
				aux_rit = regex_iterator<string::iterator> (papers.begin(), papers.end(),reg_name);	
				while(aux_rit != rend){
					if(aux_rit->str().compare(rit->str()) != 0)		
						if(authors[rit->str()].find(aux_rit->str()) == -1)		
							authors[rit->str()] += aux_rit->str() + ' ';					
					++aux_rit;
				}
				++rit;
			}
		}
		bfs("Erdos, P.");		
		printf("Scenario %d\n", count_scenario++);
		while(n--){
			getline(cin,name);
			rit = regex_iterator<string::iterator> (name.begin(), name.end(),reg_name);			
			cout << rit->str() << ' ';
			if(author_level[rit->str()] == INT_MAX || author_level[rit->str()] == 0)
				cout << "infinity" << endl;
			else
				cout << author_level[rit->str()] << endl;
		}
		authors.clear();
		author_parent.clear();
		author_level.clear();		
		author_set.clear();
	}
	return 0;	
}
