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
        int capacity_;
        int cache_size;
        int total_timecounts;
        std::unordered_map<int, int> cache_frequencies{};
        std::unordered_map<int, int> cache_timecounts{};
    public:
        cache_t(const int capacity);
        std::unordered_map<int, std::string> cache_map{};
        void append(int key, const std::string& value);
        void remove_old();
        void remove(int key);
        void cache_clear();
        int get_cache_size();
        std::string get(int key);
    };

}
#endif
