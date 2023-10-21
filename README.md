
## JCLI (Ji9sw's Command Line Interface)

**JCLI** is an open-source, command-line interface (CLI) tool written in C++. It allows you to interact with a set of predefined commands, each with its own functionality. You can use these commands to perform various tasks within the console environment.

### List of Commands

-   **DisplayCommandsCommand**: Returns a string that contains available commands and their information.
-   **SayCommand**: Repeats all the parameters except for the command itself to the console.
-   **ClearCommand**: Clears the console.
-   **ExecuteCommand**: Executes a command, similar to using the command prompt.

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
