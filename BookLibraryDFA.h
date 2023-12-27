#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>

class BookLibraryDFA {
private:
    // ��������� ������ ��� �������� ���������, ��������� � ��������
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> transitions;
    std::unordered_set<std::string> states;
    std::unordered_set<std::string> alphabet;
    std::string initialState;
    std::string outputState;

public:
    // ����������� ������
    BookLibraryDFA();

    // ������ ��� ���������� ��������� � �������� � �������
    void addState(const std::string& state);
    void addSymbol(const std::string& symbol);

    // ������ ��� ��������� ���������� � ��������� ���������
    void setInitialState(const std::string& initialState);
    void setOutputState(const std::string& outputState);

    // ����� ��� ���������� ��������� ����� �����������
    void addTransition(const std::string& fromState, const std::string& inputSymbol, const std::string& toState);

    // ����� ��� ��������� ������������������ �������� � ����������
    bool processLibraryActions(const std::vector<std::string>& actions);
};
