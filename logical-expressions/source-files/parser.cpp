#include "../header-files/parser.h"
#include <stack>
#include <algorithm>
#include <iostream>

using enum Operation;

ExpressionParser::ExpressionParser(std::string infix_expr) {
    for (char c : infix_expr) {
        this->infix_expr.push_back(c);
    }
    delete_spaces(this->infix_expr);
    convert_to_postfix();
}

bool ExpressionParser::calculate(int values) {
    std::stack<bool> locals;

    for (char c : postfix_expr) {
        if (is_variable(c)) {
            locals.push(determine_value(values, c));
        } else {
            Operation op = static_cast<Operation>(c);
            
            switch(op) {
                case Negation: 
                    {
                    bool variable = locals.top();
                    locals.pop();
                    locals.push(!variable);
                    break;
                    } 
                default: 
                    {
                    bool variable1 = locals.top();
                    locals.pop();
                    bool variable2 = locals.top();
                    locals.pop();
                    locals.push(execute_operation(op, variable1, variable2));
                    }
            }
        }
    }

    return locals.top();
}

void ExpressionParser::print_postfix() {
    for (char c : postfix_expr) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;
}

std::map<Operation, int> ExpressionParser::operation_priority { 
    {Addition, 1}, 
    {Xor, 2},
    {Multiplication, 3}, 
    {Negation, 4},
    {LeftBrace, 5},
    {RightBrace, 5}
};

void ExpressionParser::delete_spaces(std::vector<char> &expr) {
    int last_free_pos = 0;
    for (size_t i = 0; i < expr.size(); i++) {
        if (expr[i] != ' ') {
            expr[last_free_pos++] = expr[i];
        }
    }
    expr.resize(last_free_pos);
    expr.shrink_to_fit();
}

bool ExpressionParser::is_variable(char c) {
    return 'a' <= c && c <= 'z';
}

bool ExpressionParser::execute_operation(Operation op, char value1, char value2) {
    switch (op) {
        case Addition:
            return value1 | value2;
        case Multiplication:
            return value1 & value2;
        case Xor:
            return value1 ^ value2;
        default:
            return 0;
    }
}


void ExpressionParser::convert_to_postfix() {
    std::stack<Operation> operations;

    for (char c : infix_expr) {
        if (is_variable(c)) {
            variables.insert(c);
            postfix_expr.push_back(c);
        } else {
            Operation op = static_cast<Operation>(c);

            switch (op) {
                case LeftBrace:
                    operations.push(op);
                    break;
                case RightBrace:
                    while (!operations.empty() && operations.top() != LeftBrace) {
                        postfix_expr.push_back(static_cast<char>(operations.top()));
                        operations.pop();
                    }
                    operations.pop();
                    break;
                default:
                    while (!operations.empty() && operation_priority[operations.top()] >= operation_priority[op]) {
                        postfix_expr.push_back(static_cast<char>(operations.top()));
                        operations.pop();
                    }
                    operations.push(op);
            }
        }
    }

    while (!operations.empty()) {
        postfix_expr.push_back(static_cast<char>(operations.top()));
        operations.pop();
    }
}

bool ExpressionParser::determine_value(int values, char variable) {
    int index = distance(variables.begin(), variables.lower_bound(variable));
    return (values >> index) & 1;
}

int main() {
    std::string s = "a*b*c + a*!b*!c + b";
    ExpressionParser parser1{s};
    parser1.print_postfix();
    return 0;
}