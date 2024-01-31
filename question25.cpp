
#include<bits/stdc++.h>
using namespace std;

char myPair(char c)
{
    if (c == ')') return '(';
    if (c == ']') return '[';
    if (c == '}') return '{';
}

bool isLeftBrace(char c)
{
    if (c == '(') return 1;
    if (c == '[') return 1;
    if (c == '{') return 1;
    return 0;
}

bool isRightBrace(char c)
{
    if (c == ')') return 1;
    if (c == ']') return 1;
    if (c == '}') return 1;
    return 0;
}

void solve(string s)
{
    char stk[145];
    int top = -1;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isLeftBrace(c))
        {
            stk[++top] = c;
        }
        if (isRightBrace(c))
        {
            if (stk[top] == myPair(c))
            {
                top--;
            }
            else {
                cout << "Mismatch" << endl;
                return;
            }
        }
    }
    if (top == -1) cout << "Match" << endl;
    else cout << "Mismatch" << endl;
}

int main()
{
    char a[50];
    gets_s(a);
    while (a != "****00*")
    {
        solve(a);
        getchar();
        gets_s(a);
    }
    return 0;
}