#ifndef PARSER
#define PARSER

#include <string>
#include <map>
#include <vector>
#include <set>

enum class Operation: char {
    Addition = '+',
    Multiplication = '*',
    Xor = '^',
    Negation = '!',
    LeftBrace = '(',
    RightBrace = ')'
};


class ExpressionParser {
public:
    ExpressionParser(std::string infix_expr);

    bool calculate(int values);
    void print_postfix();
private:
    static std::map<Operation, int> operation_priority;

    static void delete_spaces(std::vector<char> &expr);
    static bool is_variable(char c);
    static bool execute_operation(Operation operation, char value1, char value2);

    std::set<char> variables;
    std::vector<char> infix_expr, postfix_expr;

    void convert_to_postfix();
    bool determine_value(int values, char variable);
};

#endif