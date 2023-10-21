
## JCLI (Ji9sw's Command Line Interface)

**JCLI** is an open-source, command-line interface (CLI) tool written in C++. It allows you to interact with a set of predefined commands, each with its own functionality. You can use these commands to perform various tasks within the console environment.

### List of Commands

-   **Help**: Sends a list of commands and their info.
-   **Stop**: Stops the console.
-   **Say**: Repeats your message to the console.
-   **Clear**: Clears the console.
-   **Execute**: Executes a command just like in command prompt. 
-   **CommandCount**: Says how many commands are present. 
-   **Calculate**: Add, Multiply, Subtract, and Divide. 
-   **Time**: Says the current system date and time. 
-   **MessageBox**: Shows a message box with your title and text. ***New!***
-   **CheckPrime**: Tells you if a number is a prime number. ***New!***

### Command Type Documentation

The `Command` type is used to represent individual commands within the CLI. It includes the following attributes:

-   `Name`: Name of the command.
-   `Description`: Description of what the command does.
-   `Usage`: Usage instructions for the command.
-   `ParameterCount`: The number of parameters required for the command.
-   `Function`: A function to execute the command.

#### Constructor

The `Command` type has a constructor to initialize the command:

`Command(const std::string& _name, const std::string& _description, const std::string& _usage, int _parametercount, std::function<void(string Input)> _parameters)` 

### Usage Example

Here is an example of how to use JCLI:

    #include <iostream>
    #include "JSimple.hpp"
    #include "Command.hpp"
    #include "CommandList.hpp"
    
    int main(int argc, char* argv[]) {
        CommandsList CommandManager; // A type to access useful functions 
        string Command = "Execute"; //Command
        string Parameters = "notepad"; // Parameters (they are seperated by space)
        Command MyCommand = CommandManager.GetCommandByName(Command); // Retrieves the command by the Name parameter of the Command Type from the list of commands in CommandList
        MyCommand->Execute(Parameters); //Runs the Execute() function attached to the Command type and passes the parameters
    }

In this example, `CommandManager` is used to manage and execute a set of predefined commands. Note the `int argc, char* argv[]`, these enable the compatibility of shortcut parameters.

## Open Source
Please note that this is all opensource, so if you understand C++ or are learning, you can modify anything in this project using Visual Studio, such as adding your own commands.

## JSimple
This project was made with [JSimple](https://github.com/ji8sw/JSimple)
