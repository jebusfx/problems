#include <iostream>
#include <utility>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<char, int>  &p1, const pair<char, int> &p2)
{
    return p1.second > p2.second;

}

int is_char(char x){
	return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int main(){
	int n;
	vector<pair<char,int> > hashV;
	map<char,int> hash;
	string line;
	hashV.reserve(28);
	cin>>n;
	while(n>-1){
		getline(cin,line);
		for(int i = 0;i<line.length();i++)
			if(is_char(line[i]))
				hash[toupper(line[i])]++;							
		n--;
	}
	copy(hash.begin(), hash.end(),back_inserter(hashV));
	sort(hashV.begin(),hashV.end(),cmp);
	for(int i = 0;i<hashV.size();i++)
		if(hashV[i].second)
			cout<<hashV[i].first<<" "<<hashV[i].second<<endl;
	return 0;
}