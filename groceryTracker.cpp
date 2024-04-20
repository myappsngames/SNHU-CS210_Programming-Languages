#include "groceryTracker.h"

#include <fstream>
#include <iostream>
#include <unordered_map>

GroceryTracker::GroceryTracker()
{
    // Initialize an empty map for storing item frequencies
    itemFrequencies_ = std::map<std::string, int>();
    // Optionally, initialize the filename member to an empty string
    filename_ = "";
}

void GroceryTracker::analyzeFile(const std::string& filename) {
    // Updates the item frequencies based on a grocery data file

    // Store the provided filename for potential future use
    filename_ = filename;

    // Attempt to open the input file for reading
    std::ifstream inputFile(filename);

    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        // Print an error message if the file cannot be opened
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return; // Exit the function if there's an error
    }

    // Declare a string variable to store each item read from the file
    std::string item;

    // Read the file line by line using a while loop
    while (inputFile >> item) {
        // Extract each item (word) from the file and store it in 'item'

        // Increment the frequency of the current item in the itemFrequencies_ map
        itemFrequencies_[item]++;
    }
    // close the input file after reading all data
    inputFile.close();

    // Save item and frequency data to frequency.dat file
    saveToFile();
}

void GroceryTracker::displayMenu() {
    // Presents a menu to the user for interacting with the GroceryTracker

    int choice; // Stores the user's menu selection

    // Loop to keep displaying the menu until the user exits (choice 4)
    do {
        // Print the menu header
        std::cout << "\nCorner Grocer Item Tracker" << std::endl;

        // Display menu options
        std::cout << "1. Search for item and return its frequency\n";
        std::cout << "2. Print Frequency List\n";
        std::cout << "3. Print Histogram" << std::endl;;
        std::cout << "4. Exit\n";

        // Prompt the user for their choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        // Handle user's menu selection using a switch statement
        switch (choice) {
        case 1:
            searchForItem();
            break;

        case 2:
            // Call the PrintFrequencyList function to display the list
            printFrequencyList();
            break;

        case 3:
            // Call the PrintHistogram function to display the histogram
            printHistogram();
            break;

        case 4:
            // Exit message
            std::cout << "Exiting program...\n";
            break;

        default:
            // Handle invalid choices
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4); // Continue looping until the user exits
}

void GroceryTracker::searchForItem()
{
    std::string item;
    // Prompt user for item name
    std::cout << "Enter the item name: ";
    std::cin >> item; // store input in item variable

    // Call GetItemFrequency to retrieve the item's frequency
    int frequency = itemFrequencies_[item];

    // Check if the item exists in the map
    if (itemFrequencies_.find(item) == itemFrequencies_.end()) {
        std::cout << item << " not found in the list.\n";
    }
    else {
        // Print the item and its frequency (if found)
        if (frequency == 1) {
            std::cout << item << " found " << frequency << " time." << std::endl;
        }
        else {
            std::cout << item << " found " << frequency << " times." << std::endl;
        }
    }
}

void GroceryTracker::printFrequencyList() const {
    // Prints a list of items and their frequencies in the itemFrequencies_ map

    std::cout << "Grocery Item Frequency list:\n"; // Print header message

    // Iterate through each item (key-value pair) in the itemFrequencies_ map
    for (auto const& item : itemFrequencies_) {

        // Access the item name (key) and frequency (value) from the current item
        std::string itemName = item.first;
        int frequency = item.second;

        // Print the item name and its frequency
        std::cout << item.first << " " << item.second << std::endl;
    }
}

void GroceryTracker::printHistogram() const {
    // Prints a histogram of item frequencies using asterisks

    std::cout << "Grocery Item Histogram:" << std::endl; // Print header message
    for (auto const& item : itemFrequencies_) {

        // Access the item name (key) and frequency (value) from the current item
        std::string itemName = item.first;
        int frequency = item.second;

        // Print the item name followed by asterisks representing its frequency
        std::cout << item.first << " ";
        for (int i = 0; i < item.second; i++) {
            // Print an asterisk for each occurrence of the item
            std::cout << "*";
        }
        std::cout << std::endl; // Move to the next line after each item's histogram
    }
}

void GroceryTracker::saveToFile() const
{
    // Saves the item frequencies data to a file

    // Open the output file using the filename member variable
    std::ofstream outputFile("frequency.dat");

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {

        // Print an error message if the file cannot be opened
        std::cerr << "Error: Could not open file " << filename_ << std::endl;
        return; // Exit the function if there's an error
    }

    // Iterate through each item (key-value pair) in the itemFrequencies_ map
    for (auto const& item : itemFrequencies_) {

        // Access the item name (key) and frequency (value) from the current item
        std::string itemName = item.first;
        int frequency = item.second;

        // Write the item name and its frequency to the output file
        outputFile << item.first << " " << item.second << std::endl;
    }

    // Close the output file after writing all data
    outputFile.close(); 
}
