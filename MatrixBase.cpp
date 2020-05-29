#include "MatrixBase.h"

void MatrixBase::operator*= (int iMult)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			matrix[i][j] = matrix[i][j] * iMult;
}

void MatrixBase::operator+=(MatrixBase iAdd)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			matrix[i][j] = matrix[i][j] + iAdd.element(i, j);
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
	for (int i = 0; i < iMatrix.size(); i++)
	{
		for (int j = 0; j < iMatrix.size(); j++)
			stream << iMatrix.element(i, j) << "\t";
		stream << "\n";
	}
	return stream;
}
