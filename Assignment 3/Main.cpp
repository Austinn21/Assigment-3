#include <iostream>
#include <stack>
#include <string>
#include <queue>

#include "Operand.h"
#include "infixToPostfix.h"
#include "Balance.h"


using namespace std;


int main() 
{   // creats the string for the infix expression
    string infixExp;
    cout << "Enter infix expression: ";
    // gabes what the uses inputs
    getline(cin, infixExp);
    // runs the balance function to see if it is balanced and responds if it is 'Invaild"
    if (!isBalanced(infixExp)) 
    {
        cout << "Invalid Expression" << endl;
    }
    // the other responce as to it being 'Valid'
    else 
    {
        // grabs the que and the string from the infixTopostfix function
        queue<string> postfixExp = infixToPostfix(infixExp);
        cout << "Postfix expression: ";
        // runs a while loop to populate the postfix expression 
        while (!postfixExp.empty())
        {
            // pushes the corect postfix to the front of the empty stack
            cout << postfixExp.front() << " ";
            postfixExp.pop();
        }
        cout << endl;
        queue<string> q;


    }
    return 0;
}