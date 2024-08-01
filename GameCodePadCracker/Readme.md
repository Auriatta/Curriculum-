#Brute Force Code Pad Cracker
##Overview
This project demonstrates a brute force method application created in C++. The program was initially created in 2015 and focuses on simulating keyboard inputs to crack a code pad in a game called "Zombi".
Key Features and Concepts Demonstrated

##Windows API Integration

Use of <Windows.h> for low-level system operations
Implementation of FindWindow(), GetWindowThreadProcessId(), OpenProcess(), and ReadProcessMemory() for interacting with other processes
Use of SendInput() for simulating keyboard inputs


##Memory Manipulation

Direct memory reading from another process using ReadProcessMemory()
Use of specific memory addresses to read game state


##Multithreading

Use of <process.h> for thread management
Implementation of _beginthread() and _endthread() for concurrent execution


##Input Simulation

Use of INPUT structure and SendInput() function to simulate keyboard events
Implementation of key press and release events

##Brute Force Algorithm

Implementation of a brute force algorithm to try all possible combinations


##Code Structure
The code is structured into several key components:

Header file (Header.h) containing necessary includes, global variables, and struct definitions
Main source file containing several functions:

getstatus: Monitors the game's memory state
moveBase: Simulates basic movement inputs
Symulacja: Implements the main brute force logic
movescombine: Sets up the movement patterns for each number
main: Initializes the program and handles user input



##Areas for Improvement

Code Organization: The code could benefit from being split into multiple files for better readability and maintainability.
Error Handling: More robust error handling could be implemented, especially for system calls.
Comments: Adding more comments would improve code readability and maintainability.
Internationalization: The code contains some Polish comments and variable names. Consistent use of English would improve international readability.
Input Validation: More thorough input validation could be implemented to handle unexpected user inputs.