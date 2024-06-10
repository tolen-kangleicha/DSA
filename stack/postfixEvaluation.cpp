#include <iostream>
#include <stack>
#include <string>

int postfixEvaluate( std::string &expression ) {
    std::stack<int> stack;
    for( char ch : expression ) {
        if( isdigit( ch ) ) {
            stack.push( ch - '0' );
        } else {
            int val1 = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();

            switch( ch ) {
                case '+': stack.push( val1 + val2 ); break;
                case '-': stack.push( val1 - val2 ); break;
                case '*': stack.push( val1 * val2 ); break;
                case '/': stack.push( val1 / val2 ); break;

            }
        }
    }

    return stack.top();
}

int main() {
    std::string expression;
    std::cout << "Enter a postfix expression: " << std::endl;
    std::cin >> expression;

    std::cout << "The result is " << postfixEvaluate( expression ) << std::endl;

    return 0;
}