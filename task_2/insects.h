#ifndef INSECTS_H
#define INSECTS_H

namespace task2
{
    /**
     * Перечисление, которое определят тип муравья, в который переродится личинка
     */
    enum class INSECT_TYPE
    {
        WORKER = 0,
        POLICE = 1,
        SOLDIER = 2
    };

    /**
     * Класс личинки муравья
     */
    class Larva
    {
    protected:
        int meal_count;
    public:
        Larva();
        Larva(int meal);
        int get_meal_count();
        void set_meal_count(int count);
        void eat(int& all_meat);
        INSECT_TYPE reborn();
    };

    /**
     * Класс муравья - рабочего
     */
    class Worker: Larva
    {
    private:
        int meal_extracted;
    public:
        Worker();
        Worker(int meal, int extracted);
        int get_meal_extracted();
        void set_meal_extracted(int extracted);
    };

    /*
     * Класс муравья - полицейского 
     */
    class Police: Larva
    {
    private:
        int meal_percent;
    public:
        Police();
        Police(int meal, int percent);
        int get_meal_percent();
        void set_meal_percent(int percent);
        void increase(int& all_meal);
    };

    /**
     * Класс муравья - солдата
     */
    class Soldier: Larva
    {
    private:
        int pest_destroyed_count;
    public:
        Soldier();
        Soldier(int meal, int count);
        int get_pest_count();
        void set_pest_count(int count);
        void destroy(int& all_pests);
    };

    /**
     * Класс муравья - матки
     */
    class Mother: Larva
    {
    private:
        int new_larvas_count;
    public:
        Mother();
        Mother(int meal, int count);
        int get_larvas_count();
        void set_larvas_count(int count);
    };
};

#endif
