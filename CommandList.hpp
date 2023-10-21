#ifndef COMMANDSLIST_HPP
#define COMMANDSLIST_HPP
#pragma once

#include "Command.hpp"

class CommandsList {
public:
    CommandsList();

    void AddCommand(const Command& command); // Manually add a command
    bool RemoveCommandByName(const string& Name); // Remove a command from the CommandList by its name
    bool RemoveCommandByNumber(const int& Value); // Remove a command from the CommandList by its number
    void DisplayCommands() const; // Function to display all commands and their info
    Command* GetCommandByName(const std::string& name); // Function to retrieve a command by name
    Command* GetCommandByNumber(const int& Value); // Function to retrieve a command by value
    int GetCommandNumberByName(const string& Name); // Get a command by its number
    int GetCommandCount(); // Get the amount of commands in CommandList

    // Number values are relative to the order they are in CommandList, the first Command added will be 0

private:
    std::vector<Command> CommandList;
};

#endif // COMMANDSLIST_HPP