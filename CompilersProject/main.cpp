#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("input.txt","r",stdin);
    char x;
    string comment = "";
    int caseNo;
    while(cin>>x)
    {
        cout << "here" << endl;
        if(x == ':')
        {
            caseNo = 2;
        } else if(x == '{')
        {
            caseNo = 4;
            cout << "Here" << endl;
        }

        switch(caseNo)
        {
            case 4:
                comment += x;
                while(cin >> x && x != '}')
                {
                    comment += x;
                }

                comment += x;

                cout << comment << " : COMMENT" << endl;
                break;
        }
    }
}
