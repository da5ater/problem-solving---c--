#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream obj(str);
    
    int buffer;
    vector<int> vec;
    char ch;
    while (obj >> buffer) {
    
        vec.push_back(buffer);
        obj >>ch;
            
    }
    return vec ;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}