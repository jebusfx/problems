#include <algorithm>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;


int main() {
    int n,max_element = 0;
    char line[256];
    char* token;
    stack<int> s, smax;
    scanf("%d\n",&n);
    while(n--){
        fgets(line,256,stdin);
        token = strtok(line," ");
        int ntokens = 0;
        int op,element = -1;
        while(token != NULL){            
            if(ntokens == 0)
                op = atoi(token);
            else
                element = atoi(token);
            token = strtok(NULL," ");
            ntokens++;
        }
        switch(op){
            case 1:
                s.push(element);
                if(smax.empty())
                    smax.push(element);
                else
                    if(element >= smax.top())
                        smax.push(element);
                break;
            case 2:
                if(smax.top() == s.top())
                    smax.pop();
                s.pop();
                break;
            case 3:
                printf("%d\n",smax.top());
                break;
            default:
                break;
        }
    }
    return 0;
}
