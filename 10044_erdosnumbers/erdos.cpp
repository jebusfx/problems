#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

int count_to_erdos;
map<string,string> authors;
map<string,int> processed;
regex reg_name("[a-zA-Z]+,[ ]*([a-zA-z][\\.]*)+");	
regex_iterator<string::iterator> search_rit;
regex_iterator<string::iterator> rend;

int search_erdos(string author,string last_author=""){
	if(authors[author].find("Erdos, P.") != -1)
		return 1;
	else if(authors[author] == "")
		return -1;
	else{
		search_rit = regex_iterator<string::iterator> (authors[author].begin(), authors[author].end(),reg_name);
		processed[author] = 1;
		while(search_rit != rend){
			if(search_rit->str().compare(last_author) != 0 && processed[search_rit->str()] == 0){				
				count_to_erdos = search_erdos(search_rit->str(),author);
				if(count_to_erdos > 0)
					return ++count_to_erdos;
			}
			++search_rit;	
		}
	}
	return -1;
}

int main(){	
	int nscenarios,n,p,result,count_scenario = 1;
	string name,papers;	
	regex_iterator<string::iterator> rit;
	regex_iterator<string::iterator> aux_rit;	
	scanf("%d",&nscenarios);	
	while(nscenarios--){
		scanf("%d%d\n",&p,&n);
		while(p--){
			getline(cin,papers);			
			rit = regex_iterator<string::iterator> (papers.begin(), papers.end(),reg_name);
			while(rit != rend){				
				aux_rit = regex_iterator<string::iterator> (papers.begin(), papers.end(),reg_name);	
				while(aux_rit != rend){
					if(aux_rit->str().compare(rit->str()) != 0){						
						authors[rit->str()] += aux_rit->str() + ' ';
					}
					++aux_rit;
				}
				++rit;
			}
		}
		printf("Scenario %d\n", count_scenario++);
		while(n--){
			getline(cin,name);
			rit = regex_iterator<string::iterator> (name.begin(), name.end(),reg_name);					
			result = search_erdos((*rit).str());			
			cout << rit->str() << ' ';
			if(result <= 0)
				cout << "infinity" << endl;
			else
				cout << result << endl;
			processed.clear();

		}
		authors.clear();
	}
	return 0;	
}
