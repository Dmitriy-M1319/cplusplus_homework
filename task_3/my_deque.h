#ifndef MY_DEQUE_H
#define MY_DEQUE_H

#include <cstdint>
#include <utility>
#include <stdexcept>
#include <iostream>

namespace my_deque
{
    /// Класс элемента дека (ячейка хранения)
    template<typename T>
    class MyDequeItem
    {
    private:
        T data;
        MyDequeItem *prev;
        MyDequeItem *next;
    public:
        MyDequeItem():data(T()), prev(nullptr), next(nullptr){}
        MyDequeItem(T data):data(data), prev(nullptr), next(nullptr){}

        T& get_data()
        {
            return data;
        }

        const T& get_data() const
        {
            return data;
        }

        void set_data(T& value)
        {
            data = value;
        }
        void set_data(T&& value)
        {
            data = std::move(value);
        }

        MyDequeItem<T> *get_prev() 
        { 
            return prev; 
        }

        MyDequeItem<T> *get_next() 
        { 
            return next; 
        }

        void set_prev(MyDequeItem<T>* prev)
        {
            this->prev = prev;
        }
        void set_next(MyDequeItem<T>* next)
        {
            this->next = next;
        }
    };

    /// Класс дека (двунаправленной очереди)
    template<typename T>
    class MyDeque
    {
    private:
        MyDequeItem<T>* head;
        MyDequeItem<T>* tail;
        std::size_t deque_size;

    public:
        using node_elem = MyDequeItem<T>*;
        MyDeque(): deque_size(0)
        {
            head = tail = nullptr;
        }

        ~MyDeque()
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


        /// Получить количество элементов в деке
        std::size_t size() noexcept
        {
            return deque_size;
        }

        /// Проверка на пустой дек
        bool empty()
        {
            return deque_size == 0;
        }

        /// Получить значение по индексу
        T& at(int index)
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

        const T& at(int index) const
        {
            return at(index);
        }

        /// Вставить значение в конец
        void push_back(const T& value)
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

        /// Вставить значение в начало
        void push_front(const T& value)
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

        /// Получить значение в конце
        T& back()
        {
            if(empty())
            {
                throw "the deque is empty";
            }
            return tail->get_data();
        }

        const T& back() const
        {
            return back();
        }

        /// Получить значение в начале
        T& front()
        {
            if(empty())
            {
                throw "the deque is empty";
            }
            return head->get_data();
        }
        const T& front() const
        {
            return front();
        }

        /// Вставить значение в определенную позицию в деке
        void insert(const T& value, int position)
        {
            if (position < 0 || position >= (int)deque_size) 
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
                {
                    curr = curr->get_next();
                }
            
                node_elem tmp = new MyDequeItem<T>(value);
                tmp->set_prev(curr->get_prev());
                curr->get_prev()->set_next(tmp);
                curr->set_prev(tmp);
                tmp->set_next(curr);
                deque_size++;
            }
        }

        /// Удалить элемент с конца
        void pop_back()
        {
            if(empty()) return;

            node_elem tmp = tail;
            tail = tail->get_prev();
            tail->set_next(nullptr);
            delete tmp;
            deque_size--;
        }

        /// Удалить элемент с начала
        void pop_front()
        {
            if(empty()) return;

            node_elem tmp = head;
            head = head->get_next();
            head->set_prev(nullptr);
            delete tmp;
            deque_size--;
        }

        /// Удалить элемент в деке на определенной позиции
        void erase(int position)
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
                {
                    curr = curr->get_next();
                }
        
                curr->get_prev()->set_next(curr->get_next());
                curr->get_next()->set_prev(curr->get_prev());
                delete curr;
                deque_size--;
            }
        }

        /// Очистить весь дек
        void clear()
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

        /// Вывести дек в консоль
        void print_deque()
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
};

#endif

