#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

int main()
{
    int N /*number of lines in the HRML program*/, Q /*number of queries*/;
    cin >> N >> Q;
    string line;
    vector<string> hml_container;
    for (int i = 0; i = N; i++)
    {
        getline(cin, line);
        hml_container.push_back(line);
    }

    vector<string> q_container;

    for (int i = 0; i < Q; i++)
    {
        getline(cin, line);
        hml_container.push_back(line);
    }

    stack<string> nested_tags;
    map<string, string> path_attribute;

    for (int i = 0; i < hml_container.size(); i++)
    {
        if (hml_container[i].find('/') != string::npos) // closing tag
        {
        }
        else
        { // opening tag
        }
    }
}