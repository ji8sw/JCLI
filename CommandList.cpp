#include "CommandList.hpp"
#include "JSimple.hpp"
#include <fstream>
#include <cstdlib>

CommandsList::CommandsList() {
    Command DisplayCommandsCommand("Help", "Sends a list of commands and their info", "", 0, [this] (string Input)
        {
            this->DisplayCommands();
        });
    AddCommand(DisplayCommandsCommand);
    
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
}

void CommandsList::AddCommand(const Command& command) {
    CommandList.push_back(command);
}

void CommandsList::DisplayCommands() const {
    for (const Command& cmd : CommandList) {
        Print("Command Name: "+ cmd.Name + "\n");
        if (cmd.Description != "")
        {
            Print("Description: " + cmd.Description + "\n");
        }
        if (cmd.Usage != "")
        {
            Print("Usage: " + cmd.Usage + "\n");
        }
        Print("\n");
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


