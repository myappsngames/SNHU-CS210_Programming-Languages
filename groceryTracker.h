#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

class GroceryTracker {
public:
	// Destructor - Frees memory allocated for the unordered_map
	~GroceryTracker() = default;

	// Copy Constructor - Creates a deep copy of the object
	GroceryTracker(const GroceryTracker& other);

	// Copy Assignment Operator - Performs a deep copy when assigning objects
	GroceryTracker& operator=(const GroceryTracker& other);

	// Analyzes the input file and stores item frequencies
	void AnalyzeFile(const std::string& filename);

	// Prompts user and returns the frequency of a specific item
	int GetFrequency(const std::string& item) const;

	// Prints the list of items with their frequencies
	void PrintFrequencyList() const;

	// Prints a histogram representation of item frequencies
	void PrintHistogram() const;

	// Saves item frequencies to a backup file (automatic)
	void SaveToFile() const;

private:
	// Stores item names (keys) and their frequencies (values)
	std::unordered_map<std::string, int> itemFrequencies_;

	// Filename associated with the item data
	std::string filename_;
};

#endif // GROCERYTRACKER_H