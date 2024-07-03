#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

void close_tag(stack<string> &tag_stack)
{
    tag_stack.pop();
}

void parse_tag(string &curated_tag, map<string, map<string, string>> &tag_map, stack<string> &tag_stack)
{
    stringstream ss(curated_tag);

    string tag_name, key, equal_sign, value;

    ss >> tag_name;

    string full_tag_name = "";

    if (!tag_stack.empty()) // not empty
    {
        full_tag_name = tag_stack.top() + "." + tag_name;
    }
    else
    { // empty
        full_tag_name = tag_name;
    }
    tag_stack.push(full_tag_name);

    while (ss >> key)
    {
        ss >> equal_sign >> value;

        value = value.substr(1, value.size() - 2); // remove quotes

        tag_map[full_tag_name + '~' + key] = value;
    }
}

int main()
{
    // int N /*number of lines in the HRML program*/, Q /*number of queries*/;
    // cin >> N >> Q;
    // cin.ignore();

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

    //----------------------------------------------------------------
    std::vector<std::string> hrml_container;

    hrml_container.push_back("<avalue=\"GoodVal\"><b>value=\"BadVal\"size=\"10\"></b><cheight=\"auto\"><dsize=\"3\"><estrength=\"2\"></e></d></c>");

    std::vector<std::string> q_container;

    q_container.push_back("a~value");
    q_container.push_back("b~value");
    q_container.push_back("a.b~size");
    q_container.push_back("a.b~value");
    q_container.push_back("a.b.c~height");
    q_container.push_back("a.c~height");
    q_container.push_back("a.d.e~strength");
    q_container.push_back("a.c.d.e~strength");

    //----------------------------------------------------------------
    map<string, map<string, string>> tag_map; // store tag attribute pairs
    stack<string> tag_stack;                  // keep track of nested tags

    for (int i = 0; i < hrml_container.size(); i++) // do not forge t n
    {
        if (hrml_container[i].substr(0, 2) == "</") // closing tag
        {
            close_tag(tag_stack);
        }
        else // openenig tag
        {
            string curated_tag = hrml_container[i].substr(1, hrml_container[i].size() - 2);
            parse_tag(curated_tag, tag_map, tag_stack);
        }
    }

    // for (int i = 0; i < q_container.size(); i++)
    // {
    //     auto it = tag_map.find(q_container[i]);
    //     if (it != tag_map.end())
    //     {
    //         cout << it->second << endl;
    //     }
    //     else
    //     {
    //         cout << "Not Found!\n";
    //     }
    // }
}
