Created at 2015
(2024 adnotation)
##Key Features:

##Object-Oriented Design:

Implements a CustomProcessManager class for process-related operations


##Windows API Integration:

Uses <Windows.h> and <shellapi.h> for advanced Windows functionality
Manipulates window properties and processes using Win32 API functions


##Process Management:

Provides methods to start, manipulate, and terminate processes


##Window Manipulation:

Implements setWindowParams() to control window position, size, and appearance
Uses MoveWindow(), SetWindowLong(), and SetWindowPos() for precise window control


##Process Execution:

Uses ShellExecuteEx() for flexible process creation


##Process Termination:

Implements killProcess() to forcefully terminate a process by its window name


##Unicode Support:

Uses LPCWSTR for wide-character string parameters, supporting Unicode
