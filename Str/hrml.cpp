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
    // vector<string> hrml_container;
    // for (int i = 0; i < N; i++)
    // {
    //     getline(cin, line);
    //     if (line.empty())
    //     {
    //     }
    //     else
    //     {
    //         hrml_container.push_back(line);
    //     }
    // }

    // vector<string> q_container;

    // for (int i = 0; i < Q; i++)
    // {
    //     getline(cin, line);
    //     q_container.push_back(line);
    // };

    // ---------------------------------------------------------------
    vector<string> hrml_container;

    // Option 1: Pre-defined lines (assuming you have the content ready)
    hrml_container.push_back("<tag1 value = \"HelloWorld\">");
    hrml_container.push_back("<tag2 name = \"Name1\">");
    hrml_container.push_back("</tag2>");
    hrml_container.push_back("</tag1>");

    vector<string> q_container;

    // Define the input strings (replace with your actual input method)
    string input1 = "<tag1 tag1.tag2~name>";
    string input2 = "tag1~name>";
    string input3 = "tag1~value>";

    // Add each input string to the vector
    q_container.push_back(input1);
    q_container.push_back(input2);
    q_container.push_back(input3);

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
    for (const auto &pair : attributes)
    {
        std::cout << pair.first << " :: " << pair.second << '\n';
    }

    cout << "------------\n";

    for (auto &&i : tag_stack)
    {
        cout << i << endl;
    }
}
