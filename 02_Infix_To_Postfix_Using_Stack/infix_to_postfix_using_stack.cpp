#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperand(char c)
{
    return isalnum(c);
}

string infixToPostfix(string exp)
{
    stack<char> st;
    string result = "";

    for (char c : exp)
    {
        if (isOperand(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() &&
                   ((precedence(st.top()) > precedence(c)) ||
                    (precedence(st.top()) == precedence(c) && c != '^')))
            {
                result += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: " << infixToPostfix(exp);

    return 0;
}
