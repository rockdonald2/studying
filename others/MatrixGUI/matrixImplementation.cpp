#include <matrixInterface.h>
#include <cstdlib>

using namespace standardMatrix;

Matrix::Matrix(std::vector<int>::size_type row, std::vector<int>::size_type col) : rowCount(row), colCount(col), matrix(rowCount)
{
    typedef std::vector<int>::size_type size_type; // convenience typedef
    // reserve as many spaces in the matrix as the row * col
    for (size_type i = 0 ; i < rowCount ; i++ )
    {
        matrix[i].resize(colCount);
        matrix[i][i] = 0;
    }

    if (row == 3 && col == 3)
    {
        is3by3 = true;
        is2by2 = false;
    }
    else if (row == 2 && col == 2) {
        is2by2 = true;
        is3by3 = false;
    }
}

void Matrix::clear()
{
    // clear base vector
    this->matrix.clear();
}

void Matrix::assign(Matrix::size_type row, Matrix::size_type col, int value)
{
    // assign value to a specific index
    this->matrix[row][col] = value;
}

void Matrix::resize(Matrix::size_type newSize)
{
    // adjust a new size to the matrix
    size_type oldSize = matrix.size();
    this->matrix.resize(newSize);
    for(size_type i = 0; i < oldSize; ++i)
    {
        this->matrix[i].resize(newSize);
    }
}

Matrix Matrix::setRows(Matrix::size_type nRows)
{
    this->rowCount = nRows;

    return *this; // make it chainable
}

Matrix Matrix::setColumns(Matrix::size_type nCols)
{
    this->colCount = nCols;

    return *this; // make it chainable
}

std::string Matrix::toString(Matrix::size_type row, Matrix::size_type col)
{
    return std::to_string(this->matrix[row][col]);
}



/*void Matrix::push_back(int value)
{
    this->matrix.push_back(value);
}

void Matrix::clear()
{
    this->matrix.clear();
}

void Matrix::assign(Matrix::size_type index, int value)
{
    this->matrix[index] = value;
}

void Matrix::reserve(Matrix::size_type value)
{
    this->matrix.reserve(value);
}

void Matrix::resize(Matrix::size_type newSize)
{
    this->matrix.resize(newSize);
}

void Matrix::setRows(Matrix::size_type nRows)
{
    this->rowCount = nRows;
}

void Matrix::setColumns(Matrix::size_type nCols)
{
    this->colCount = nCols;
}

int Matrix::at(Matrix::size_type index)
{
    return this->matrix.at(index);
}

std::string Matrix::toString(Matrix::size_type index)
{
    return std::to_string(this->matrix.at(index));
}*/
