#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string s;
    cin>>s;
    printf("%f\n", stof(s));

    float f;
    cin>>f;
    printf("%f\n", f);

    float f2=123.1234;
    printf("%f\n",f2);
    float f3=123.1234;

    if(f2==123.1234)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    
    if(f2==f3)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    
    return 0;
}
