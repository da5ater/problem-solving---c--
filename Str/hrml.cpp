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
    // int N /*number of lines in the HRML program*/, Q /*number of queries*/;
    // cin >> N >> Q;
    // string line;
    // vector<string> hml_container;
    // for (int i = 0; i < N; i++)
    // {
    //     getline(cin, line);
    //     if (line.empty())
    //     {
    //     }
    //     else
    //     {
    //         hml_container.push_back(line);
    //     }
    // }

    // vector<string> q_container;

    // for (int i = 0; i < Q; i++)
    // {
    //     getline(cin, line);
    //     q_container.push_back(line);
    // };

    // ---------------------------------------------------------------
    vector<string> hml_container;

    // Option 1: Pre-defined lines (assuming you have the content ready)
    hml_container.push_back("<tag1 value = \"HelloWorld\">");
    hml_container.push_back("<tag2 name = \"Name1\">");
    hml_container.push_back("</tag2>");
    hml_container.push_back("</tag1>");

    vector<string> q_container;

    // Define the input strings (replace with your actual input method)
    string input1 = "<tag1 tag1.tag2~name";
    string input2 = "tag1~name";
    string input3 = "tag1~value";

    // Add each input string to the vector
    q_container.push_back(input1);
    q_container.push_back(input2);
    q_container.push_back(input3);

    //----------------------------------------------------------------

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

            regex attr_regex(R"((\w+)=["']([^"']+)["'])");
            smatch match;
            string tag = hml_container[i];
            while (regex_search(tag, match, attr_regex))
            {
                path_attribute[match[1].str()] = match[2].str();
                tag = match.suffix().str();
            }
        }
    }

    for (auto &pair : path_attribute)
    {
        cout << pair.first << "::" << pair.second << endl;
    }
}
