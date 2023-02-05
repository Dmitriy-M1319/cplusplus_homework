#ifndef CACHE_H 
#define CACHE_H

#include <unordered_map>
#include <string>
#include "page.hpp"

namespace cache
{
    class cache_t
    { 
    private:
        std::unordered_map<int, page_t> cache_map;
        std::unordered_map<int, int> cache_frequencies;
        std::unordered_map<int, int> cache_timecounts;
        int capacity_;
        int total_timecounts;
    public:
        cache_t(const int capacity);
        void append(int key, const page_t& value);
        void remove(int key);
        void cache_clear();
        page_t get(int key);
    };

}
#endif
