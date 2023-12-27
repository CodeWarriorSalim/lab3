#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>

class BookLibraryDFA {
private:
    // Структуры данных для хранения переходов, состояний и алфавита
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> transitions;
    std::unordered_set<std::string> states;
    std::unordered_set<std::string> alphabet;
    std::string initialState;
    std::string outputState;

public:
    // Конструктор класса
    BookLibraryDFA();

    // Методы для добавления состояний и символов в алфавит
    void addState(const std::string& state);
    void addSymbol(const std::string& symbol);

    // Методы для установки начального и конечного состояний
    void setInitialState(const std::string& initialState);
    void setOutputState(const std::string& outputState);

    // Метод для добавления переходов между состояниями
    void addTransition(const std::string& fromState, const std::string& inputSymbol, const std::string& toState);

    // Метод для обработки последовательности действий в библиотеке
    bool processLibraryActions(const std::vector<std::string>& actions);
};
