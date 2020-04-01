#pragma once
#include <cassert>
#include <vector>
class PlayField
{
public:
	enum CellStatus
	{
		csEmpty,
		csCross,
		csNought
	};
	enum FieldStatus
	{
		fsInvalid,
		fsNormal,
		fsCrossesWin,
		fsNoughtsWin,
		fsDraw
	};
	class CellIdx
	{
	public:
		static CellIdx GetCellIdx(int id)
		{
			assert(id >= 0 || id < 9);
			int row = 0;
			int column = 0;
			row = id / 3;
			column = id % 3;
			return CellIdx(row, column);
		}
		void SetCellIdx(int X, int Y,int ID)
		{
			cell_X = X;
			cell_Y = Y;
			cell_ID = ID;
		}
		CellIdx(int row, int column)
		{
			assert(row > 0 || column > 0 || row <= 2 || column <= 2);
			cell_X = row;
			cell_Y = column;
			cell_ID = cell_X * 3 + cell_Y;
		}
		const int GetCellX() { return cell_X; }
		const int GetCellY() { return cell_Y; }
		const int GetCellID() { return cell_ID; }
	private:
		int cell_X;
		int cell_Y;
		int cell_ID;
	};

	CellStatus fieldState[9]{ csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty };
	std::vector<CellIdx*> getEmptyCells();
	PlayField makeMove(CellIdx square);
	FieldStatus checkFieldStatus()
	{
		if (checkWin(csCross, fieldState)) return fsCrossesWin;
		if (checkWin(csNought, fieldState)) return fsNoughtsWin;
		auto emptyCells = getEmptyCells();
		if (emptyCells.empty()) return fsDraw;
		if (hasMoves()) return fsNormal;
		else return fsInvalid;
	}

private:
	CellStatus mark = csCross;
	CellStatus operator[](CellIdx cell);
	PlayField operator+(CellIdx cell);
	bool hasMoves();
	bool checkWin(PlayField::CellStatus mark, PlayField::CellStatus* fieldState);
	bool hasHorizontal(PlayField::CellStatus mark, PlayField::CellStatus* fieldState);
	bool hasVertical(PlayField::CellStatus mark, PlayField::CellStatus* fieldState);
	bool hasDiagonal(PlayField::CellStatus mark, PlayField::CellStatus* fieldState);
};


