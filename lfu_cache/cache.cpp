#include "cache.hpp"
#include "page.hpp"

using namespace cache;

cache_t::cache_t(const int capacity)
    : capacity_{capacity}, total_timecounts{0}, cache_map{}, cache_frequencies{}, cache_timecounts{} 
{
}

void cache_t::append(int key, const page_t &value)
{

}

void cache_t::remove(int key)
{

}

void cache_t::cache_clear()
{

}

page_t cache_t::get(int key)
{
}
