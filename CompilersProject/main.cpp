#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("Input.txt","r",stdin);
    string s;
    string comment = "";
    int caseNo;
    vector<pair<string,string>> tokens;
    string token = "";
    while(getline(cin, s))
    {
        int index = 0;
        while(index < s.length())
        {
            if(s[index] == ':')
            {
                caseNo = 3;
            } else if(s[index] == '{')
            {
                caseNo = 4;
            }

            switch(caseNo)
            {
                case 3:
                    if(s[index + 1] == '=') {
                        index++;
                        token = ":=";
                        tokens.push_back(make_pair(token, "Assignment"));
                    }
                    break;
                case 4:
                    token = "";
                    token += s[index++];
                    while(index < s.length() && s[index] != '}')
                    {
                        token += s[index++];
                    }

                    if(index < s.length())
                    {
                        token += '}';
                    }

                    tokens.push_back(make_pair(token, "Comment"));
                    break;
                default:
                    break;
            }
            index++;
            token = "";
            caseNo = 10;
        }
    }

    for(int i = 0; i < tokens.size(); i++) {
        cout << tokens[i].first << "   " << tokens[i].second << endl;
    }
}
