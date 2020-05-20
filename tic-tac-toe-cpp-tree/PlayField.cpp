#include "PlayField.h"
#include <cassert>

PlayField::CellPos::CellPos(int cellNum) {
    _row = cellNum / fieldSize;
    _column = cellNum % fieldSize;
}

int PlayField::CellPos::getRow() const {
    return _row;
}

void PlayField::CellPos::setRow(int value) {
    assert(value >= 0 && value <= fieldSize - 1);
    _row = value;
}

int PlayField::CellPos::getColumn() const {
    return _column;
}

void PlayField::CellPos::setColumn(int value) {
    assert(value >= 0 && value <= fieldSize - 1);
    _column = value;
}

PlayField::CellPos::operator int() const {
    return _column + _row * fieldSize;
}

PlayField::CellPos::CellPos(int row, int column) : _row(row), _column(column) { }

PlayField::PlayField(std::vector<CellStatus>& field) : _field(field) { }

PlayField::CellStatus PlayField::operator[](const CellPos &cellPos) const {
    return _field[int(cellPos)];
}

std::vector<PlayField::CellPos> PlayField::getEmptyCells() const {
    std::vector<CellPos> result;
    for (int i = 0; i < _field.size(); ++i)
        if (_field[i] == CellStatus::csEmpty)
            result.emplace_back(CellPos(i));
    return result;
}

//bool PlayField::hasWinInLine(PlayField::CellStatus player, bool row) const {
//    int multiplier = row ? 1 : 3;
//    for (int i = 0; i < 3; ++i) {
//        if (_field[i] == player &&
//            _field[i + 1 * multiplier] == player &&
//            _field[i + 2 * multiplier] == player)
//            return true;
//    }
//    return false;
//}

//bool PlayField::hasWinInDiagonal(PlayField::CellStatus player) const {
//    return _field[0] == player && _field[4] == player && _field[8] == player ||
//           _field[2] == player && _field[4] == player && _field[6] == player;
//}

bool PlayField::checkWinStatus(PlayField::CellStatus player,bool row) const {
    return hasWin(player, row);
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    if (checkWinStatus(CellStatus::csCross))
        return FieldStatus::fsCrossesWin;
    if (checkWinStatus(CellStatus::csNought))
        return FieldStatus::fsNoughtsWin;
    int crosses = countCells(CellStatus::csCross);
    int noughts = countCells(CellStatus::csNought);
    if (!(crosses == noughts || crosses == noughts + 1))
        return FieldStatus::fsInvalid;
    if (getEmptyCells().empty())
        return FieldStatus::fsDraw;
    return FieldStatus::fsNormal;
}

PlayField PlayField::operator+(const CellPos &cellPos) const {
    PlayField newField(_field);
    newField._field[int(cellPos)] =
            countCells(CellStatus::csCross) - 1 == countCells(CellStatus::csNought)
            ? CellStatus::csCross
            : CellStatus::csNought;
    return newField;
}

PlayField PlayField::makeMove(const CellPos &cellPos) const {
    FieldStatus fieldStatus = checkFieldStatus();
    assert((*this)[cellPos] == CellStatus::csEmpty ||
           fieldStatus != FieldStatus::fsCrossesWin ||
           fieldStatus != FieldStatus::fsNoughtsWin ||
           fieldStatus != FieldStatus::fsNormal);
    return *this + cellPos;
}

int PlayField::countCells(PlayField::CellStatus cellStatus) const {
    int result = 0;
    for (auto i : _field) {
        if (i == cellStatus)
            ++result;
    }
    return result;
}

bool PlayField::hasWin(PlayField::CellStatus player, bool row) const
{
    bool CheckWinInDiagonal = _field[0] == player && _field[4] == player && _field[8] == player ||
                              _field[2] == player && _field[4] == player && _field[6] == player;
    int multiplier = row ? 1 : 3;
    for (int i = 0; i < 3; ++i) {
        if (_field[i] == player &&
            _field[i + 1 * multiplier] == player &&
            _field[i + 2 * multiplier] == player)
            return true;
    }
    return CheckWinInDiagonal;
}
