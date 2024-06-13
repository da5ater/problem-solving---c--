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
            size_t start = hml_container[i].find('<') + 1;
            size_t end = hml_container[i].find('>') - 1;
            string open_tag = hml_container[i].substr(start, end);

            vector<pair<string, string>> attributes;
            size_t attr_start = start;

            while (true)
            {
                size_t attr_name_start = hml_container[i].find(" ", attr_start);
                if (attr_name_start == string::npos)
                    break;

                size_t attr_name_end = hml_container[i].find("=") - 1;
                string attr_name = hml_container[i].substr(attr_name_start, attr_name_end);

                size_t attr_value_start = attr_name_end;
                size_t attr_value_end   = hml_container[i].find(" ",
            }
        }
    }
}