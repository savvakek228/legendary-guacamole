
#include <iostream>
#include "PlayField.h"
#include "TreeNode.h"

using namespace std;

void buildSubTree(TreeNode *node, bool isRootNode, int *wins = nullptr, int *defeats = nullptr,
                  int *draws = nullptr) {
    auto emptyCells = node->value().getEmptyCells();
    for (auto emptyCell : emptyCells) {
        int firstMoveWins = 0;
        int firstMoveDefeats = 0;
        int firstMoveDraws = 0;
        auto newField = node->value().makeMove(emptyCell);
        auto nodeChild = new TreeNode(newField);
        node->addChild(reinterpret_cast<TreeNode &>(nodeChild));
        if (nodeChild->isTerminal()) {
            switch (nodeChild->value().checkFieldStatus()) {
                case PlayField::FieldStatus::fsCrossesWin:
                    ++(*wins);
                    break;
                case PlayField::FieldStatus::fsNoughtsWin:
                    ++(*defeats);
                    break;
                case PlayField::FieldStatus::fsDraw:
                    ++(*draws);
                    break;
                default:
                    break;
            }
        } else {
            if (isRootNode)
                buildSubTree(nodeChild, false, &firstMoveWins, &firstMoveDefeats, &firstMoveDraws);
            else
                buildSubTree(nodeChild, false, wins, defeats, draws);
        }
        if (isRootNode) {
            std::cout << "Starting with cell row: " << emptyCell.getRow() << " column: " << emptyCell.getColumn()
                      << endl
                      << "crosses win: " << firstMoveWins << endl << "crosses lose (noughts win): " << firstMoveDefeats
                      << endl
                      << "draws: " << firstMoveDraws << endl;
            firstMoveWins = 0;
            firstMoveDefeats = 0;
            firstMoveDraws = 0;
        }
    }
}

int main() {
    auto *node0 = new TreeNode(PlayField(std::vector<PlayField::CellStatus>(9, PlayField::CellStatus::csEmpty)), nullptr);
    buildSubTree(node0, true);
    return 0;
}

