#include <iostream>
#include <set>
#include <string>

void basic_less() {
    std::set<int> s;
    for(int i=0; i<3; ++i) {
        s.insert(i);
    }
    for(int e: s) {
        std::cout<<e<<std::endl;
    }
}

void basic_greater() {
    std::set<int, std::greater<int>> s;
    for(int i=0; i<3; ++i) {
        s.insert(i);
    }
    for(int e: s) {
        std::cout<<e<<std::endl;
    }
}

void pair_less() {
    std::set<std::pair<std::string, int>> s;
    s.insert({"B", 2});
    s.insert({"B", 1});
    s.insert({"C", 3});

    for(std::pair<std::string,int> e: s) {
        std::cout<<e.first<<" "<<e.second<<std::endl;
    }
}

void pair_greater() {
    std::set<std::pair<float, std::string>, std::greater<std::pair<float, std::string>>> s;
    s.insert({0.1, "Tom"});
    s.insert({-0.5, "Jane"});
    s.insert({10.2, "Eden"});

    for(std::pair<float, std::string> e: s) {
        std::cout<<e.first<<" "<<e.second<<std::endl;
    }
}

bool comp_func(std::pair<int, std::string> a, std::pair<int, std::string> b) {
    return a.second>b.second;
}

struct comp_st {
    bool operator() (const std::pair<int, std::string> a, const std::pair<int, std::string> b) const {
        return a.second<b.second;
    }
};

void pair_custom() {

    // using lambda
    auto comp_lambda = [] (std::pair<int, std::string> a, std::pair<int, std::string> b) -> bool {
        return a.second<b.second;
    };

    // for c++2a (2020)
    // std::set<std::pair<int, std::string>, decltype(comp_lambda)> s;

    // for c++11
    // std::set<std::pair<int, std::string>, decltype(comp_lambda)> s(comp_lambda);

    // using reference
    // std::set<std::pair<int, std::string>, decltype(&comp_func)> s(&comp_func);

    // using pointer
    // std::set<std::pair<int, std::string>, decltype(comp_func)*> s(comp_func);

    std::set<std::pair<int, std::string>, comp_st> s;
    s.insert({1, "C"});
    s.insert({2, "A"});
    s.insert({3, "B"});

    for(std::pair<int, std::string> e: s) {
        std::cout<<e.first<<" "<<e.second<<std::endl;
    }
}

int main() {
    //basic_less();
    //basic_greater();
    //pair_less();
    //pair_greater();
    pair_custom();
    return 0;
}
