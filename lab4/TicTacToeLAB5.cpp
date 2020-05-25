
#include <iostream>
#include <clocale>
#include "PlayField.h"
#include "TreeNode.h"



using namespace std;



void buildSubTree(TreeNode &node, bool isRootNode, int *wins = nullptr, int *defeats = nullptr,

                  int *draws = nullptr) {

    auto emptyCells = node.value().getEmptyCells();

    for (auto emptyCell : emptyCells) {

        int firstMoveWins = 0;

        int firstMoveDefeats = 0;

        int firstMoveDraws = 0;

        auto newField = node.value().makeMove(emptyCell);

        auto nodeChild = TreeNode(newField);

        node.addChild(nodeChild);

        if (nodeChild.isTerminal()) {

            switch (nodeChild.value().checkFieldStatus()) {

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

            cout << "starting cell: " << emptyCell.getRow() << " row: " << emptyCell.getColumn()

                      << endl

                      << "crosses win: " << firstMoveWins << endl << "noughts win: " << firstMoveDefeats

                      << endl

                      << "draws: " << firstMoveDraws << endl;

            firstMoveWins = 0;

            firstMoveDefeats = 0;

            firstMoveDraws = 0;

        }

    }

}



int main() {

    PlayField startingField;

    TreeNode node0(startingField);

    buildSubTree(node0, true);

    return 0;

}