#include "Matrix2D.h"

Matrix2D::Matrix2D(unsigned int iSize) : MatrixBase(iSize)
{
	matrix = new int* [iSize];
	for (unsigned int i = 0; i < iSize; i++)
	{
		matrix[i] = new int[iSize];
		for (int j = 0; j < iSize; j++)
			matrix[i][j] = i * iSize + j + 1;
	}
}