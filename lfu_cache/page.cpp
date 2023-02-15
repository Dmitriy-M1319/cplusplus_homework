#include "page.hpp"
#include <stdexcept>
#include <cstring>

using namespace cache;

page_t::page_t(int size)
{
    d_size = size;
    data = new char[d_size];
}

page_t::page_t(): d_size(0), data(nullptr){}

page_t::page_t(int size, const char *data)
{
    d_size = size + 1;
    this->data = new char[d_size];
    if(sizeof(data) > sizeof(this->data))
        throw std::invalid_argument("Too big input data");
    else
    {
        strncpy(this->data, data, size);
        this->data[size] = '\0';
    }
}

page_t::~page_t()
{
    delete[] data;
}

int page_t::size() { return d_size; };

const char *page_t::get_data() { return data; }
