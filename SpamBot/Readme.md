#Console Spambot
##Overview
This project demonstrates a console-based spambot application created in C++. The program was initially created in 2015 and focuses on keyboard events and states.
Key Features and Concepts Demonstrated

##Windows API Integration

Use of <windows.h> for low-level system operations
Implementation of keyboard events using keybd_event()


##Multithreading

Use of <process.h> for thread management
Implementation of _beginthread() and _endthread() for concurrent execution


##Function Pointers

Use of __cdecl calling convention for the spam function


##Code Structure
The code is structured into two main parts:

The spam function, which handles the actual spamming logic
The main function, which manages user input and program flow

##Areas for Improvement

Code Organization: The code could benefit from being split into multiple methods that could use classes for better readability and maintainability.
Error Handling: More robust error handling could be implemented to manage unexpected inputs or system states.
Comments: Adding more comments would improve code readability and maintainability.