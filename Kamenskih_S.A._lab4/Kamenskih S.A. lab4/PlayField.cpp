#include "PlayField.h"
#include <cassert>
#include <vector>
using namespace std;

vector<PlayField::CellIdx*> PlayField::getEmptyCells()
{
	vector<PlayField::CellIdx*> emptyCells;
	for (int i = 0; i < 9; i++)
	{
		if (fieldState[i] == csEmpty)
		{
			CellIdx cell = PlayField::CellIdx::GetCellIdx(i);
			emptyCells.push_back(&cell);
		}
	}
	return emptyCells;
}

PlayField PlayField::makeMove(CellIdx cell)
{
	if (mark == PlayField::csCross) mark = PlayField::csNought;
	else mark = PlayField::csCross;
	PlayField field = *this;
	int id = cell.GetCellID();
	assert(fieldState[id] == csEmpty || checkFieldStatus() == fsNormal);
	field.fieldState[id] = mark;
	return field;
}

bool PlayField::checkWin(PlayField::CellStatus mark, PlayField::CellStatus* fieldState)
{
	if (hasHorizontal(mark, fieldState) || hasVertical(mark, fieldState) || hasDiagonal(mark, fieldState))
		return true;
	else return false;
}

bool PlayField::hasHorizontal(PlayField::CellStatus mark, PlayField::CellStatus* fieldState)
{
	for (int i = 0; i < 3; i++)
		if (fieldState[0 + i * 3] == mark && fieldState[1 + i * 3] == mark && fieldState[2 + i * 3] == mark)
			return true;
	return false;
}

bool PlayField::hasVertical(PlayField::CellStatus mark, PlayField::CellStatus* fieldState)
{
	for (int i = 0; i < 3; i++)
		if (fieldState[0 + i] == mark && fieldState[3 + i] == mark && fieldState[6 + i] == mark)
			return true;
	return false;
}

bool PlayField::hasDiagonal(PlayField::CellStatus mark, PlayField::CellStatus* fieldState)
{
	if (fieldState[0] == mark && fieldState[4] == mark && fieldState[8] == mark ||
		fieldState[2] == mark && fieldState[4] == mark && fieldState[6] == mark)
		return true;
	return false;
}

bool PlayField::hasMoves()
{
	int cross = 0;
	int nought = 0;
	for (int i = 0; i < 9; i++)
	{
		if (fieldState[i] == csCross) cross++;
		if (fieldState[i] == csNought) nought++;
	}
	return abs(cross - nought) < 2;
}

PlayField::CellStatus PlayField::operator[](CellIdx cell)
{
	return fieldState[cell.GetCellID()];
}

PlayField PlayField::operator+(CellIdx cell)
{
	makeMove(cell);
	return *this;
}