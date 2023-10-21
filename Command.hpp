#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "JSimple.hpp"
#include <functional> 

struct Command {
    string Name;        // Name of the command
    string Description; // Description of what the command does
    string Usage;       // Usage instructions for the command
    int ParameterCount; // Amount of Parameters required for the command
    std::function<void(string Input)> Function; // Function to execute the command

    // Constructor to initialize the command
    Command(const std::string& _name, const std::string& _description, const std::string& _usage, int _parametercount, std::function<void(string Input)> _parameters)
        : Name(_name), Description(_description), Usage(_usage), ParameterCount(_parametercount), Function(_parameters) {}

    void Execute(string Parameters) {
        Function(Parameters);
    }

};

#endif // COMMAND_HPP