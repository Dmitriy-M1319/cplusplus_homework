#include <iostream>
#include <string>
#include "my_deque.h"

int main(void)
{
    std::cout << "Программа для предоставления примера работы с деком (строки)" << std::endl;

    my_deque::MyDeque<std::string> deque{};
    std::cout << "Создан пустой дек со строками" << std::endl << std::endl;


    std::cout << "Добавим несколько значений в конец: Java, Go, PHP, Python:" << std::endl;
    deque.push_back(std::string{"Java"});
    deque.push_back(std::string{"Go"});
    deque.push_back(std::string{"PHP"});
    deque.push_back(std::string{"Python"});

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "Добавим несколько значений в начало: C, C++ :" << std::endl;
    deque.push_front(std::string{"C"});
    deque.push_front(std::string{"C++"});

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "Удалим 2 значения с конца" << std::endl;
    deque.pop_back();
    deque.pop_back();

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "Удалим значение с начала" << std::endl;
    deque.pop_front();

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "Вставим значение Kotlin на 1 позицию" << std::endl;
    deque.insert(std::string{"Kotlin"}, 1);

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "И удалим его же" << std::endl;
    deque.erase(1);

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "Первое значение в деке: " << deque.front() << std::endl;
    std::cout << "Последнее значение в деке: " << deque.back() << std::endl;
    std::cout << "Количество элементов в деке: " << deque.size()  << " (не изменилось)" << std::endl;
    std::cout << std::endl;

    std::cout << "Очистим дек" << std::endl;
    deque.clear();

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    return 0;

}
