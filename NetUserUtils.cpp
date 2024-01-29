#include <string>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

void changePWD(std::string username, std::string password);
void createUser(std::string username, std::string password);
void execute(std::vector<std::string> args);

// New Methods since 1.0.1-Snapshot
void opUser(std::string username);
void deleteUser(std::string username);
void deactivateUser(std::string username);

int main() {

    std::string executeMode = "normal";

    system("title Archiv Multi-Featured NetUserUtils v1.0.1-Snapshot (DEV_CHANNEL)[8cn12d]");
    system("color 1F");

    std::cout << "Loaded program v1.0.1-Snapshot (DEV_CHANNEL)[8cn12d].\n" << std::endl;
    std::cout << "Change Log: Added OP&Delete feature.\n" << std::endl;
    std::string username;
    std::cout << "Type in your username: ";
    std::getline(std::cin, username);

    while (true) {
        std::string CMD;
        std::cout << username << " > ";
        std::getline(std::cin, CMD);

        std::istringstream iss(CMD);
        std::vector<std::string> args;

        std::string word;
        while (iss >> word) {
            args.push_back(word);
        }

        if (CMD == "break") {
            std::cout << "Thanks for using!" << std::endl;
            return 1;
        } else if (CMD == "cmd") {
            std::cout << "\nSet the execution mode to COMMAND LINE.\n" << std::endl;
            executeMode = "cmd";
        } else if (CMD == "back") {
            std::cout << "\nSet the execution mode to APPLICATION.\n" << std::endl;
            executeMode = "normal";
        } else {
            if (executeMode == "normal") {
                execute(args);
            } else {
                system(CMD.c_str());
            }
        }
    }

    return 0;
}

void changePWD(std::string username, std::string password) {
    std::string command = "net user " + username + " " + password;
    system(command.c_str());
}

void createUser(std::string username, std::string password) {
    std::string command = "net user " + username + " " + password + " /add";
    system(command.c_str());
    std::string command2 = "net user " + username + " " + password + " /active:yes";
    system(command2.c_str());
}

void execute(std::vector<std::string> args) {
    if (args[0] == "changePWD") {
        std::string targetName = args[1];
        std::string pwd = args[2];
        changePWD(targetName, pwd);
    } else if (args[0] == "createUser") {
        std::string targetName = args[1];
        std::string pwd = args[2];
        createUser(targetName, pwd);
    } else if (args[0] == "op") {
        std::string targetName = args[1];
        opUser(targetName);
    } else if (args[0] == "deleteUser") {
        std::string targetName = args[1];
        deleteUser(targetName);
    } else if (args[0] == "deactivateUser") {
        std::string targetName = args[1];
        deactivateUser(targetName);
    } else {
        std::cout << "Not a command developed!\n" << std::endl;
        std::cout << "  - createUser [Username] [Password]\n" << std::endl;
        std::cout << "  - deleteUser [Username]\n" << std::endl;
        std::cout << "  - deactivateUser [Username]\n" << std::endl;
        std::cout << "  - op [Username]\n" << std::endl;
        std::cout << "  - changePWD [Username] [Password]\n\n" << std::endl;
        std::cout << "Archiv Multi-Featured NetUserUtils v1.0.1-Snapshot (DEV_CHANNEL)[8cn12d]\n" << std::endl;
    }
}

void opUser(std::string username) {
    std::string command = "net localgroup administrators " + username + " /add";
    system(command.c_str());
}

void deleteUser(std::string username) {
    std::string command = "net user " + username + " /delete";
    system(command.c_str());
}

void deactivateUser(std::string username) {
    std::string cmd = "net user " + username + " /active:no";
    system(cmd.c_str());
}