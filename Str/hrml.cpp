#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int N /*number of lines in the HRML program*/, Q /*number of queries*/;
    cin >> N >> Q;
    string line;
    vector<string> hml_container;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        if (line.empty())
        {
        }
        else
        {
            hml_container.push_back(line);
        }
    }

    vector<string> q_container;

    for (int i = 0; i < Q; i++)
    {
        getline(cin, line);
        q_container.push_back(line);
    };

    stack<string> nested_tags;
    map<string, string> path_attribute;

    for (size_t i = 0; i < hml_container.size(); i++)
    {
        if (hml_container[i].find('/') != string::npos) // closing tag
        {
        }
        else
        { // opening tag
            size_t space_pos = hml_container[i].find(" ");
            string tag_name = hml_container[i].substr(1, space_pos - 1);
            cout << "Tag name: " << tag_name << endl;
        }
    }
}
