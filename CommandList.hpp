#ifndef COMMANDSLIST_HPP
#define COMMANDSLIST_HPP

#include "Command.hpp"

class CommandsList {
public:
    CommandsList();

    void AddCommand(const Command& command); // Manually add a command
    void DisplayCommands() const; // Function to display all commands and their info
    Command* GetCommandByName(const std::string& name); // Function to retrieve a command by name

private:
    std::vector<Command> CommandList;
};

#endif // COMMANDSLIST_HPP