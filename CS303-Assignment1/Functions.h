#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//PRE:      fileName refers to the valid file containing values separated by whitespace
//          arr[] contains space to fill with values within fileName
//POST:     arr[] is filled with values contained in valid file in order
//          returns the size of the array into integer variable currSize
int readFileToArray(string fileName, int arr[]);

//PRE:      arr[] contains values in order from file and from previously modified functions
//          currSize contains the current size of the array
//POST:     takes user input for integer and checks if it exists in the array
//          returns the index of the given value
int numInArray(int arr[], int &currSize);

//PRE:      arr[] contains values in order from file and from previously modified functions
//POST:     takes user input for a specific index and takes user input for a value
//          replcaes the number at the given index with the user input and returns the old/new numbers
pair<int, int> changeArrayValue(int arr[], int &currSize);

//PRE:      arr[] contains values in order from file and from previously modified functions
//          arrSize contains the maximum size of the array and currSize contains the current Size
//POST:     takes user input for a number and appends to end of the array
void addNumArray(int arr[], int ARRSIZE, int &currSize);

//PRE:      arr[] contains values in order from file and from previously modified functions
//          currSize contains the current Size
//POST:     takes user input for an index and removes the value located at that index
void removeNumArray(int arr[], int &currSize);
