#include "CommandList.hpp"
#include "JSimple.hpp"
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#pragma comment(lib, "user32.lib")
#include <Windows.h>
#pragma warning(disable : 4996)

CommandsList::CommandsList() {
    Command DisplayCommandsCommand("Help", "Sends a list of commands and their info", "", 0, [this] (string Input)
        {
            this->DisplayCommands();
        });
    AddCommand(DisplayCommandsCommand);
    
    Command StopCommand("Stop", "Stops the console", "", 0, [this](string Input)
        {
            exit(0);
        });
    AddCommand(StopCommand);

    Command SayCommand("Say", "Repeats your message to the console", "Say Hello World!", 1, [this](string Input)
        {
            Print(Input);
        });
    AddCommand(SayCommand);

    Command ClearCommand("Clear", "Clears the console", "", 0, [this](string Input)
        {
            system("cls");
            Print("Ji9sw's Command Line Interface\n");
        });
    AddCommand(ClearCommand);

    Command ExecuteCommand("Execute", "Executes a command just like in command prompt", "Execute notepad", 1, [this](string Input)
        {
            system(Input.c_str());
            Print("\n");
        });
    AddCommand(ExecuteCommand);

    Command CommandCountCommand("CommandCount", "Says how many commands are present", "", 0, [this](string Input)
        {
            Print(to_string(CommandList.size()));
        });
    AddCommand(CommandCountCommand);

    Command CalculateCommand("Calculate", "Add, Multiply, Subtract, and Divide", "Calculate 1 x 1", 3, [this](string Input) {
        vector<string> Parameters = StringToListWords(Input);

        int Num1, Num2;
        if (!(istringstream(Parameters[0]) >> Num1) || !(istringstream(Parameters[2]) >> Num2)) {
            Print("Error: Invalid numeric values for calculation.");
            return;
        }

        if (Parameters[1] == "x" || Parameters[1] == "X" || Parameters[1] == "*" || ToLowerCase(Parameters[1]) == "times") {
            int result = Num1 * Num2;
            Print(to_string(result));
        }
        else if (Parameters[1] == "+" || ToLowerCase(Parameters[1]) == "plus") {
            int result = Num1 + Num2;
            Print(to_string(result));
        }
        else if (Parameters[1] == "-" || ToLowerCase(Parameters[1]) == "minus") {
            int result = Num1 - Num2;
            Print(to_string(result));
        }
        else if (Parameters[1] == "/") {
            if (Num2 == 0) {
                Print("Error: Division by zero is not allowed.");
                return;
            }
            float result = static_cast<float>(Num1) / static_cast<float>(Num2);
            Print(to_string(result));
        }
        else {
            Print("Error: Invalid operator. Supported operators are +, -, *, /");
        }
        });
    AddCommand(CalculateCommand);

    Command TimeCommand("Time", "Says the current system date and time", "", 0, [this](string Input)
        {
            time_t CurrentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());

            string TimeString = ctime(&CurrentTime);

            Print("Current time: " + TimeString);
        });
    AddCommand(TimeCommand);

    Command MessageBoxCommand("MessageBox", "Shows a message box with your title and text", "MessageBox MyTitle MyDescription", 2, [this](string Input)
        {
            vector<string> Parameters = StringToListWords(Input);

            std::wstring Title = std::wstring(Parameters[0].begin(), Parameters[0].end());
            LPCWSTR WideTitle = Title.c_str();

            std::wstring Description = std::wstring(Parameters[1].begin(), Parameters[1].end());
            LPCWSTR WideDescription = Description.c_str();

            MessageBox(NULL, WideDescription, WideTitle, MB_OK | MB_ICONINFORMATION);
        });
    AddCommand(MessageBoxCommand);

    Command CheckPrimeCommand("CheckPrime", "Tells you if a number is a prime number", "CheckPrime 2", 1, [this](string Input)
        {
            vector<string> Parameters = StringToListWords(Input);

            try {
                if (!Parameters.empty()) {
                    int number = std::stoi(Parameters[0]);
                    // The conversion was successful; you can use 'number' here.
                }
                else {
                    Print("Error: Missing parameter");
                    return;
                }
            }
            catch (const std::invalid_argument& e) {
                Print("Error: Invalid number");
                return;
            }

            
            if (IsPrime(stoi(Parameters[0])))
            {
                Print("Number is a prime number");
            }
            else 
            {
                Print("Number is not a prime number");
            }
        });
    AddCommand(CheckPrimeCommand);

}

void CommandsList::AddCommand(const Command& command) {
    CommandList.push_back(command);
}

bool CommandsList::RemoveCommandByName(const string& Name) {
    auto it = std::find_if(CommandList.begin(), CommandList.end(), [Name](const Command& cmd) 
    {
        return cmd.Name == Name;
    });

    if (it != CommandList.end()) {
        CommandList.erase(it);
    }

    return true;
}

bool CommandsList::RemoveCommandByNumber(const int& Value) {
    return RemoveCommandByName(GetCommandByNumber(Value)->Name);
}

void CommandsList::DisplayCommands() const {
    int position = 0; // Initialize the position counter

    for (const Command& cmd : CommandList) {
        Print("Command Name: " + cmd.Name + " (" + to_string(position) + ")\n");

        if (cmd.Description != "") {
            Print("Description: " + cmd.Description + "\n");
        }
        if (cmd.Usage != "") {
            Print("Usage: " + cmd.Usage + "\n");
        }
        Print("\n");

        position++; // Increment the position counter
    }
}


Command* CommandsList::GetCommandByName(const string& Name) {
    for (Command& cmd : CommandList) {
        if (cmd.Name == Name) {
            return &cmd;
        }
    }
    return nullptr; // Command not found
}

Command* CommandsList::GetCommandByNumber(const int& Value) {
    if (CommandList[Value].Name != "")
    {
        return &CommandList[Value];
    }
    return nullptr; // Command not found
}

int CommandsList::GetCommandNumberByName(const string& Name) {
    auto it = std::find_if(CommandList.begin(), CommandList.end(), [Name](const Command& cmd) 
    {
        return cmd.Name == Name;
    });

    if (it != CommandList.end()) 
    {
        return std::distance(CommandList.begin(), it);
    }

    return -1; // Command not found
}

int CommandsList::GetCommandCount() {
    return CommandList.size();
}


