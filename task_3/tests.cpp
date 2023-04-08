#define BOOST_TEST_MODULE Deque Tests
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "my_deque.h"

BOOST_AUTO_TEST_CASE(deque_test_1)
{
    my_deque::MyDeque<int> deq;
    deq.push_back(5);
    deq.erase(0);
    BOOST_ASSERT(deq.empty());
}

BOOST_AUTO_TEST_CASE(deque_test_2)
{
    my_deque::MyDeque<int> deq;
    deq.push_front(5);
    deq.erase(0);
    BOOST_ASSERT(deq.empty());
}

BOOST_AUTO_TEST_CASE(deque_test_3)
{
    try
    {
        my_deque::MyDeque<int> deq;
        deq.at(1);
        BOOST_ASSERT(false);
    } catch(std::out_of_range)
    {
        BOOST_ASSERT(true);
    }
}
