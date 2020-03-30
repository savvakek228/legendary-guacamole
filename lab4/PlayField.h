#pragma once
class PlayField
{
	enum CellStatus
	{
		csEmpty,
		csCross,
		csNought
	};
	enum FieldStatus
	{
		fsInvalid,
		fsCrossesWin,
		fsNoughtsWin,
		fsDraw
	};
	class CellIdx
	{
	private:
		int cell_X;
		int cell_Y;
	public:
		CellIdx(int X, int Y)
		{
			SetCellIdx(X,Y);
		}
		void SetCellIdx(int X, int Y) 
		{
			cell_X = X;
			cell_Y = Y;
		}
		int GetCellX() { return cell_X; }
		int GetCellY() { return cell_Y; }
	};

};


