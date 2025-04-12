#include "CellularAutomaton.hpp"
#include "CellularAutomaton.cpp"
#include <fstream>
#include <cstring>

int is_correct(std::string state) {
	for (int i = 0; i < state.size(); i++) {
		if (state[i] < '1' || state[i] > '3') {
			return 0;
		}
	}

	return 1;
}

int is_a_number(std::string string) {
    for (int i = 0; i < string.size(); i++) {
		if (!std::isdigit(string[i])) {
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[]) {
	if ((argc == 4) && (is_a_number(argv[1])) && (std::atoll(argv[1]) >= 0) && (std::atoll(argv[1]) <= 7625597484986) && is_correct(argv[2]) && (is_a_number(argv[3])) && (std::atoi(argv[3]) >= 0)) {
		long long evolution_function_no = std::atoll(argv[1]);
		std::string initial_state = argv[2];
		int steps_no = std::atoi(argv[3]);
    	CellularAutomaton ca(evolution_function_no, initial_state);

		std::string filename = std::to_string(evolution_function_no) + "_" + initial_state + "_" + std::to_string(steps_no) + ".txt";
		std::ofstream result_file (filename);
		result_file << initial_state;
    	for (int i = 0; i < steps_no; i++) {
    		result_file << std::endl << ca;
    	}
		result_file.close();

		return 0;
	} else {
		std::cout << "Provide 3 arguments: evolution function number [0, 7625597484986], initial state (string longer than 3 characters made of 1s, 2s and 3s) and number of steps!" << std::endl;
		
		return -1;
	}
}