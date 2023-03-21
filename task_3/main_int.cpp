#include <iostream>
#include "my_deque.h"


int main(int argc, const char *argv[])
{
    std::cout << "Программа для предоставления примера работы с деком (целые числа)" << std::endl;

    my_deque::MyDeque<int> deque{};
    std::cout << "Создан пустой дек с целыми числами" << std::endl << std::endl;


    std::cout << "Добавим несколько значений в конец: 1, 2, 4, 5:" << std::endl;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(4);
    deque.push_back(5);

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "Добавим несколько значений в начало: 17, -2, 43:" << std::endl;
    deque.push_front(17);
    deque.push_front(-2);
    deque.push_front(43);

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

    std::cout << "Вставим значение 19 на 2 позицию" << std::endl;
    deque.insert(19, 2);

    std::cout << "Количество элементов в деке: " << deque.size() << std::endl;
    std::cout << "Текущее состояние дека" << std::endl;
    deque.print_deque();
    std::cout << std::endl;

    std::cout << "И удалим его же" << std::endl;
    deque.erase(2);

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
