#ifndef MATRIXINTERFACE_H
#define MATRIXINTERFACE_H

#include <vector>
#include <string>

/*
   vector<vector<int> > matrix(RR);
for ( int i = 0 ; i < RR ; i++ )
   matrix[i].resize(CC);
*/

namespace standardMatrix {

class Matrix
{
    typedef std::vector<int>::size_type size_type; // convenience typedef

private:
    // int variables that defines the number of columns and rows of the matrix
    size_type rowCount;
    size_type colCount;

    // vectors that represent the actual matrix
    std::vector<std::vector<int>> matrix;

    bool is2by2;
    bool is3by3;

public:
    Matrix(std::vector<int>::size_type row = 3, std::vector<int>::size_type col = 3);

    void push_back(int value);
    void clear();
    void assign(size_type row, size_type col, int value);
    void reserve(size_type value);
    void resize(size_type newSize);
    Matrix setRows(size_type nRows);
    Matrix setColumns(size_type nCols);
    int at(size_type row, size_type col);
    std::string toString(size_type row, size_type col);

    //convenience getters
    size_type getRows() const { return rowCount; } // implicitly inline
    size_type getColumns() const { return colCount; }

    friend const Matrix operator+(const Matrix &lhs, const Matrix &rhs)
    {
        typedef std::vector<int>::size_type size_type; // convenience typedef

        if (lhs.getRows() != rhs.getRows() && lhs.getColumns() != rhs.getColumns())
        {
            exit(-1);
        }

        Matrix _Matrix(lhs.rowCount, lhs.colCount);

        if ((lhs.is2by2 && rhs.is2by2) || (lhs.is3by3 && rhs.is3by3))
        {
            for (size_type i = 0; i < lhs.rowCount; ++i) {
                for (size_type j = 0; j < lhs.colCount; ++j)
                {
                    _Matrix.matrix[i][j] = lhs.matrix[i][j] + rhs.matrix[i][j];
                }
            }
        }

        return _Matrix;
    }
    friend const Matrix operator-(const Matrix &lhs, const Matrix &rhs)
    {
        return lhs + (rhs * -1);
    }
    friend const Matrix operator*(const Matrix &lhs, const Matrix &rhs)
    {
        typedef std::vector<int>::size_type size_type; // convenience typedef

        Matrix _Matrix(lhs.rowCount, lhs.colCount);

        for (size_type i = 0; i < lhs.rowCount; ++i)
        {
            for (size_type j = 0; j < lhs.colCount; ++j) {
                for (size_type u = 0; u < lhs.rowCount; ++u) {
                    _Matrix.matrix[i][j] += lhs.matrix[i][u] * rhs.matrix[u][j];
                }

            }
        }

        return _Matrix;
    }
    friend const Matrix operator*(const int num, const Matrix &rhs)
    {
        typedef std::vector<int>::size_type size_type; // convenience typedef

        Matrix _Matrix(rhs.rowCount, rhs.colCount);

        for (size_type i = 0; i < rhs.rowCount; ++i)
        {
            for (size_type j = 0; j < rhs.colCount; ++j)
                _Matrix.matrix[i][j] = num * rhs.matrix[i][j];
        }

        return _Matrix;
    }
    friend const Matrix operator*(const Matrix &lhs, const int num)
    {
        typedef std::vector<int>::size_type size_type; // convenience typedef

        Matrix _Matrix(lhs.rowCount, lhs.colCount);

        for (size_type i = 0; i < lhs.rowCount; ++i)
        {
            for (size_type j = 0; j < lhs.colCount; ++j)
                _Matrix.matrix[i][j] = num * lhs.matrix[i][j];
        }

        return _Matrix;
    }


};

}

#endif // MATRIXINTERFACE_H
