#include "insects.h"
#include <exception>
#include <cstdlib>
using namespace task2;

// Реализация класса личинки

Larva::Larva(): BaseInsect(){}

Larva::Larva(int meal): BaseInsect(meal){}


INSECT_TYPE Larva::reborn()
{
    // Просто случайным образом получаем тип перерожденной личинки
    return (INSECT_TYPE)(random() % 3);  
}


// Реализация класса муравья - рабочего

Worker::Worker(): BaseInsect()
{
    meal_extracted = 0;
}

Worker::Worker(int meal, int extracted): BaseInsect(meal), meal_extracted(extracted){}

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

Police::Police(): BaseInsect()
{
    meal_percent = 0;
}

Police::Police(int meal, int percent): BaseInsect(meal), meal_percent(percent){}

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
    all_meal += all_meal * meal_percent / 100;
}


// Реализация класса муравья - солдата

Soldier::Soldier(): BaseInsect()
{
    pest_destroyed_count = 0;
}

Soldier::Soldier(int meal, int count): BaseInsect(meal), pest_destroyed_count(count){}

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
    if(all_pests < 0)
        all_pests = 0;
}


// Реализация класса муравья - матки

Mother::Mother(): BaseInsect()
{
    new_larvas_count = 0;
}

Mother::Mother(int meal, int count): BaseInsect(meal), new_larvas_count(count){}

int Mother::get_larvas_count()
{
    return new_larvas_count;
}

void Mother::set_larvas_count(int count)
{
    new_larvas_count = count;
}

