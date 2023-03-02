#include "matrix.h"
#include <iostream>
using namespace task1;


Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    array = new int*[rows];
    for (int i = 0; i < rows; i++) 
    {
        array[i] = new int[cols]; 
    }
}

Matrix::Matrix(int rows, int cols, int **arr): Matrix(rows, cols)
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            array[i][j] = arr[i][j]; 
        }
    }
}


Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] array[i];
    }

    delete[] array;
}

void Matrix::set_elem(int i, int j, int value)
{
    array[i][j] = value;
}

void Matrix::swap_columns()
{
    for (int i = 0; i < cols / 2; i++) 
    {
        for (int j = 0; j < rows; j++)
        {
            int tmp = array[j][i]; 
            array[j][i] = array[j][cols - 1 - i];
            array[j][cols - 1 - i] = tmp;
        }
    } 
}



void Matrix::print()
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
