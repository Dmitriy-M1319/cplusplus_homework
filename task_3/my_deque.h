#ifndef MY_DEQUE_H
#define MY_DEQUE_H

#include <cstdint>
/// Класс дека (двунаправленной очереди)

namespace my_deque
{
    /// Класс элемента дека (ячейка хранения)
    template<typename T>
    class MyDequeItem
    {
    private:
        T data;
        MyDequeItem *next;
        MyDequeItem *prev;
    public:
        MyDequeItem();
        MyDequeItem(T data);
        ~MyDequeItem();

        T& get_data();
        const T& get_data() const;

        void set_data(T& value);
        void set_data(T&& value);

        MyDequeItem<T> *get_prev();

        MyDequeItem<T> *get_next();

        void set_prev(const MyDequeItem<T>* prev);

        void set_next(const MyDequeItem<T>* next);
    };

    template<typename T>
    class MyDeque
    {
    private:
        MyDequeItem<T>* head;
        MyDequeItem<T>* tail;
        std::size_t deque_size;

    public:
        using node_elem = MyDequeItem<T>*;
        MyDeque();

        /// Получить количество элементов в деке
        std::size_t size() noexcept;

        /// Проверка на пустой дек
        bool empty();

        /// Получить значение по индексу
        T& at(int index);
        const T& at(int index) const;

        /// Вставить значение в конец
        void push_back(const T& value);
        void push_back(T&& value);

        /// Вставить значение в начало
        void push_front(const T& value);
        void push_front(T&& value);

        /// Получить значение в конце
        T& back();
        const T& back() const;

        /// Получить значение в начале
        T& front();
        const T& front() const;

        /// Вставить значение в определенную позицию в деке
        void insert(const T& value, int position);
        void insert(T&& value, int position);

        /// Удалить элемент с конца
        void pop_back();

        /// Удалить элемент с начала
        void pop_front();

        /// Очистить весь дек
        void clear();

    };
};

#endif

