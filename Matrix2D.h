#pragma once
#include "MatrixBase.h"

class Matrix2D: public MatrixBase
{
public:
    explicit Matrix2D ();
	int element(unsigned int i, unsigned int j) const override { return matrix[i*size+j]; }
	int& element(unsigned int i, unsigned int j) override { return matrix[i*size+j]; }
private:
    static constexpr int size = 2;
    int matrix[size * size];

};