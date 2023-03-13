#define BOOST_TEST_MODULE Anthill Test
#include <boost/test/included/unit_test.hpp>
#include "anthill.h"


// Модульные тесты для муравейника

task2::Anthill get_anthill()
{
    int larvas_start_count = 5;
    int workers_start_count = 10;
    int police_start_count = 15;
    int soldiers_start_count = 20;
    int pests = 27;
    int meal = 10000;
    int larvas_create_count = 5;

    task2::Anthill anthill(larvas_start_count,
            workers_start_count,
            police_start_count,
            soldiers_start_count,
            pests,
            meal,
            larvas_start_count);
    return anthill;
}

BOOST_AUTO_TEST_CASE(anthill_create_test)
{
    auto anthill = get_anthill(); 

    BOOST_TEST(anthill.get_larvas().size() == 5);
    BOOST_TEST(anthill.get_workers().size() == 10);
    BOOST_TEST(anthill.get_policemans().size() == 15);
    BOOST_TEST(anthill.get_soldiers().size() == 20);
    BOOST_TEST(anthill.get_meal() == 10000);
    BOOST_TEST(anthill.get_pests() == 27);
}


BOOST_AUTO_TEST_CASE(anthill_set_extracted_meal_test)
{
    auto anthill = get_anthill(); 

    anthill.set_extracted_for_workers(25);
    for(auto worker: anthill.get_workers())
    {
        BOOST_TEST(worker.get_meal_extracted() == 25);
    }
}

BOOST_AUTO_TEST_CASE(anthill_set_increased_percent_test)
{
    auto anthill = get_anthill(); 

    anthill.set_percents_for_policemans(40);
    for(auto police: anthill.get_policemans())
    {
        BOOST_TEST(police.get_meal_percent() == 40);
    }
}


BOOST_AUTO_TEST_CASE(anthill_set_destroyed_pests_test)
{
    auto anthill = get_anthill(); 

    anthill.set_pests_for_soldiers(40);
    for(auto soldier: anthill.get_soldiers())
    {
        BOOST_TEST(soldier.get_pest_count() == 40);
    }
}

BOOST_AUTO_TEST_CASE(anthill_extract_meal_test)
{
    auto anthill = get_anthill(); 
    anthill.set_extracted_for_workers(20);

    anthill.extract_meal(3);

    BOOST_TEST(anthill.get_meal() == 10060);
}

BOOST_AUTO_TEST_CASE(anthill_eat_together_test)
{
    auto anthill = get_anthill(); 
    try
    {
        anthill.eat_together();
        BOOST_TEST(true);
    }
    catch(const char* msg)
    {
        BOOST_TEST(false);
    }
}

BOOST_AUTO_TEST_CASE(anthill_increase_meal_test)
{
    auto anthill = get_anthill(); 
    anthill.set_percents_for_policemans(50);

    anthill.increase_meal(2);

    BOOST_TEST(anthill.get_meal() == 22500);
}

BOOST_AUTO_TEST_CASE(anthill_destroy_pests_test_1)
{
    auto anthill = get_anthill(); 
    anthill.set_pests_for_soldiers(5);

    anthill.destroy_pests(3);

    BOOST_TEST(anthill.get_pests() == 12);
}

BOOST_AUTO_TEST_CASE(anthill_destroy_pests_test_2)
{
    auto anthill = get_anthill(); 
    anthill.set_pests_for_soldiers(7);

    anthill.destroy_pests(4);

    BOOST_TEST(anthill.get_pests() == 0);
}

BOOST_AUTO_TEST_CASE(anthill_create_pests_test)
{
    auto anthill = get_anthill(); 

    anthill.create_pests(12);

    BOOST_TEST(anthill.get_pests() == 39);
}

BOOST_AUTO_TEST_CASE(anthill_create_new_larvas_test)
{
    auto anthill = get_anthill(); 

    int prev_size = anthill.get_larvas().size();

    anthill.create_new_larvas();

    BOOST_TEST(anthill.get_larvas().size() - prev_size == anthill.get_mother().get_larvas_count());
}
