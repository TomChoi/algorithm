#include <string>
#include <iostream>
#include <unordered_set>

std::string solve(std::string numbers, std::unordered_set<int>& s) {
    std::string str = "";

    std::cout<<numbers<<std::endl;
   	int sz=numbers.size();
    for(int i=0; i<sz; ++i) {
        std::string num = numbers;
        str += num[i];
        num.erase(i, 1);
        str += solve(num,s);
        s.insert(std::stoi(str));
    }
    return str;
}

int solution(std::string numbers) {
    int answer = 0;
    std::unordered_set<int> s;

    solve(numbers, s);
    std::cout<<"SET"<<std::endl;
    for(int e: s) {
        std::cout<<e<<std::endl;
    }
    std::cout<<"==========="<<std::endl;

    return answer;
}

int main() {
    std::string str= "17";

    solution(str);
    return 0;
}

