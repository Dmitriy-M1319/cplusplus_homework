#include "anthill.h"
#include "insects.h"
#include <iostream>
#include <vector>
using namespace task2;

Anthill::Anthill(): larvas(std::vector<Larva>()), workers(std::vector<Worker>()),
    policemans(std::vector<Police>()), soldiers(std::vector<Soldier>()), mother(Mother()), meal(0), pests(0) {}

Anthill::Anthill(int larvas_start_count, 
                int workers_start_count, 
                int police_start_count,
                int soldiers_start_count,
                int pests,
                int meal,
                int larvas_create_count)
{
    larvas.resize(larvas_start_count);
    for (int i = 0; i < larvas_start_count; i++) 
    {
        larvas.push_back(Larva(larva_meal));
    }

    workers.resize(workers_start_count);
    for (int i = 0; i < workers_start_count; i++) 
    {
        workers.push_back(Worker(worker_meal, 0));
    }

    policemans.resize(police_start_count);
    for (int i = 0; i < police_start_count; i++) 
    {
       policemans.push_back(Police(police_meal, 0));
    }

    soldiers.resize(soldiers_start_count);
    for (int i = 0; i < soldiers_start_count; i++) 
    {
       soldiers.push_back(Soldier(soldier_meal, 0));
    }

    mother.set_meal_count(mother_meal);
    mother.set_larvas_count(larvas_create_count);

    this->meal = meal;
    this->pests = pests;

}

int Anthill::get_meal()
{
    return meal;
}

int Anthill::get_pests()
{
    return pests;
}

Mother Anthill::get_mother()
{
    return mother;
}

void Anthill::set_extracted_for_workers(int extracted)
{
    for(auto worker: workers)
    {
        worker.set_meal_extracted(extracted);
    }
}


void Anthill::set_pests_for_soldiers(int count)
{
    for(auto soldier: soldiers)
    {
        soldier.set_meal_count(count);
    }
}


void Anthill::set_percents_for_policemans(int percent)
{
    for(auto police: policemans)
    {
        police.set_meal_percent(percent);
    }
}


std::vector<Larva>& Anthill::get_larvas()
{
    return larvas;
}


std::vector<Worker>& Anthill::get_workers()
{
    return workers;
}


std::vector<Police>& Anthill::get_policemans()
{
    return policemans;
}

std::vector<Soldier>& Anthill::get_soldiers()
{
    return soldiers;
}

void Anthill::extract_meal(int workers_count)
{
    if(workers_count > workers.size() || workers_count < 0)
    {
        throw "Введено неверное количество рабочих";
    }
    for(int i = 0; i < workers_count; i++)
    {
        workers[i].extract(meal);
    }
}

template<typename T>
void Anthill::eat_larva_childs(std::vector<T> insects)
{
    for (auto iter = insects.begin(); iter != insects.end(); iter++) 
    {
        try
        {
            (*iter).eat(meal);
        }
        catch(const char* msg)
        {
            std::cout << msg << std::endl;
            insects.erase(iter);
            meal_error_flag = true;
        }
    }
}

void Anthill::eat_together()
{
    mother.eat(meal);
    eat_larva_childs(larvas);
    eat_larva_childs(workers);
    eat_larva_childs(policemans);
    eat_larva_childs(soldiers);
    if(meal_error_flag)
        throw "Процесс поедания прошел не успешно";
}

void Anthill::increase_meal(int police_count)
{
    if(police_count > policemans.size() || police_count < 0)
    {
        throw "Введено неверное количество полицейских";
    }
    for(int i = 0; i < police_count; i++)
    {
        policemans[i].increase(meal);
    }
}

void Anthill::destroy_pests(int soldier_count) 
{

    if(soldier_count > soldiers.size() || soldier_count < 0)
    {
        throw "Введено неверное количество солдат";
    }
    for(int i = 0; i < soldier_count; i++)
    {
        soldiers[i].destroy(pests);
    }
}

void Anthill::create_pests(int pests_count)
{
    pests += pests_count;
}

void Anthill::reborn_last_larva()
{
   INSECT_TYPE type = larvas.end()->reborn();
   switch (type) 
   {
        case INSECT_TYPE::WORKER:
            {
                Worker new_worker{worker_meal, 0}; 
                workers.push_back(new_worker);
                break;
            }
        case INSECT_TYPE::POLICE:
            {
                Police new_police{police_meal, 0}; 
                policemans.push_back(new_police);
                break;
            }
        case INSECT_TYPE::SOLDIER:
            {
                Soldier new_soldier{soldier_meal, 0}; 
                soldiers.push_back(new_soldier);
                break;
            }
   }
   larvas.pop_back();
}

void Anthill::create_new_larvas()
{
    for(int i = 0; i < mother.get_larvas_count(); i++)
    {
        Larva larv{larva_meal};
        larvas.push_back(larv);
    }
}

void Anthill::print_anthill_info()
{
    std::cout << "Информация о муравейнике:" << std::endl;
    std::cout << "1. Личинки. Количество личинок " << larvas.size() << ":" << std::endl;
    for (auto larva : larvas) 
    {
        std::cout << "  Личинка: Количество еды - " << larva.get_meal_count();
    }

    std::cout << "2. Рабочие. Количество рабочих " << workers.size() << ":" << std::endl;
    for (auto worker : workers) 
    {
        std::cout << "  Рабочий: Количество еды - " << worker.get_meal_count() << ", Количество добываемой еды - " << worker.get_meal_extracted() << std::endl;
    }

    std::cout << "3. Полицейские. Количество полицейских " << policemans.size() << ":" << std::endl;
    for (auto police : policemans) 
    {
        std::cout << "  Полицейский: Количество еды - " << police.get_meal_count() << ", Процент увеличения еды - " << police.get_meal_percent() << std::endl;
    }

    std::cout << "4. Солдаты. Количество солдат " << soldiers.size() << ":" << std::endl;
    for (auto soldier : soldiers) 
    {
        std::cout << "  Солдат: Количество еды - " << soldier.get_meal_count() << ", Количество убиваемых вредителей - " << soldier.get_pest_count() << std::endl;
    }

    std::cout << "5. Матка. Количество еды: " << mother.get_meal_count() << ", Количество личинок: " << mother.get_larvas_count() << std::endl;
    std::cout << "6. Общее количество еды: " << meal << std::endl;
    std::cout << "7. Общее количество вредителей: " << pests << std::endl;
}
