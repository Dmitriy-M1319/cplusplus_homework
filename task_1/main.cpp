#include <iostream>
#include <ostream>
#include "matrix.h"


int main(int argc, const char *argv[])
{
    int rows = 0;
    int cols = 0;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
    
    task1::Matrix m1(rows, cols);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            std::cout << "Введите значение для " << i << " строки " << j << " столбца: ";
            int a = 0;
            std::cin >> a;
            m1.set_elem(i,  j, a);
        }
    }

    std::cout << std::endl;
    std::cout << "Введенная матрица:" << std::endl;
    m1.print();
    m1.swap_columns();
    std::cout << "Измененная матрица:" << std::endl;
    m1.print();
    return 0;
}
