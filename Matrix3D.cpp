#include "Matrix3D.h"

Matrix3D::Matrix3D() : MatrixBase(size)
{
	for (unsigned int i = 0; i < size*size; i++)
	{
		matrix[i] = i + 1;
	}
}