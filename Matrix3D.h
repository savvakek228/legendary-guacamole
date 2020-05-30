#pragma once
#include "MatrixBase.h"

class Matrix3D : public MatrixBase
{
public:
	explicit Matrix3D();
	int element(unsigned int i, unsigned int j) const override { return matrix[i*size+j]; }
	int& element(unsigned int i, unsigned int j) override { return matrix[i*size+j]; }
private:
    static constexpr int size = 3;
	int matrix[size*size];
};