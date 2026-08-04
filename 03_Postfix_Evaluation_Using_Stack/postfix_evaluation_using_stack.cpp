#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

int postfixEvaluation(string exp)
{
    stack<int> st;

    for (char c : exp)
    {
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            switch (c)
            {
                case '+':
                    st.push(a + b);
                    break;

                case '-':
                    st.push(a - b);
                    break;

                case '*':
                    st.push(a * b);
                    break;

                case '/':
                    st.push(a / b);
                    break;

                case '^':
                    st.push(pow(a, b));
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    string exp;

    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result: " << postfixEvaluation(exp);

    return 0;
}
