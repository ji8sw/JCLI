#include <iostream>
#include "JSimple.hpp"
#include "Command.hpp"
#include "CommandList.hpp"

void func(string Input)
{

}

int main(int argc, char* argv[])
{
    CommandsList CommandManager;

    Print("Ji9sw's Command Line Interface\n");
    Print("Type 'Help' for a list of commands\n");


    if (argv[1])
    {
        if (CommandManager.GetCommandByName(argv[1]))
        {
            string Parameters;
            for (int i = 2; i < argc; i++) {
                Parameters = Parameters + argv[i] + " ";
            }
            Print(Parameters);

            
            if (CommandManager.GetCommandByName(argv[1])->ParameterCount > 0 && Parameters == "")
            {
                Print("Error: This command requires " + std::to_string(CommandManager.GetCommandByName(argv[1])->ParameterCount) + " Parameters\n");
                goto TopOfLoop;
            }
            CommandManager.GetCommandByName(argv[1])->Execute(Parameters);
            Print("\n");
        }
        else {
            Print("Error: This command does not exist\n");
        }
    }
    
    while (true) 
    {        
    TopOfLoop:
        string CommandInput = CreateInput("");
        string Command;
        string Parameters;

        size_t spacePos = CommandInput.find(' ');

        if (spacePos != std::string::npos) {
            // Seperate the command and parameters
            Command = CommandInput.substr(0, spacePos);
            Parameters = CommandInput.substr(spacePos + 1);
        }
        else {
            // No space found, the entire input is the command
            Command = CommandInput;
        }

        if (CommandManager.GetCommandByName(Command)) 
        {
            if (CommandManager.GetCommandByName(Command)->ParameterCount > 0 && Parameters == "")
            {
                Print("Error: This command requires " + std::to_string(CommandManager.GetCommandByName(Command)->ParameterCount) + " Parameters\n");
                goto TopOfLoop;
            }
            CommandManager.GetCommandByName(Command)->Execute(Parameters);
            Print("\n");
        }
        else if (stoi(Command) >~ CommandManager.GetCommandCount() && CommandManager.GetCommandByNumber(stoi(Command)))
        {
            Command = CommandManager.GetCommandByNumber(stoi(Command))->Name;
            
            if (CommandManager.GetCommandByName(Command)->ParameterCount > 0 && Parameters == "")
            {
                Print("Error: This command requires " + std::to_string(CommandManager.GetCommandByName(Command)->ParameterCount) + " Parameters\n");
                goto TopOfLoop;
            }
            CommandManager.GetCommandByName(Command)->Execute(Parameters);
            Print("\n");
        }
        else 
        {
            Print("Error: This command does not exist\n");
        }
    }
}

