# CS303-Assignment1
Contains my Assignment 1 code with 3 files - main.cpp, Functions.cpp. and Functions.h

// Brief description of my code //
This code contains a file that reads integer values from 0-100 into a fixed array of size 100. It then enters a while loop inside main that requires a user input to access the functions within the program.

// Functions //
Function 1 (numInArray) - Searches for a given value in the array and returns the index.
Function 2 (changeArrayValue) - Takes user input for an index and a value. Modifies the value at the given index with the given value. Returns the old/new values.
Function 3 (addNumArray) - Appends a given value to the end of the array if size is < 100.
Function 4 (removeNumArray) - Removes a value at a given index.

Requires download of main.cpp, Functions.cpp, Functions.h, and A1input.txt.

<img width="303" alt="Screenshot 2025-06-16 at 6 59 03 PM" src="https://github.com/user-attachments/assets/043c5314-f14b-4b65-98ef-5e8140e15f43" />
// How to run the program //
This is what initially is shown when you run main. The user must input values 0-5, any other input will be invalidated but the loop will continue to run.
If the user enters 0, it will display the array and show the current size.
If the user enters values 1-4, the respective function is called.
If the user enters 5, the code exits.
