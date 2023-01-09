#include <string>
#include <iostream>

std::string to_lower(std::string s) {
    for(char& c: s)
        c=std::tolower(c);
    return s;
}

std::string to_upper(std::string s) {
    for(char& c: s)
        c=std::toupper(c);
    return s;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string s;
    std::cin>>s;

    // convert to lower case
    std::for_each(s.begin(), s.end(), [](char& c) {
        c=std::tolower(c);
    });

    std::cout<<s<<std::endl;
    
    // convert to upper case
    std::for_each(s.begin(), s.end(), [](char& c) {
        c=std::toupper(c);
    });
    
    std::cout<<s<<std::endl;

    std::cout<<std::endl<<"Using custom function"<<std::endl;
    std::cout<<to_lower(s)<<std::endl;
    std::cout<<to_upper(s)<<std::endl;

    return 0;
}
