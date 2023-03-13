#include "insects.h"
#include <exception>
#include <cstdlib>
using namespace task2;

// Реализация класса личинки

Larva::Larva(): meal_count(0){}

Larva::Larva(int meal): meal_count(meal){}

int Larva::get_meal_count()
{
    return meal_count;
}

void Larva::set_meal_count(int count)
{
    meal_count = count;
}

void Larva::eat(int &all_meat)
{
    if(all_meat - meal_count < 0)
    {
        throw "Еда закончилась в муравейнике. Теперь у муравья проблемы...";
    }
    all_meat -= meal_count;
}

INSECT_TYPE Larva::reborn()
{
    // Просто случайным образом получаем тип перерожденной личинки
    return (INSECT_TYPE)(random() % 3);  
}


// Реализация класса муравья - рабочего

Worker::Worker(): Larva()
{
    meal_extracted = 0;
}

Worker::Worker(int meal, int extracted): Larva(meal), meal_extracted(extracted){}

int Worker::get_meal_extracted()
{
    return meal_extracted;
}

void Worker::set_meal_extracted(int extracted)
{
    meal_extracted = extracted;
}

void Worker::extract(int &all_meal)
{
    all_meal += meal_extracted;
}


//  Реализация класса муравья - полицейского

Police::Police(): Larva()
{
    meal_percent = 0;
}

Police::Police(int meal, int percent): Larva(meal), meal_percent(percent){}

int Police::get_meal_percent()
{
    return meal_percent;
}

void Police::set_meal_percent(int percent)
{
    meal_percent = percent;
}

void Police::increase(int &all_meal)
{
    all_meal += all_meal * (meal_percent / 100);
}


// Реализация класса муравья - солдата

Soldier::Soldier(): Larva()
{
    pest_destroyed_count = 0;
}

Soldier::Soldier(int meal, int count): Larva(meal), pest_destroyed_count(count){}

int Soldier::get_pest_count()
{
    return pest_destroyed_count;
}

void Soldier::set_pest_count(int count)
{
    pest_destroyed_count = count;
}

void Soldier::destroy(int &all_pests)
{
    all_pests -= pest_destroyed_count;
}


// Реализация класса муравья - матки

Mother::Mother(): Larva()
{
    new_larvas_count = 0;
}

Mother::Mother(int meal, int count): Larva(meal), new_larvas_count(count){}

int Mother::get_larvas_count()
{
    return new_larvas_count;
}

void Mother::set_larvas_count(int count)
{
    new_larvas_count = count;
}

