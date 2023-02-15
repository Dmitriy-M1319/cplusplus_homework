#include "cache.hpp"
#include "page.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace cache;

cache_t::cache_t(const int capacity)
    : capacity_{capacity}, cache_size(0), total_timecounts{0}, cache_map{}, cache_frequencies{}, cache_timecounts{} 
{
}

void cache_t::remove_old()
{
    std::vector<std::pair<int, int>> mins{};
    auto min_freq = std::min_element(cache_frequencies.begin(), cache_frequencies.end(), 
            [](const auto& a, const auto& b) { return a.second < b.second;}) ;

    std::for_each(cache_frequencies.begin(), cache_frequencies.end(), 
            [min_freq, &mins](const std::pair<int, int>& a){if (a.second == min_freq->second) { mins.push_back(a); }});

    if(mins.size() > 1)
    {
       int random_key = mins[rand() % mins.size()].first;
       remove(random_key);
    }
    else
        remove(min_freq->first);
    
}

void cache_t::append(int key, const std::string& value)
{
    auto value_iter = cache_map.find(key);
    if(value_iter == cache_map.end())
    {
        if((int)cache_map.size() < capacity_)
        {
            cache_map[key] = value;
            cache_timecounts[key] = total_timecounts;
            cache_frequencies[key] = 1;
        }
        else
        {
            remove_old();
            cache_map[key] = value;
            cache_timecounts[key] = total_timecounts;
            cache_frequencies[key] = 1;
        }
        cache_size++;
    }
    else 
    { 
        cache_map[key] = value;
        cache_timecounts[key] = total_timecounts;
        cache_frequencies[key] += 1;
    }
}

void cache_t::remove(int key)
{
    auto value_p = cache_map.find(key);
    if(value_p == cache_map.end())
        throw std::out_of_range("not such key in cache");
    else
    {
        cache_map.erase(value_p);
        cache_timecounts.erase(key);
        cache_frequencies.erase(key);
    }
}

void cache_t::cache_clear()
{
    cache_map.clear();
    cache_timecounts.clear();
    cache_frequencies.clear();
    total_timecounts = 0;
}

std::string cache_t::get(int key)
{
    auto value_p = cache_map.find(key);
    if(value_p == cache_map.end())
        //throw std::out_of_range("not such key in cache");
        return "";
    else
        return value_p->second;
}

int cache_t::get_cache_size()
{
    return cache_size;
}
