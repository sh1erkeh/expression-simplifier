#ifndef SIMPLIFYER
#define SIMPLIFYER

#include <string>
#include <vector>
#include <my_parser.h>

enum class Bit: char {
    False = 0,
    True = 1,
    Empty = 2
};

struct maxterm {
    std::vector<Bit> value;

    int count_ones();
    bool operator<(maxterm &other);
};

class Simplifier {
public:
    Simplifier();
    std::vector<maxterm> simplify(int number_of_variables, std::vector<maxterm> &maxterms);
private:
    Simplifier(int number_of_variables, std::vector<maxterm> &maxterms);

    int number_of_variables;
    std::vector<maxterm> maxterms;
};

#endif