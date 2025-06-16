#include "Functions.h"

int readFileToArray(string fileName, int arr[]) {
    ifstream inFile;

    // Open file and verify that it's valid
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }

    // Try block to throw any errors -> (out_of_range)
    try {
        int number;
        int count = 0;

        // Loop through file, assigning values with the corresponding index location value
        while (inFile >> number) {
            arr[count] = number;
            count++;
        }

        // Close file and return the size of the array
        inFile.close();
        return count;
    }

    // Catch out of range exception if too many values are added to array of fixed size 100
    catch (out_of_range e) {
        cout << "Exception: " << e.what() << endl;
        return -1;
    }
}

int numInArray(int arr[], int &currSize) {
    string userInputStr;

    // Try block to throw any errors -> (out_of_range & invalid_argument)
    try {
        // Get user input for value, and convert it to an integer
        cout << "Which number would you like to search for?: ";
        getline(cin, userInputStr);

        size_t pos;
        int userInput = stoi(userInputStr, &pos);

        // Check that the entire input is valid (no trailing characters)
        if (pos != userInputStr.length()) {
            throw invalid_argument("Input contains non-integer characters.");
        }

        // Iterate through the array and check if the number exists in the array
        // If true, return the index. Otherwise, exit loop
        for (int i = 0; i < currSize; i++) {
            if (arr[i] == userInput) {
                cout << "\nThe number " << userInput << " was found at index " << i << ".\n";
                return i;
            }
        }

        // If value is not found in array, return -1
        cout << "\nThe number " << userInput << " was not found in the array.\n";
        return -1;
    }
    // Catch out_of_range exception if accessed an index out of bounds
    catch (const out_of_range& e) {
        cerr << "\nOut of range exception thrown: " << e.what();
        return -1;
    }
    // Catch invalid_argument exception if user didn't input an integer
    catch (const invalid_argument& e) {
        cerr << "\nInvalid input, please enter an integer." << endl;
        return -1;
    }
}

pair<int, int> changeArrayValue(int arr[], int &currSize) {
    string indexInputStr, userInputStr;

    // Try block to throw any errors -> (out_of_range & invalid_argument)
    try {
        // Get user input for index location, and convert it to an integer with validation
        cout << "Which index location would you like to modify?: ";
        getline(cin, indexInputStr);

        size_t pos;
        int indexInput = stoi(indexInputStr, &pos);

        // Check that the entire input is valid (no trailing characters)
        if (pos != indexInputStr.length()) {
            throw invalid_argument("Input contains non-integer characters.");
        }

        // Check if indexInput is within bounds
        if (indexInput < 0 || indexInput >= currSize) {
            throw out_of_range("Index is out of range");
        }

        // Access the current value at the index
        cout << "\nThe number at index " << indexInput << " is -> " << arr[indexInput] << endl;
        int oldNum = arr[indexInput];

        // Get user input for new value, with validation
        cout << "What number would you like to change it to?: ";
        getline(cin, userInputStr);

        // Check that the entire input is valid (no trailing characters)
        int userInput = stoi(userInputStr, &pos);
        if (pos != userInputStr.length()) {
            throw invalid_argument("Input contains non-integer characters.");
        }

        // Update the array and display the change
        arr[indexInput] = userInput;
        cout << "\nThe previous number " << oldNum << " was modified to " << userInput << endl;

        return make_pair(userInput, oldNum);
    }
    // Catch out_of_range exception if accessed an index out of bounds
    catch (const out_of_range& e) {
        cerr << "\nOut of range exception thrown: " << e.what() << endl;
        return make_pair(-1, -1);
    }
    // Catch invalid_argument exception if user didn't input an integer
    catch (const invalid_argument& e) {
        cerr << "\nInvalid input, please enter a valid integer." << endl;
        return make_pair(-1, -1);
    }
}

void addNumArray(int arr[], int arrSize, int &currSize) {
    string userInputStr;

    // Try block to throw any errors -> (out_of_range & invalid_argument)
    try {
        // Throw out_of_range if array is already at maximum size
        if (currSize >= arrSize) {
            throw out_of_range("Array is already at maximum size.");
        }

        // Get user input
        cout << "Which number would you like to append?: ";
        getline(cin, userInputStr);

        size_t pos;
        int userInput = stoi(userInputStr, &pos);

        // Validate for extra characters after the number
        if (pos != userInputStr.length()) {
            throw invalid_argument("Input contains non-integer characters.");
        }

        // Add the integer to the end of the array and update current size
        arr[currSize] = userInput;
        currSize++;

        cout << "\nThe number " << userInput << " was successfully appended. Array size is now -> " << currSize << endl;
    }
    // Catch out_of_range exception if accessed an index out of bounds
    catch (const out_of_range& e) {
        cerr << "\nOut of range exception thrown: " << e.what() << endl;
    }
    // Catch invalid_argument exception if user didn't input an integer
    catch (const invalid_argument& e) {
        cerr << "\nInvalid input, please enter a valid integer." << endl;
    }
}

void removeNumArray(int arr[], int &currSize) {
    string indexInputStr;

    // Try block to throw any errors -> (out_of_range & invalid_argument)
    try {
        cout << "Which index location would you like to remove?: ";
        getline(cin, indexInputStr);

        size_t pos;
        int indexInput = stoi(indexInputStr, &pos);

        // Check that the entire input is valid (no trailing characters)
        if (pos != indexInputStr.length()) {
            throw invalid_argument("Input contains non-integer characters.");
        }

        // Validate index bounds, also check for negative input
        if (indexInput < 0 || indexInput >= currSize) {
            throw out_of_range("Index is out of range");
        }

        int removedNum = arr[indexInput];

        // Shift elements left to fill the removed spot
        for (int i = indexInput; i < currSize - 1; i++) {
            arr[i] = arr[i + 1];
        }

        currSize--;

        cout << "\nThe value " << removedNum << " was removed from index " << indexInput << endl;
        cout << "The array's new size is now " << currSize << endl;
    }
    // Catch out_of_range exception if accessed an index out of bounds
    catch (const out_of_range& e){
        cerr << "\nOut of range exception thrown: " << e.what() << endl;
    }
    // Catch invalid_argument exception if user didn't input an integer
    catch (const invalid_argument& e) {
        cerr << "\nInvalid input, please enter a valid integer." << endl;
    }
}
