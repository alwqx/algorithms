#include <map>
#include <iostream>

using namespace std;

int main() {

    map<string, string> mm;
    mm["E"] = "Excellent";
    mm["C"] = "Cheer";
    mm["N"] = "Nice";
    mm["U"] = "Ultimate";
    mm["Impossible"] = "I'm possible";
    mm["ACM"] = "Accept More";

    int n;
    string s;
    cin>>n;
    while(n--) {
        cin>>s;
        cout<<mm[s]<<endl;
    }

    return 0;
}