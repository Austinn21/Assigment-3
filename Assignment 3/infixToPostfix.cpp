#include <queue>
#include <string>
#include <stack>

#include "Operand.h"

using namespace std;

queue<string> infixToPostfix(string exp) 
{   // delcares the stack to hold operators
    stack<char> st;
    // declares a queue to hold operands and operators in postfix order
    queue<string> q;
    // declares a string to hold multi-digit operands
    string operand;
    
    for (int i = 0; i < exp.length(); i++) 
    {
        char ch = exp[i];
        // if the character is an operand, append it to the current operand string
        if (isOperand(ch)) 
        {
            operand += ch;
            // if the operand is complete push it onto the postfix queue
            if (i == exp.length() - 1 || !isOperand(exp[i + 1])) 
            {
                q.push(operand);
                operand = "";
            }
        }
        /* if the character is an operator, pop operators from the stackand push them onto the postfix queue
        until a lower precedence operator is encountered or the stack is empty then push the current operator onto the stack */
        else if (isOperator(ch)) 
        {
            while (!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) 
            {
                q.push(string(1, st.top()));
                st.pop();
            }
            st.push(ch);
        }
        // if the character is an opening parenthesis, push it onto the stack
        else if (ch == '(') 
        {
            st.push(ch);
        }
        /* if the character is a closing parenthesis, pop operators from the stackand push them onto the postfix queue
        until an opening parenthesis is encountered, then discard the opening parenthesis */
        else if (ch == ')') 
        {
            while (!st.empty() && st.top() != '(') 
            {
                q.push(string(1, st.top()));
                st.pop();
            }
            if (!st.empty() && st.top() == '(') 
            {
                st.pop();
            }
            else 
            {
                // Unbalanced parentheses
                return queue<string>();
            }
        }
        else 
        {
            // Invalid character in the expression
            return queue<string>();
        }
    }
    // after all characters have been processed, pop any remaining operators from the stack and push them onto the postfix queue
    while (!st.empty()) 
    {
        if (st.top() == '(') 
        {
            // Unbalanced parentheses
            return queue<string>();
        }
        q.push(string(1, st.top()));
        st.pop();
    }
    return q;
}