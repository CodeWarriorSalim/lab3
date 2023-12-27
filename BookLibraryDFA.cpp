#include "BookLibraryDFA.h"

// ���������� ������� ������ BookLibraryDFA

BookLibraryDFA::BookLibraryDFA() {}

void BookLibraryDFA::addState(const std::string& state) {
    states.insert(state); // ���������� ��������� � �������
}

void BookLibraryDFA::addSymbol(const std::string& symbol) {
    alphabet.insert(symbol); // ���������� ������� � �������
}

void BookLibraryDFA::setInitialState(const std::string& initialState) {
    this->initialState = initialState; // ��������� ���������� ���������
}

void BookLibraryDFA::setOutputState(const std::string& outputState) {
    this->outputState = outputState; // ��������� ��������� ���������
}

void BookLibraryDFA::addTransition(const std::string& fromState, const std::string& inputSymbol, const std::string& toState) {
    transitions[fromState][inputSymbol] = toState; // ���������� ��������
}

bool BookLibraryDFA::processLibraryActions(const std::vector<std::string>& actions) {
    std::string currentState = initialState;
    bool issuePresent = false;
    bool fineApplied = false;

    std::cout << "��������� ���������: " << currentState << std::endl;

    for (const std::string& symbol : actions) {
        std::cout << "������� ��������: " << symbol << std::endl;

        // �������� ������� �������� ��� ������� �� �������� ���������
        if (transitions[currentState].find(symbol) == transitions[currentState].end()) {
            std::cout << "������! ������������ ��������: " << symbol << std::endl;
            std::cout << "�������� �� ���������." << std::endl;
            return false;
        }

        currentState = transitions[currentState][symbol];

        std::cout << "������� ���������: " << currentState << std::endl;

        // �������� ��������� ���������� ��������
        if (currentState == outputState && issuePresent) {
            std::cout << "�������� ������� ���������." << std::endl;

            // �������� ��������� � ���������� ������
            if (currentState == "����������" && fineApplied) {
                std::cout << "����� �� ��������� ��������." << std::endl;
            }

            return true;
        }

        // ��������� ����� ������� ������
        if (symbol == "������") {
            issuePresent = true;
        }

        // �������� �� ��������� � ���������� ������
        if (currentState == "����������" && !fineApplied) {
            std::cout << "����� ����������!" << std::endl;
            fineApplied = true;
        }
    }

    std::cout << "�������� �� ���������." << std::endl;
    return false;
}
