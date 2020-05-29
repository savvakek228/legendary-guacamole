#pragma once
#include "MatrixBase.h"

class Matrix2D: public MatrixBase
{
public:
	explicit Matrix2D(unsigned int iSize);

	~Matrix2D() { delete[] matrix; }

	int element(unsigned int i, unsigned int j) const override { return matrix[i][j]; }
	int& element(unsigned int i, unsigned int j) override { return matrix[i][j]; }
};