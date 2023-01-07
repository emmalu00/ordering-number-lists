# Order-Numbers

## Project Description
This is a program in C that takes an input file as a command line argument. The input file contains several lists of numbers, each on separate lines. The program reorders these lists by size (smallest number of elements to most elements), and for each list, it sorts the numbers from least to greatest. 

## Running the Program
The input file will be taken as a command like argument. If the user does not enter a filename as a command line argument, the program will produce an error message and exit.

If you are using a Windows system, your program should then run with the statement:
> `./a.exe inputFile`

If you are using a Linux/Unix/Mac system, your program should run with the statement:
> `./a.out inputFile`

## Program Structure
In addition to the main method, the program contains the following separate functions:
* Sorting all the lists by length
* Helper method to swap lists
* Sorting all the elements in each list
* Helper method to swap elements
* Printing a list
