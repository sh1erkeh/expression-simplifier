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
    ExpressionParser();
    ExpressionParser(std::string infix_expr);

    ExpressionParser(const ExpressionParser&) = delete;
    // ExpressionParser& operator=(const ExpressionParser&) = delete;
    
    void load_expr(std::string infix_expr);
    std::vector<int> find_maxterms();
private:
    static std::map<Operation, int> operation_priority;

    static void delete_spaces(std::vector<char> &expr);
    static bool is_variable(char c);
    static bool execute_operation(Operation operation, char value1, char value2);

    std::set<char> variables;
    std::vector<char> infix_expr, postfix_expr;

    bool calculate_expr_value(int values);
    void convert_expr_to_postfix();
    bool determine_variable_value(int values, char variable);
};

#endif