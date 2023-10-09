#include <iostream>
#include "Cards.h"
#include <cstdlib>
#include <ctime>


int main() {

	// seed the randomizer
	srand(static_cast<unsigned int>(time(0)));	// using unsigned int, cuz time won't be negative
    int testCount = 1000000;


	// Output the number
	int pickWithReplacement{ 0 };
	for (int i = 0; i < testCount; i++) {
		pickWithReplacement += getPickCountNeededForFourSuits(false, true);
	}
	std::cout << "Avg picks for 4 suits (random with replacment): " << pickWithReplacement / static_cast<double>(testCount) << std::endl;

	int pickWithoutReplacement{ 0 };
	for (int i = 0; i < testCount; i++) {
		pickWithoutReplacement += getPickCountNeededForFourSuits(false, false);
	}

	std::cout << "Avg picks for 4 suits (random without replacement): " << pickWithoutReplacement / static_cast<double>(testCount) << std::endl;

	return 0;
}
