#ifndef MY_DEQUE_H
#define MY_DEQUE_H

#include <cstddef>
#include <cstdint>
/// Класс дека (двунаправленной очереди)

template<typename T>
class MyDeque
{
private:
    /// Класс элемента дека (ячейка хранения)
    class MyDequeItem
    {
    private:
        T *data;
        std::size_t data_size;
        int last_index;
        MyDequeItem *next;
        MyDequeItem *prev;
    public:
        MyDequeItem();
        ~MyDequeItem();
        MyDequeItem(int size);
        T at(int index);
        void insert(T value);
        bool is_full();
    };

    MyDequeItem* head;
    MyDequeItem* tail;
    std::size_t size;
};

#endif

