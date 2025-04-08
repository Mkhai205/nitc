#include "bits/stdc++.h"
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;

    while (true)
    {
        string s;
        getline(cin, s);
        if (s == ".") break;

        stack<char> st;
        bool isValid = true;

        for (char c : s)
        {
            if (c == '(' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }

        if (isValid && st.empty())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
