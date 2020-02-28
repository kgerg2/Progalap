#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

void throwInt() {
    throw 0;
}

enum Error {
    SOME_ERROR
};

void throwEnum() {
    throw SOME_ERROR;
}

void throwException() {
    throw std::runtime_error("error");
}

std::string getInput() {
    std::cout << "Input: ";
    std::string inp;
    std::cin >> inp;
    
    if (inp == "katalogus") {
        throw std::runtime_error("nincs katalogus");
    }
    
    return inp;
}

void tryCatch() {
    try {
        throw 0;
    } catch (int e) {}
    
    try {
        throwInt();
    } catch (int e) {
        std::cerr << "caught int: " << e << std::endl;
    }
    
    try {
        throwEnum();
        throwInt();
    } catch (int e) {
        std::cerr << "caught int: " << e << std::endl;
    } catch (Error e) {
        std::cerr << "caught Error: " << e << std::endl;
    }
    
    try {
        throwException();
    } catch (const std::runtime_error &e) {
        std::cerr << "caught std::runtime_error: " << e.what() << std::endl;
    }
    
    try {
        std::string inp = getInput();
        std::cout << "Your input was: " << inp << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "error: " << e.what() << std::endl;
    }
    
    try {
        std::string inp = getInput();
        if (inp == "int") {
            throwInt();
        } else if (inp == "enum") {
            throwEnum();
        } else if (inp == "exception") {
            throwException();
        }
    } catch (...) {
        std::cerr << "Something went wrong." << std::endl;
    }
}

int main() {
    tryCatch();
    return 0;
}
