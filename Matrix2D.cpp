#include "Matrix2D.h"

Matrix2D::Matrix2D() : MatrixBase(size)
{
	for (unsigned int i = 0; i < size*size; i++)
	{
			matrix[i] = i+1;
	}
}