#pragma once



#include <vector>



class PlayField {

public:

    class CellPos {

    public:

        explicit CellPos(int cellNum);

        CellPos(int row, int column);



        int getRow() const;



        void setRow(int value);



        int getColumn() const;



        void setColumn(int value);



        explicit operator int() const;

    private:

        int _row;

        int _column;

    };



    enum class CellStatus {

        csEmpty, csCross, csNought

    };



    enum class FieldStatus {

        fsInvalid, fsNormal, fsCrossesWin, fsNoughtsWin, fsDraw

    };



    CellStatus operator[](const CellPos &cellPos) const;



    std::vector<CellPos> getEmptyCells() const;



    FieldStatus checkFieldStatus() const;



    PlayField makeMove(const CellPos &cellPos) const;



private:
    static constexpr int fieldSize = 3;
    std::vector<CellStatus> _field = std::vector<CellStatus>(9, PlayField::CellStatus::csEmpty);

    bool hasWin(CellStatus player,bool row = false) const;

    bool checkWinStatus(CellStatus player) const;

    int countCells(CellStatus cellStatus) const;

    PlayField operator+(const CellPos &cellPos) const;
};

