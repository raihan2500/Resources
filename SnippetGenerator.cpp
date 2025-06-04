#include<vector>
#include <string>
#include<fstream>
#include <sstream>
#include <iostream>
using namespace std;

void vsCode(const string& input) {
    stringstream ss(input);
    string title;
    getline(ss, title);

    vector<string> codeLines;
    string line;
    while (getline(ss, line)) {
        codeLines.push_back(line);
    }

    string output = "{\n";
    output += "  \"" + title + "\": {\n";
    output += "    \"prefix\": \"" + title + "\",\n";
    output += "    \"body\": [\n";

    for (size_t i = 0; i < codeLines.size(); ++i) {
        output += "      \"";
        for (char c : codeLines[i]) {
            if (c == '\\') output += "\\\\";
            else if (c == '"') output += "\\\"";
            else output += c;
        }
        output += "\"";
        if (i + 1 < codeLines.size()) output += ",";
        output += "\n";
    }

    output += "    ],\n";
    output += "    \"description\": \"\"\n";
    output += "  }\n";
    output += "}\n";


    #ifdef w
        string output_filename = "/home/raihan/.config/Code/User/snippets/";
        output_filename += title;
        output_filename += ".code-snippets";

        ofstream out(output_filename);
        out << output << endl;
    #else
        cout << output << endl;
    #endif

}

void sublimeText(const string& input) {
    stringstream ss(input);
    string title;
    getline(ss, title);

    string content;
    string line;
    while (getline(ss, line)) {
        content += line + "\n";
    }

    string tabTrigger = title;
    for (auto& ch : tabTrigger) {
        if (!isalnum(ch)) ch = '_';
    }
    if (tabTrigger.empty()) tabTrigger = "snippet";

    string output;
    output += "<snippet>\n";
    output += "\t<content><![CDATA[\n";
    output += content;
    output += "\n]]></content>\n";
    output += "\t<tabTrigger>" + tabTrigger + "</tabTrigger>\n";
    output += "\t<scope>source.c++</scope>\n";
    output += "</snippet>\n";


    #ifdef w
        string output_filename = "/home/raihan/.config/sublime-text/Packages/User/";
        output_filename += title;
        output_filename += ".sublime-snippet";
        ofstream out(output_filename);
        out << output << endl;
    #else
        cout << output << endl;
    #endif
}

int main() {
    int type = 12;
    cout << "Reminder: Press Ctrl + D. after giving the input.\n";
    cout << "Enter 1 for sublimeText or 2 for VsCode else both: ";
    cin >> type;
    cin.ignore();

    string input, line;
    while (getline(cin, line)) {
        input += line + "\n";
    }

    if(type == 2 or type != 1)vsCode(input);
    if(type == 1 or type != 2)sublimeText(input);

    return 0;
}