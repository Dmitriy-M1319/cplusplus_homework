#ifndef MY_DEQUE_H
#define MY_DEQUE_H

#include <cstdint>
#include <exception>
#include <utility>
#include <stdexcept>
#include <iostream>

namespace my_deque
{
    /// Класс элемента дека (ячейка хранения)
    template<typename T>
    class MyDequeItem
    {
    public:
        MyDequeItem():data(T()), prev(nullptr), next(nullptr){}
        MyDequeItem(T data):data(data), prev(nullptr), next(nullptr){}

        T& get_data();

        const T &get_data() const;

        void set_data(const T& value);
        void set_data(T&& value);

        MyDequeItem<T> *get_prev();
        MyDequeItem<T> *get_next();

        void set_prev(MyDequeItem<T>* prev);
        void set_next(MyDequeItem<T>* next);
    private:
        /* Приватные поля: m_название */
        T data;
        MyDequeItem *prev;
        MyDequeItem *next;
    };

    

    template<typename T>
    T& MyDequeItem<T>::get_data()
    {
        return data;
    }

    template<typename T>
    const T &MyDequeItem<T>::get_data() const
    {
        return data;
    }

    template<typename T>
    void MyDequeItem<T>::set_data(const T& value)
    {
        data = value;
    }

    template<typename T>
    void MyDequeItem<T>::set_data(T&& value)
    {
        data = std::move(value);
    }

    template<typename T>
    MyDequeItem<T> *MyDequeItem<T>::get_prev() 
    { 
        return prev; 
    }

    template<typename T>
    MyDequeItem<T> *MyDequeItem<T>::get_next() 
    { 
        return next; 
    }

    template<typename T>
    void MyDequeItem<T>::set_prev(MyDequeItem<T>* prev)
    {
        this->prev = prev;
    }

    template<typename T>
    void MyDequeItem<T>::set_next(MyDequeItem<T>* next)
    {
        this->next = next; 
    }




    /// Класс дека (двунаправленной очереди)
    template<typename T>
    class MyDeque
    {
    public:
        using node_elem = MyDequeItem<T>*;
        MyDeque(): deque_size(0)
        {
            head = tail = nullptr;
        }

        ~MyDeque();


        /// Получить количество элементов в деке
        std::size_t size();

        /// Проверка на пустой дек
        bool empty();

        /// Получить значение по индексу
        T &at(const int index); 

        /// Вставить значение в конец
        void push_back(const T &value);

        /// Вставить значение в начало
        void push_front(const T &value); 

        /// Получить значение в конце
        T &back(); 

        /// Получить значение в начале
        T &front(); 

        /// Вставить значение в определенную позицию в деке
        void insert(const T &value, const int position);
        
        /// Удалить элемент с конца
        void pop_back();
        
        /// Удалить элемент с начала
        void pop_front();
        
        /// Удалить элемент в деке на определенной позиции
        void erase(const int position);
        
        /// Очистить весь дек
        void clear();
        
        /// Вывести дек в консоль
        void print_deque();    
    private:
        MyDequeItem<T>* head;
        MyDequeItem<T>* tail;
        std::size_t deque_size;
    };

    template<typename T>
    MyDeque<T>::~MyDeque()
    {
        if(head != nullptr)
        {
            while(head != tail)
            {
                node_elem tmp = head;
                head = head->get_next();
                delete tmp;
            }
            delete head;
        }
    }



    template<typename T>
    std::size_t MyDeque<T>::size()
    {
        return deque_size;
    }

    template<typename T>
    bool MyDeque<T>::empty()
    {
        return deque_size == 0;
    }

    template<typename T>
    T &MyDeque<T>::at(const int index)
    {
        if(index < 0 || index >= deque_size || empty())
            throw std::out_of_range{"bad index value"};
    
        node_elem curr = head;
        for (int i = 0; i < index; i++) 
            curr = curr->get_next();
    
        return curr->get_data();
    }

    template<typename T>
    void MyDeque<T>::push_back(const T &value)
    {
        if(deque_size == 0)
        {
            tail = new MyDequeItem<T>(value);
            head = tail;
            }
        else
        {
            node_elem tmp = new MyDequeItem<T>(value);
            tmp->set_prev(tail);
            tail->set_next(tmp);
            tail = tail->get_next();
        }
        deque_size++;
    }

    template<typename T>
    void MyDeque<T>::push_front(const T &value)
    {
        if(deque_size == 0)
        {
            head = new MyDequeItem<T>(value);
            tail = head;
        }
        else
        {
            node_elem tmp = new MyDequeItem<T>(value);
            tmp->set_next(head);
            head->set_prev(tmp);
            head = head->get_prev();
        }
        deque_size++;
    }

    template<typename T>
    T &MyDeque<T>::back()
    {
        if(empty())
            throw "the deque is empty";
        return tail->get_data();
    }

    template<typename T>
    T &MyDeque<T>::front()
    {
        if(empty())
            throw "the deque is empty";
        return head->get_data();
    }

    template<typename T>
    void MyDeque<T>::insert(const T &value, const int position)
    {
        if (position < 0 || position >= (int)deque_size || empty()) 
            throw std::out_of_range{"bad index value"};
        else if(position == 0)
        {
            push_front(value);
            return;
        }
        else if(position == (int)deque_size - 1)
        {
            push_back(value);
            return;
        }
        else
        {
            node_elem curr = head;
            for (int i = 0; i < position; i++) 
                curr = curr->get_next();
        
            node_elem tmp = new MyDequeItem<T>(value);
            tmp->set_prev(curr->get_prev());
            curr->get_prev()->set_next(tmp);
            curr->set_prev(tmp);
            tmp->set_next(curr);
            deque_size++;
        }
    }

    template<typename T>
    void MyDeque<T>::pop_back()
    {
        if(empty()) return;
        node_elem tmp = tail;
        tail = tail->get_prev();
        if(tail != nullptr)
            tail->set_next(nullptr);
        delete tmp;
        deque_size--;
    }

    template<typename T>
    void MyDeque<T>::pop_front()
    {
        if(empty()) return;
        node_elem tmp = head;
        head = head->get_next();
        if(head != nullptr)
            head->set_prev(nullptr);
        delete tmp;
        deque_size--;
    }

    template<typename T>
    void MyDeque<T>::erase(const int position)
    {
        if(position < 0 || position >= (int)deque_size)
            throw std::out_of_range{"bad index value"};
        else if (position == 0) 
        {
            pop_front();
            return;
        }
        else if (position == (int)deque_size - 1) 
        {
            pop_back();
            return;
        }
        else
        {
            node_elem curr = head;
            for (int i = 0; i < position; i++) 
                curr = curr->get_next();
        
            curr->get_prev()->set_next(curr->get_next());
            curr->get_next()->set_prev(curr->get_prev());
            delete curr;
            deque_size--;
        }
    }

    template<typename T>
    void MyDeque<T>::clear()
    {
        while(head != tail)
        {
            node_elem tmp = head;
            head = head->get_next();
            delete tmp;
        }
        delete head;
        head = nullptr;
        deque_size = 0;
    }

    template<typename T>
    void MyDeque<T>::print_deque()
    {
        std::cout << "Deque: ";
        if (empty()) 
        {
            std::cout << "Пустой " << std::endl;
            return;
        }
        node_elem curr = head;
        while (curr != nullptr) 
        {
            std::cout << curr->get_data() << " ";
            curr = curr->get_next();
        }
        std::cout << std::endl;
    }
};

#endif

