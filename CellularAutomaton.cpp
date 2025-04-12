#include "CellularAutomaton.hpp"
#include <algorithm>
#include <string>

CellularAutomaton::CellularAutomaton(unsigned long long evolution_function_no, std::string initial_state) {
	evolution_function = evolution_function_no;
	state = initial_state;
  	int index = 26;
  	while ((evolution_function > 0) && (index >= 0)) {
		evolution_function_base3_plus_1[index] += evolution_function % 3;
		evolution_function /= 3;
		index--;
  	}
}

std::string CellularAutomaton::operator()() {
	std::string result = "";
	std::string lcr;

	for (int i = 0; i < state.size(); i++) {
		lcr = state.substr((i - 1) % state.size(), 1) + state.substr((i) % state.size(), 1) + state.substr((i + 1) % state.size(), 1);
		int index = std::find(lcr_array, lcr_array + 27 , lcr) - lcr_array;
		result += std::to_string(evolution_function_base3_plus_1[index]);
  	}
  	state = result;

	return state;
}

std::ostream& operator<<(std::ostream& os, CellularAutomaton& ca) {
	os << ca();

  	return os;
}