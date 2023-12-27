#include "BookLibraryDFA.h"

// Реализация методов класса BookLibraryDFA

BookLibraryDFA::BookLibraryDFA() {}

void BookLibraryDFA::addState(const std::string& state) {
    states.insert(state); // Добавление состояния в автомат
}

void BookLibraryDFA::addSymbol(const std::string& symbol) {
    alphabet.insert(symbol); // Добавление символа в алфавит
}

void BookLibraryDFA::setInitialState(const std::string& initialState) {
    this->initialState = initialState; // Установка начального состояния
}

void BookLibraryDFA::setOutputState(const std::string& outputState) {
    this->outputState = outputState; // Установка конечного состояния
}

void BookLibraryDFA::addTransition(const std::string& fromState, const std::string& inputSymbol, const std::string& toState) {
    transitions[fromState][inputSymbol] = toState; // Добавление перехода
}

bool BookLibraryDFA::processLibraryActions(const std::vector<std::string>& actions) {
    std::string currentState = initialState;
    bool issuePresent = false;
    bool fineApplied = false;

    std::cout << "Начальное состояние: " << currentState << std::endl;

    for (const std::string& symbol : actions) {
        std::cout << "Текущее действие: " << symbol << std::endl;

        // Проверка наличия перехода для символа из текущего состояния
        if (transitions[currentState].find(symbol) == transitions[currentState].end()) {
            std::cout << "Ошибка! Недопустимое действие: " << symbol << std::endl;
            std::cout << "Операция не выполнена." << std::endl;
            return false;
        }

        currentState = transitions[currentState][symbol];

        std::cout << "Текущее состояние: " << currentState << std::endl;

        // Проверка успешного завершения операции
        if (currentState == outputState && issuePresent) {
            std::cout << "Операция успешно выполнена." << std::endl;

            // Проверка просрочки и применение штрафа
            if (currentState == "возвращено" && fineApplied) {
                std::cout << "Штраф за просрочку применен." << std::endl;
            }

            return true;
        }

        // Установка флага наличия выдачи
        if (symbol == "выдача") {
            issuePresent = true;
        }

        // Проверка на просрочку и применение штрафа
        if (currentState == "просрочено" && !fineApplied) {
            std::cout << "Книга просрочена!" << std::endl;
            fineApplied = true;
        }
    }

    std::cout << "Операция не завершена." << std::endl;
    return false;
}
