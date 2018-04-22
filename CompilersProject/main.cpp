#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair <string,string > > tokens;

    freopen ("Input.txt","r",stdin);
    char x;
    string line;
    string comment = "";
    int caseNo;
    while(getline(cin,line))
    {


            int index=0;
        while(index<line.length())
        {

            string token="";

            if(line[index]>='0' && line[index] <='9')
            {
                caseNo = 1;
            }
            else if(line[index]>='A' && line[index] <='z')
            {
                caseNo=2;
            }
            else if(line[index] == ':')
            {
                caseNo = 3;
            }
            else if(line[index] == '{')
            {
                caseNo = 4;

            }
            else if(line[index] == ' ')
            {
                caseNo = 5;
            }
            else
            {
                caseNo = 6;
            }

            switch(caseNo)
            {
                case 1:
                while(line[index]>='0' && line[index] <='9')
                {
                    token+=line[index];
                    index++;
                }
                tokens.push_back(make_pair(token,"Number"));
                break;

                case 2:
                while(line[index]>='A' && line[index] <='z')
                {
                    token+=line[index];
                    index++;
                }

                if(token == "if" || token == "then" || token == "else" || token == "end"
                    || token == "repeat" || token == "until" || token == "read" || token == "write")
                {
                    tokens.push_back(make_pair(token, "Reserved Word"));
                } else
                {
                    tokens.push_back(make_pair(token,"ID"));
                }
                break;

                case 3:

                    if(line[index + 1] == '=') {

                        token = ":=";
                        index+=2;
                        tokens.push_back(make_pair(token, "Symbol"));

                    }
                    else index++;

                    break;
                case 4:
                    token = "";
                    token += line[index++];
                    while(index < line.length() && line[index] != '}')
                    {
                        token += line[index++];
                    }

                    if(index < line.length())
                    {
                        token += '}';
                        tokens.push_back(make_pair(token, "Comment"));
                    }


                    break;

                case 5:
                    index++;
                    break;
                case 6:
                    if(line[index] == '-' || line[index] == '+' || line[index] == '*'
                        || line[index] == '/' || line[index] == '=' || line[index] == '<'
                        || line[index] == '(' || line[index] == ')' || line[index] == ';')
                    {
                        token = line[index];
                        tokens.push_back(make_pair(token, "Symbol"));
                    }
                    index++;
                    break;
            }
        }

        tokens.push_back(make_pair("", ""));
    }

    for(int i =0; i<tokens.size(); i++)
    {
        cout<<tokens[i].first<<" "<<tokens[i].second<<endl;
    }
}
