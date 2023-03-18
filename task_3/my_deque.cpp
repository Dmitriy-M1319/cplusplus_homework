#include "my_deque.h"
#include <utility>
#include <stdexcept>

using namespace my_deque;

// Реализация внутреннего класса элемента дека

template<typename T>
MyDequeItem<T>::MyDequeItem(T data): data(data), prev(nullptr), next(nullptr){}

template<typename T>
MyDequeItem<T>::MyDequeItem(): MyDequeItem<T>(T()) {}

template<typename T>
T& MyDequeItem<T>::get_data()
{
    return data;
}

template<typename T>
const T& MyDequeItem<T>::get_data() const
{
    return data;
}

template<typename T>
void MyDequeItem<T>::set_data(T& value)
{
    data = value;
}

template<typename T>
void MyDequeItem<T>::set_data(T&& value)
{
    data = std::move(value);
}

template<typename T>
MyDequeItem<T>* MyDequeItem<T>::get_next()
{
    return next;
}

template<typename T>
MyDequeItem<T>* MyDequeItem<T>::get_prev()
{
    return prev;
}

template<typename T>
void MyDequeItem<T>::set_next(const MyDequeItem<T> *next)
{
    this->next = next;
}

template<typename T>
void MyDequeItem<T>::set_prev(const MyDequeItem<T> *prev)
{
    this->prev = prev;
}


// Реализация самого дека

template<typename T>
MyDeque<T>::MyDeque(): deque_size(0)
{
    head = tail = nullptr;
}

template<typename T>
std::size_t MyDeque<T>::size() noexcept
{
    return deque_size;
}

template<typename T>
bool MyDeque<T>::empty()
{
    return deque_size == 0;
}


template<typename T>
T& MyDeque<T>::at(int index)
{
    if(index < 0 || index >= deque_size)
    {
        throw std::out_of_range{"bad index value"};
    }

    node_elem *curr = head;
    for (int i = 0; i < index; i++) 
    {
        curr = curr->get_next();
    }

    return curr->get_data();
}

template<typename T>
const T& MyDeque<T>::at(int index) const
{
    return at(index);
}

template<typename T>
void MyDeque<T>::push_back(const T& value)
{
    if(deque_size == 0)
    {
        tail = new MyDequeItem<T>(value);
    }
    else
    {
        node_elem tmp = tail->get_next();
        tmp = new MyDequeItem<T>(value);
        tmp->set_prev(tail);
        tail = tail->get_next();
    }
    deque_size++;
}

template<typename T>
void MyDeque<T>::push_back(T&& value)
{
    push_back(std::move(value));
}

template<typename T>
void MyDeque<T>::push_front(const T& value)
{
    if(deque_size == 0)
    {
        head = new MyDequeItem<T>(value);
    }
    else
    {
        node_elem tmp = head->get_prev();
        tmp = new MyDequeItem<T>(value);
        tmp->set_next(head);
        head = head->get_prev();
    }
    deque_size++;
}

template<typename T>
void MyDeque<T>::push_front(T&& value)
{
    push_front(std::move(value));
}

template<typename T>
T& MyDeque<T>::back()
{
    return tail->get_data();
}

template<typename T>
const T& MyDeque<T>::back() const
{
    return tail->get_data();
}

template<typename T>
T& MyDeque<T>::front()
{
    return head->get_data();
}

template<typename T>
const T& MyDeque<T>::front() const
{
    return head->get_data();
}

template<typename T>
void MyDeque<T>::insert(const T& value, int index) // надо много проверок
{
    if(index == 0 && empty()) // такая ситуация вполне вероятна
    {
        push_back(value);
        return;
    }

    if (index < 0 || index >= deque_size) 
    {
        throw std::out_of_range{"bad index value"};
    }

    node_elem curr = head;
    for (int i = 0; i < index; i++) 
    {
        curr = curr->get_next();
    }

    node_elem tmp = new MyDequeItem<T>(value);
    tmp->set_next(curr->get_next());
    curr->get_prev()->set_prev(tmp);
    curr->set_next(tmp);
    deque_size++;
}

template<typename T>
void MyDeque<T>::insert(T&& value, int index) // надо много проверок
{
    insert(std::move(value), index);
}

template<typename T>
void MyDeque<T>::pop_back()
{
    tail = tail->get_prev();
    delete tail->get_next();
    tail->set_next(nullptr);
    deque_size--;
}

template<typename T>
void MyDeque<T>::pop_front()
{
    head = head->get_next();
    delete head->get_prev();
    head->set_prev(nullptr);
    deque_size--;
}

template<typename T>
void MyDeque<T>::clear()
{
    while(head != tail)
    {
        head = head->get_next();
        delete head->get_prev();
    }
    delete head;
    deque_size = 0;
}

