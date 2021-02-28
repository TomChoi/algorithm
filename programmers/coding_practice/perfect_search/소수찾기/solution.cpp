#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

void solve(std::string numbers, std::unordered_set<int>& s) {
    std::string str = numbers;
   	int sz=str.size();
	if(!sz) return;    
   	do {
       	s.insert(stoi(str));	
    } while(std::next_permutation(str.begin(), str.end()));
    
    for(int i=0; i<sz; ++i) {
        std::string num = numbers;
        num.erase(i, 1);
        solve(num,s);
    }
}
bool check_primenumber(int n) {
    if (n<=1) return false;
    int i=1;
    while(n>++i) {
    	if(n%i == 0) return false;    
    }
    return true;
}

int solution(std::string numbers) {
    int answer = 0;
    std::unordered_set<int> s;
   	sort(numbers.begin(), numbers.end()); 
    solve(numbers, s);
    
    for(int e: s) {
        if(check_primenumber(e)) answer++;
    }
    
    return answer;
}
