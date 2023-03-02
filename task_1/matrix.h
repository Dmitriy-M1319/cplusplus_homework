#ifndef MATRIX_H
#define MATRIX_H

namespace task1
{
    class Matrix
    {
    private:
        int **array;
        int rows;
        int cols;
    public:
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, int **arr);
        ~Matrix();
        void set_elem(int i, int j, int value);
        void swap_columns();
        void print();
    };
};

#endif
