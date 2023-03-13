#define BOOST_TEST_MODULE Insects Test
#include <boost/test/included/unit_test.hpp>
#include <cstdlib>
#include <ctime>
#include "insects.h"

// Модульные тесты для класса личинки

BOOST_AUTO_TEST_CASE(larva_eating_test_1)
{
    int meal = 10;
    task2::Larva larva{5};

    larva.eat(meal);

    BOOST_TEST(meal==5);
}

BOOST_AUTO_TEST_CASE(larva_eating_test_2)
{
    int meal = 10;
    task2::Larva larva{25};

    try
    {
        larva.eat(meal);
        BOOST_TEST(false);
    }
    catch(const char* msg)
    {

        BOOST_TEST(true);
    }
}


BOOST_AUTO_TEST_CASE(larva_reborn_test)
{
    srand(time(NULL));
    task2::Larva larva{5};
    for (int i = 0; i < 1000; i++) 
    {
        int type = static_cast<int>(larva.reborn());
        BOOST_TEST(type >= 0);
        BOOST_TEST(type < 3);
    }
}


// Модульные тесты для класса рабочего

BOOST_AUTO_TEST_CASE(worker_extract_meal_test)
{
    int all_meal = 10;
    task2::Worker worker{5, 20};

    worker.eat(all_meal);
    worker.extract(all_meal);
    
    BOOST_TEST(all_meal == 25);
}

BOOST_AUTO_TEST_CASE(worker_set_extract_meal_test)
{
    int all_meal = 10;
    task2::Worker worker{5, 20};

    worker.eat(all_meal);
    worker.set_meal_extracted(30);
    BOOST_TEST(all_meal == 5);
    BOOST_TEST(worker.get_meal_extracted() == 30);
}

// Модульные тесты для класса полицейского

BOOST_AUTO_TEST_CASE(police_increase_meal_test)
{
    int all_meal = 20;
    task2::Police police{10, 50};

    police.eat(all_meal);
    police.increase(all_meal);
    
    BOOST_TEST(all_meal == 15);
}

// Модульные тесты для класса солдата

BOOST_AUTO_TEST_CASE(soldier_destroy_pests_test_1)
{
    int pests = 20;
    task2::Soldier soldier{10, 10};

    soldier.destroy(pests);
    
    BOOST_TEST(pests == 10);
}

BOOST_AUTO_TEST_CASE(soldier_destroy_pests_test_2)
{
    int pests = 5;
    task2::Soldier soldier{10, 10};

    soldier.destroy(pests);
    
    BOOST_TEST(pests == 0);
}


// Модульные тесты для класса матки

BOOST_AUTO_TEST_CASE(mother_create_test)
{
    int larvas = 10;
    task2::Mother mother{25, 10};

    BOOST_TEST(larvas == mother.get_larvas_count());
}
