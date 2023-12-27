#include <iostream>
#include "BookLibraryDFA.h"

int main() {
    setlocale(LC_ALL, "Russian");

    BookLibraryDFA libraryAutomaton; // �������� ���������� ��������� ��������

    // ���������� ��������� � �������� �������
    libraryAutomaton.addState("��������");
    libraryAutomaton.addState("������");
    libraryAutomaton.addState("����������");
    libraryAutomaton.addState("����������");

    // ���������� �������� � ������� ��������� ��������
    libraryAutomaton.addSymbol("������");
    libraryAutomaton.addSymbol("�������");
    libraryAutomaton.addSymbol("�����������_�_���������");

    // ��������� ���������� � ��������� ���������
    libraryAutomaton.setInitialState("��������");
    libraryAutomaton.setOutputState("����������");

    // ���������� ��������� ����� ����������� ��� ��������� ��������
    libraryAutomaton.addTransition("��������", "������", "������");
    libraryAutomaton.addTransition("������", "�������", "����������");
    libraryAutomaton.addTransition("������", "�����������_�_���������", "����������");
    libraryAutomaton.addTransition("����������", "�������", "����������");

    // ������������������ �������� � ����������
    std::vector<std::string> actions = {"������", "�������"};

    // ��������� ������������������ ��������
    bool isSuccessful = libraryAutomaton.processLibraryActions(actions);

    // ����� ���������� ���������� �������� � ����������
    if (isSuccessful) {
        std::cout << "�������� � ���������� ��������� �������." << std::endl;
    } else {
        std::cout << "�������� � ���������� ����������� ��������." << std::endl;
    }

    return 0;
}
