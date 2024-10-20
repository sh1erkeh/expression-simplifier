#include "../header-files/simplifyer.h"

#include <algorithm>

Simplifier::Simplifier(int number_of_variables, std::vector<maxterm> &maxterms) {
    this->number_of_variables = number_of_variables;
    std::copy(maxterms.begin(), maxterms.end(), std::back_inserter(this->maxterms));
    std::sort(this->maxterms.begin(), this->maxterms.end());
}

Simplifier::Simplifier() : Simplifier({}) {}

int maxterm::count_ones() {
    int counter = 0;
    for (size_t i = 0; i < value.size(); i++) {
        if (value[i] == Bit::True) {
            counter++;
        }
    }
    return counter;
}

bool maxterm::operator<(maxterm &other) {
    return this->count_ones() < other.count_ones();
}

std::vector<maxterm> Simplifier::simplify(int number_of_variables, std::vector<maxterm> &maxterms) {
    *this = Simplifier(number_of_variables, maxterms);

}