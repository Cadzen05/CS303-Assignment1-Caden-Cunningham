#include "Functions.h"

using namespace std;

int main() {
    // Initalize array, max size, current size, and userInput for main loop
    int arr[100];
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int currSize = 0;
    string userInputStr;

    // Call read file function to read numbers through A1input.txt and put into array
    cout << "Welcome to my array program!" << endl;
    cout << "Array's max size is 100." << endl;
    currSize = readFileToArray("A1input.txt", arr);

    // Main while loop to display the menu and take userInput (0-5)
    while (userInputStr != "5") {
        cout << "\n-------------------------------------\n";
        cout << "0. Display array\n";
        cout << "1. Find where integer exists in array\n";
        cout << "2. Replace integer in array\n";
        cout << "3. Append integer to end of array\n";
        cout << "4. Remove integer from array\n";
        cout << "5. Exit\n";
        cout << "What would you like to do?: ";

        getline(cin, userInputStr);
        int userInput;

        try {
            userInput = stoi(userInputStr);

            // Reject if number is longer than 1 digit
            if (userInputStr.length() != 1) {
                throw invalid_argument("Not a single-digit input.");
            }
        }
        // Catch invalid_argument exception if user didn't input an integer
        catch (const invalid_argument&) {
            cerr << "\nInvalid input. Please enter a number (0-5)." << endl;
            continue;
        }

        // Switch statement for values 0-5, any other input will call default and break
        switch (userInput) {
            case 0:
                // For userInput 0: Display current array and size
                cout << "\nArray: [";

                if (currSize == 0) {
                    cout << "]";
                }
                else {
                    for (int i = 0; i < currSize - 1; i++) {
                        cout << arr[i] << ", ";
                    }
                    cout << arr[currSize - 1] << "]";
                }

                cout << "\n\nArray size: " << currSize << endl;
                break;
            case 1:
                // For userInput 1: Call numInArray function with arguments (arr and currSize)
                numInArray(arr, currSize);
                break;
            case 2:
                // For userInput 2: Call changeArrayValue with argument (arr)
                changeArrayValue(arr, currSize);
                break;
            case 3:
                // For userInput 3: Call addNumArray with arguments (arr, arrSize, and currSize)
                addNumArray(arr, arrSize, currSize);
                break;
            case 4:
                // For userInput 4: Call removeNumArray with arguments (arr, arrSize, and currSize)
                removeNumArray(arr, currSize);
                break;
            case 5:
                // For userInput 5: Display final message and exit main loop
                cout << "\nThank you for using my array program!\n" << endl;
                break;
            default:
                // Default case for any userInput not (0-5), continue to loop
                cout << "\nNot a valid response. Please try again.\n";
                break;
        }
    }
    return 0;
}
