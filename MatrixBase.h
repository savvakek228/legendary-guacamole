#pragma once
#include <fstream>

class MatrixBase
{
public:
	MatrixBase() = delete;
	unsigned int size() const { return m_size; }
	virtual int element(unsigned int i, unsigned int j) const { return matrix[i][j]; };
	virtual int& element(unsigned int i, unsigned int j) { return matrix[i][j]; };
	void operator*=(int iMult);
	void operator+=(MatrixBase iAdd);
	friend std::ostream& operator<<(std::ostream&, const MatrixBase&);
protected:
	explicit MatrixBase(unsigned int iSize) { m_size = iSize; }
	int** matrix;

private:
	unsigned int m_size;
};

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);
