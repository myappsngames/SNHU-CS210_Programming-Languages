# SNHU CS-210 Project Three (Item Tracker Program)
This project is the third and final project for the CS 210 Programming Languages course at SNHU. The project is an item-tracking program that analyzes text records The Corner Grocer (grocery store) generates throughout the day providing information on how often items are purchased.

# Reflection
### Summarize the project and what problem it was solving.
  * The C++ grocery item project solves the problem of manually tracking grocery item frequencies. Manually keeping track of frequently purchased grocery items can be cumbersome and can also lead to inaccuracies and inefficiencies. The GroceryTracker class provides a solution by reading a grocery data file, analyzing that file, and storing the frequency of each grocery item in a std::map. The GroceryTracker class offers functionalities like searching for a specific grocery item and displaying their frequencies, printing a complete list of items and their corresponding frequencies, and saving the complete list of data in a .dat file.

### What did you do particularly well?
  * I was able to understand the problem and accurately grasp the challenge of manually tracking grocery item frequencies and the desired functionalities of the GroceryTracker class. I also effectively utilized C++ features like classes, std::map, file I/O, and basic error handling to create a functional program.

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  * More robust error handling:
    * The current error handling does not catch potential exceptions during file operations. Adding robust error handling will provide more informative error messages to the user.
  * Input validation for handling strings:
    * The current code does not explicitly handle strings as input for menu choices. The implementation of input validation for handling strings will improve user experience and prevent program crashes.
  * User experience enhancements:
    *  The current code does not show how many items were read and analyzed from a file. The implementation of displaying the item count to the user will increase user awareness and reduce errors.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  * The most challenging piece of code to write was the searchForItem() method. I was not sure how to search for a particular item using a std::map. I overcame this by referring back to the Zbyooks CS 210: Programming Languages section on std::map. I also referenced the C++ documentation on std::map on the website cplusplus.com. I will be adding Zybooks and C++ documentation as resources to my support network going forward.

### What skills from this project will be particularly transferable to other projects or course work?
  * Object-Oriented Programming (OOP) Concepts
    * Designing a class to encapsulate data and functionalities
    * Utilizing member functions to perform specific tasks within a class
  * C++ Fundamentals:
    * Applying core C++ concepts like std::map for storing item frequencies as key-value pairs
    * Utilizing std::ifstream and std::ofstream for file I/O operations
    * Employing basic error handling techniques such as checking if files are opened successfully
  * Problem-Solving and Algorithm Design:
    * Breaking down the task of tracking grocery item frequencies into smaller, manageable steps
    * Implementing algorithms for reading and processing data from a file
    * Designing functions to search for specific items and display data in various formats
  * User Interface Design:
    * Creating a text-based menu for user interaction with the program
    * printing informative messages to guide the user and displaying results
      
### How did you make this program maintainable, readable, and adaptable?
  * The program is readable by using meaningful names for variables and functions, proper indentation, and comments to enhance code clarity and understanding.
  * The program is maintainable and adaptable because of its modular design. The code is organized into a class with well-defined member functions and modifications can be made within specific functions without affecting the entire program. The modular design allows for the program to adapt to future changes. Future changes might include different input/output formats and handling different item data. They may also include integration with other systems and adding more functionality to the program.

