#include <iostream>
#include <array>
#include <cstdlib>
#include "Cards.h"
#include <algorithm>


// Pick a random card from the deck (represented by an int between 0-52)
// - params: none
// - return: an int between 0 - 51
// pickRandomCard();
int pickRandomCard() {
	return rand() % Constants::CARD_COUNT;
}


// Get the rank of a specific card index
// - param 1: an int representing the card index
// - return: an enum representing the Rank of the card index given.
// getRank();
Rank getRank(int cardIndex) {

	int rankIndex{ cardIndex % static_cast<int>(Rank::Count) };

	return static_cast<Rank>(rankIndex);

};

// Get the suit of a specific card index
// - param 1: an int representing the card index
// - return: an enum representing the Suit of the card index given.
// getSuit();
Suit getSuit(int cardIndex) {
	
	int suitIndex{ cardIndex / static_cast<int>(Rank::Count) };

	return static_cast<Suit>(suitIndex);

};

// A function to assess whether all elements in a boolean array are true
// You can use this function to determine whether all suits have been picked.
// - param 1: an array of boolean values(decide if it should be const or not)
// - param 2: ? do we need any other parameters here to make this work? You decide.
// - return: a bool : true if ALL the elements in param 1 are true, false otherwise.
// allArrayElementsAreTrue();

bool allArrayElementsAreTrue(std::array<bool, 4> suits) {
	for (bool suitsPicked : suits) {
		if (!suitsPicked) {
			return false;
		}

	}
	return true;	// return true if all elements are true
};

// This is the function that does all the work behind solving the problem (including
// sending output to the console).
// This function should create/use an array of Boolean values (all initially false)
// to represent the suits that have been picked.
// It should make use of allArrayElementsAreTrue() to test if all suits have been
// picked.
// - param 1: a bool called ¡°verbose¡± (meaning wordy) that defaults to true.
// If verbose is true, generate output cards picked & the pick count.
// - return: an int representing the number of card picks it takes to cover 4 suits.
// getPickCountNeededForFourSuits();

int getPickCountNeededForFourSuits(bool verbose, bool useReplacement) {
	// create an array of Boolean values(all initially false)
	std::array<bool, 4> suitsPicked = { false, false, false, false };

	// representing the number of card picks
	int picksCount = 0;
	int cardPicks = 0;
    int deck[Constants::CARD_COUNT];
    
    if (!useReplacement) {
        for (int i = 0; i < Constants::CARD_COUNT; i++) {
            deck[i] = i;
        }
        std::random_shuffle(deck, deck + 52);
		// std::random_shuffle(deck[0], deck[52]);
    }
    
    
	// check all the suits have been pick
    int cardIndexIndeck = 0;
    
	while (!allArrayElementsAreTrue(suitsPicked)) {
		if (useReplacement) {
			cardPicks = pickRandomCard();
		}
		else {
			cardPicks = deck[cardIndexIndeck++];
		}

		// pick suit
		Suit suit = getSuit(cardPicks);
		// pick rank
		Rank rank = getRank(cardPicks);

		// mark the suit
		suitsPicked[static_cast<int>(suit)] = true;

		picksCount++;

		// output all the picked number
		if (verbose) {
			std::cout << Constants::RANK[static_cast<int>(rank)] << " of " << Constants::SUIT[static_cast<int>(suit)] << '\n';
		}
	}

	if (verbose) {
		std::cout << "Number of picks for iteration : " << picksCount << std::endl << '\n';
	}

	return picksCount;
};
