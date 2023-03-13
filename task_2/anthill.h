#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>
#include "insects.h"

namespace task2
{
    class Anthill
    {
    private:
        // Коллекция личинок в муравейнике
        std::vector<Larva> larvas;

        // Коллекция рабочих в муравейнике
        std::vector<Worker> workers;

        // Коллекция полицейских в муравейнике
        std::vector<Police> policemans;

        // Коллекция солдат в муравейнике
        std::vector<Soldier> soldiers;

        // матка
        Mother mother;
        // Количество еды
        int meal;
        // Количество вредителей
        int pests;

        // Флаг, показывающий наличие проблем в процессе поедания
        bool meal_error_flag = false;
        // Шаблонная функция для организации процесса поедания определенного типа муравьев
        template<typename T> void eat_larva_childs(std::vector<T> insects);
    public:
        const static int larva_meal = 1;
        const static int worker_meal = 3;
        const static int police_meal = 5;
        const static int soldier_meal = 8;
        const static int mother_meal = 10;
        
        Anthill();
        Anthill(int larvas_start_count, 
                int workers_start_count, 
                int police_start_count,
                int soldiers_start_count,
                int pests,
                int meal,
                int larvas_create_count);

        void print_anthill_info();

        int get_meal();
        int get_pests();
        Mother get_mother();

        void set_extracted_for_workers(int extracted);
        void set_percents_for_policemans(int percent);
        void set_pests_for_soldiers(int count);
        
        std::vector<Larva>& get_larvas();
        std::vector<Worker>& get_workers();
        std::vector<Police>& get_policemans();
        std::vector<Soldier>& get_soldiers();

        /**
         * Добыча еды определенным количеством рабочих
         */
        void extract_meal(int workers_count);

        /**
         * Покушать всем
         */
        void eat_together();

        /**
         * Увеличить запас еды
         */
        void increase_meal(int police_count); 

        /**
         * Уничтожить определенное количество вредителей
         */
        void destroy_pests(int soldier_count);

        /**
         * Добавить новых вредителей
         */
        void create_pests(int pests_count);

        /**
         * Заставить последнюю личинку переродиться
         */
        void reborn_last_larva(); 

        /**
         * Заставить матку наплодить новых личинок
         */
        void create_new_larvas();
    };
};
#endif
