#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cstring>
#include <string>
#include <regex>

using namespace std;

int main()
{
    int N /*number of lines in the HRML program*/, Q /*number of queries*/;
    cin >> N >> Q;

    string line;
    vector<string> hrml_container;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        if (line.empty())
        {
        }
        else
        {
            hrml_container.push_back(line);
        }
    }

    vector<string> q_container;

    for (int i = 0; i < Q; i++)
    {
        getline(cin, line);
        q_container.push_back(line);
    };

    //----------------------------------------------------------------
    map<string, string> attributes; // store tag attribute pairs
    vector<string> tag_stack;       // keep track of nested tags

    for (int i = 0; i < hrml_container.size(); i++) // do not forgent n
    {
        if (hrml_container[i].substr(0, 2) == "</") // closing tag
        {
            /* code */
        }
        else // openenig tag
        {
            string curated_tag = hrml_container[i].substr(1, hrml_container[i].size() - 2);

            stringstream ss(curated_tag);

            string tag_name, key, equal_sign, value;
            ss >> tag_name >> key >> equal_sign >> value;
            value = value.substr(1, value.size() - 2); // remove quotes

            string full_tag_name = "";
            if (!tag_stack.empty()) // not empty
            {
                full_tag_name = tag_stack.back() + "." + tag_name;
            }
            else
            { // empty
                full_tag_name = tag_name;
            }
            tag_stack.push_back(full_tag_name); // to access the tag

            attributes[full_tag_name + '~' + key] = value;
        }
    }

    for (int i = 0; i < q_container.size(); i++)
    {
        auto it = attributes.find(q_container[i]);
        if (it != attributes.end())
        {
            cout << it->second << endl;
        }
        else
        {
            cout << "Not Found!\n";
        }
    }
}
