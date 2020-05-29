#pragma once
#include "MatrixBase.h"

class Matrix3D : public MatrixBase
{
public:
	explicit Matrix3D(unsigned int iSize);

	~Matrix3D() { delete[] matrix; }

	int element(unsigned int i, unsigned int j) const override { return matrix[i][j]; }
	int& element(unsigned int i, unsigned int j) override { return matrix[i][j]; }
};