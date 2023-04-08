#ifndef BASE_INSECT_H
#define BASE_INSECT_H

/* Сначала public, затем private/protected, cсылка смещается к названию переменной*/
/// Базовый класс насекомого, который умеет самое главное - есть
namespace task2
{
    class BaseInsect
    {
    protected:
        int meal_count;
    public:
        BaseInsect();
        BaseInsect(int meal);
        int get_meal_count();
        void set_meal_count(int count);
        void eat(int &all_meat);
    };

}

#endif
