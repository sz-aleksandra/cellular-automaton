#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

#include <iostream>

class CellularAutomaton {
private:
    unsigned long long evolution_function;
    std::string state;
    std::string const lcr_array[27] = {"333", "332", "331", "323", "322", "321", "313", "312", "311", "233", "232", "231", "223", "222", "221", "213", "212", "211", "133", "132", "131", "123", "122", "121", "113", "112", "111"};
    int evolution_function_base3_plus_1[27] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

public:
    CellularAutomaton(unsigned long long evolution_function_no, std::string initial_state);
    std::string operator()();
    friend std::ostream& operator<<(std::ostream& os, CellularAutomaton& ca);
};

#endif