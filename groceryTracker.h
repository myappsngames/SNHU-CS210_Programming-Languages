#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>

class GroceryTracker {
public:
	// Default Constructor
	GroceryTracker();

	// Destructor - Frees memory allocated for the map
	~GroceryTracker() = default;

	// Analyzes the input file and stores item frequencies
	void analyzeFile(const std::string& filename);

	// Displays the menu to the user
	void displayMenu();

	// Searches for item
	void searchForItem();

	// Prints the list of items with their frequencies
	void printFrequencyList() const;

	// Prints a histogram representation of item frequencies
	void printHistogram() const;

	// Saves item frequencies to a backup file (automatic)
	void saveToFile() const;

private:
	// Stores item names (keys) and their frequencies (values)
	std::map<std::string, int> itemFrequencies_;

	// Filename associated with the item data
	std::string filename_;
};

#endif // GROCERYTRACKER_H
