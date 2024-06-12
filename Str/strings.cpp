#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b;
    cin >> a;
    cin >> b;
    
    string aa =  a;
    string bb = b;

    aa[0] = b[0];
    bb[0] = a[0];
    
    cout << a.length()<<" " <<b.length() << endl;
    cout << a + b << endl;
    cout << aa << " " << bb <<endl;
    
  
    return 0;
}