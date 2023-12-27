#include <iostream>
#include "BookLibraryDFA.h"

int main() {
    setlocale(LC_ALL, "Russian");

    BookLibraryDFA libraryAutomaton; // Создание экземпляра конечного автомата

    // Добавление состояний в конечный автомат
    libraryAutomaton.addState("доступно");
    libraryAutomaton.addState("выдано");
    libraryAutomaton.addState("просрочено");
    libraryAutomaton.addState("возвращено");

    // Добавление действий в алфавит конечного автомата
    libraryAutomaton.addSymbol("выдача");
    libraryAutomaton.addSymbol("возврат");
    libraryAutomaton.addSymbol("уведомление_о_просрочке");

    // Установка начального и конечного состояний
    libraryAutomaton.setInitialState("доступно");
    libraryAutomaton.setOutputState("возвращено");

    // Добавление переходов между состояниями для различных действий
    libraryAutomaton.addTransition("доступно", "выдача", "выдано");
    libraryAutomaton.addTransition("выдано", "возврат", "возвращено");
    libraryAutomaton.addTransition("выдано", "уведомление_о_просрочке", "просрочено");
    libraryAutomaton.addTransition("просрочено", "возврат", "возвращено");

    // Последовательность действий в библиотеке
    std::vector<std::string> actions = {"выдача", "возврат"};

    // Обработка последовательности действий
    bool isSuccessful = libraryAutomaton.processLibraryActions(actions);

    // Вывод результата выполнения действий в библиотеке
    if (isSuccessful) {
        std::cout << "Операция в библиотеке завершена успешно." << std::endl;
    } else {
        std::cout << "Операция в библиотеке завершилась неудачно." << std::endl;
    }

    return 0;
}
