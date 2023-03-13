#include <iostream>
#include <ostream>
#include "anthill.h"

void print_menu();
void set_exctracted(task2::Anthill&);
void set_percent(task2::Anthill&);
void set_destroyed_pests(task2::Anthill&);
void extract_meal(task2::Anthill&);
void eat(task2::Anthill&);
void increase(task2::Anthill&);
void destroy(task2::Anthill&);
void add_pests(task2::Anthill&);

int main(int argc, char *argv[])
{
    std::cout << "Добро пожаловать в муравейник!!!" << std::endl;
    std::cout << "Введите стартовые данные" << std::endl;
    int larvas_start_count, workers_start_count, police_start_count, soldiers_start_count, pests, meal, larvas_create_count;
    std::cout << "Начальное количество личинок -> ";
    std::cin >> larvas_start_count;
    std::cout << "Начальное количество рабочих -> ";
    std::cin >> workers_start_count;
    std::cout << "Начальное количество полицейских -> ";
    std::cin >> police_start_count;
    std::cout << "Начальное количество солдат -> ";
    std::cin >> soldiers_start_count;
    std::cout << "Начальное количество вредителей -> ";
    std::cin >> pests;
    std::cout << "Начальное количество еды -> ";
    std::cin >> meal;
    std::cout << "Количество личинок, рождаемых одной маткой -> ";
    std::cin >> larvas_create_count;

    task2::Anthill anthill{larvas_start_count, 
        workers_start_count, 
        police_start_count,
        soldiers_start_count,
        pests,
        meal,
        larvas_create_count};

    bool end = false;
    while(!end)
    {
        print_menu();
        int number = 0;
        std::cout << std::endl;
        std::cout << "Введите номер действия: ";
        std::cin >> number;
        switch (number) 
        {
            case 1:
                set_exctracted(anthill);
                break;
            case 2:
                set_percent(anthill);
                break;
            case 3:
                set_destroyed_pests(anthill);
                break;
            case 4:
                anthill.print_anthill_info();
                break;
            case 5: 
                extract_meal(anthill);
                break;
            case 6: 
                eat(anthill);
                break;
            case 7: 
                increase(anthill);
                break;
            case 8: 
                destroy(anthill);
                break;
            case 9: 
                add_pests(anthill);
                break;
            case 10: 
                anthill.reborn_last_larva();
                std::cout << "Последняя личинка была успешно перерождена" << std::endl;
                break;
            case 11: 
                anthill.create_new_larvas();
                std::cout << "В муравейнике появилось " << anthill.get_mother().get_larvas_count() << " новых личинок" << std::endl;
                break;
            case 12:
                end = true;
                break;
            default:
                std::cerr << "Введен неверный номер действия" << std::endl;
                break;
        }
        std::cout << std::endl;
    }
    return 0;
}


void print_menu()
{
    std::cout << "Предлагаемые действия:" << std::endl;
    std::cout << "1. Установить значения добываемой еды для рабочих;" << std::endl;
    std::cout << "2. Установить процент увеличения еды для полицейских;" << std::endl;
    std::cout << "3. Установить значение количества уничтожаемых вредителей для солдат;" << std::endl;
    std::cout << "4. Получить информацию о муравейнике;" << std::endl;
    std::cout << "5. Добыть еду;" << std::endl;
    std::cout << "6. Покушать всем;" << std::endl;
    std::cout << "7. Увеличить общее количество еды;" << std::endl;
    std::cout << "8. Уничтожить количество вредителей;" << std::endl;
    std::cout << "9. Добавить количество вредителей;" << std::endl;
    std::cout << "10. Переродить последнюю личинку;" << std::endl;
    std::cout << "11. Заставить матку нарожать новых личинок;" << std::endl;
    std::cout << "12. Выйти из муравейника;" << std::endl;
}

void set_exctracted(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Введите количество добываемой еды: ";
    std::cin >> count;
    ant.set_extracted_for_workers(count);
    std::cout << "Успешно" << std::endl;
}

void set_percent(task2::Anthill& ant)
{
    int percent = 0;
    std::cout << "Введите процент увеличения еды: ";
    std::cin >> percent;
    ant.set_percents_for_policemans(percent);
    std::cout << "Успешно" << std::endl;
}

void set_destroyed_pests(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Введите количество уничтожаемых вредителей: ";
    std::cin >> count;
    ant.set_pests_for_soldiers(count);
    std::cout << "Успешно" << std::endl;
}

void extract_meal(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Введите количество рабочих, которые добудут еду в муравейник: ";
    std::cin >> count;
    try
    {
        ant.extract_meal(count);
        std::cout << "Еда была добыта успешно" << std::endl;
    }
    catch(const char* msg)
    {
        std::cerr << "Ошибка: " << msg << std::endl;
    }
}

void eat(task2::Anthill& ant)
{
    try
    {
        ant.eat_together();
        std::cout << "Процесс поедания прошел успешно. Остаток по еде: " << ant.get_meal() << std::endl;
    }
    catch(const char* msg)
    {
        std::cout << msg << std::endl;
    }
}

void increase(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Введите количество полицейских, которые увеличат количество еды в процентном соотношении в муравейнике: ";
    std::cin >> count;
    try
    {
        ant.increase_meal(count);
        std::cout << "Еда была увеличена успешно. Текущее количество еды: " << ant.get_meal() << std::endl;
    }
    catch(const char* msg)
    {
        std::cerr << "Ошибка: " << msg << std::endl;
    }
}

void destroy(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Введите количество солдат, которые уничтожат вредителей: ";
    std::cin >> count;
    try
    {
        ant.destroy_pests(count);
        std::cout << "Вредители были уничтожены успешно. Вредителей осталось: " << ant.get_pests() << std::endl;
    }
    catch(const char* msg)
    {
        std::cerr << "Ошибка: " << msg << std::endl;
    }
}

void add_pests(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Введите количество вредителей: ";
    std::cin >> count;
    ant.create_pests(count);
    std::cout << "Вредители были добавлены успешно. Вредителей осталось: " << ant.get_pests() << std::endl;
}

