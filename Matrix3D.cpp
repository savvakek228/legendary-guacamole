#include "Matrix3D.h"

Matrix3D::Matrix3D(unsigned int iSize) : MatrixBase(iSize)
{
	matrix = new int* [iSize];
	for (unsigned int i = 0; i < iSize; i++)
	{
		matrix[i] = new int[iSize];
		for (int j = 0; j < iSize; j++)
			matrix[i][j] = i * iSize + j + 1;
	}
}