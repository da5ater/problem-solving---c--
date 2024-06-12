#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, string> sample_map { { 1, "one"}, { 2, "two" } };
  sample_map[3] = "three";
  sample_map.insert({ 4, "four" });

  map<int, string>::iterator it;
  for (it = sample_map.begin(); it != sample_map.end(); it++) {
    cout << it->first << " " << it->second << " ";
  }
cout << endl;


map<int, map<int, string> > nested_map;

nested_map[1][1] = "one";

cout << nested_map[1][1] << endl;
}