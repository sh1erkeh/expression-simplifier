#include "../header-files/simplifyer.h"

// class Simplifyer {
// public:
//     void init(std::string &expression) {
//         parser.init(expression);
//         number_of_variables = parser.variables.size();
//     }

//     void simplify() {
//         std::vector<unit> maxterms = find_maxterms();
//     }
// private:
//     struct unit {
//         int counter;
//         std::vector<char> value;
//     };
//     ExpressionParser parser;

//     size_t number_of_variables;
//     std::set<std::vector<char>> ans;

//     std::vector<unit> find_maxterms() {
//         std::vector<unit> maxterms;
//         for (int value = 0; value < (1 << number_of_variables); value++) {
//             if (parser.calculate(value)) {
//                 int counter = 0;
//                 std::vector<char> maxterm(number_of_variables);

//                 for (size_t i = 0; i < number_of_variables; i++) {
//                     if (((value >> i) & 1)) {
//                         maxterm[i] = 1;
//                         counter++;
//                     } else {
//                         maxterm[i] = 0;
//                     }
//                 }
//                 maxterms.push_back({counter, maxterm});
//             }
//         }
//         sort(maxterms.begin(), maxterms.end(), comparator);
//         return maxterms;
//     }

//     bool comparator(unit &first, unit &second) {
//         return first.counter < second.counter;
//     }

//     bool minimize() {

//     }
// };  

