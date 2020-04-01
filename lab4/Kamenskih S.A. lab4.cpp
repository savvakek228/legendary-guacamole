#include "PlayField.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

int crossWin = 0;
int noughtWin = 0;
int drawCount = 0;

void drawStart()
{
	setlocale(LC_ALL, "Russian");
	cout << " Кресты ходят первые \n ID ячеек поля:" << endl;
	cout << " 0 | 1 | 2 \n 3 | 4 | 5 \n 6 | 7 | 8 \n" << endl;
	cout << "Задайте положение старта значением ячейки" << endl;
}

void printSquare(PlayField::CellStatus state) 
{
	if (state == PlayField::csCross) cout << "Х";
	if (state == PlayField::csNought) cout << "О";
	if (state == PlayField::csEmpty) cout << " ";
}

void drawField(PlayField field) 
{
	cout << " -------------" << endl;
	for (int line = 0; line <= 2; line++)
	{
		for (int column = 0; column <= 2; column++)
		{
			cout << " | ";
			int id = PlayField::CellIdx(line, column).GetCellID();
			printSquare(field.fieldState[id]);
		}
		cout << " | ";
		cout << "\n ------------- " << endl;
	}
	cout << endl;
}

void fieldWalk(TreeNode* node, PlayField field, PlayField::CellStatus mark);

bool CreateTree(PlayField field, TreeNode* node)
{
	if (node->isTerminal(*node))
	{
		PlayField field = node->value(*node);
		auto status = field.checkFieldStatus();
		if (status != PlayField::fsNormal)
		{
			switch (status)
			{
			case PlayField::fsCrossesWin:
				crossWin++;
				break;
			case PlayField::fsNoughtsWin:
				noughtWin++;
				break;
			case PlayField::fsDraw:
				drawCount++;
				break;
			}
			return true;
		}
	}
	if (node->GetLevel(*node) % 2 == 0) fieldWalk(node, field, PlayField::CellStatus::csCross);
	else fieldWalk(node, field, PlayField::CellStatus::csNought);
}

void fieldWalk(TreeNode* node, PlayField field, PlayField::CellStatus mark) 
{
	for (int i = 0; i < 9; i++)
	{
		PlayField field = node->value(*node);
		if (field.fieldState[i] == PlayField::csEmpty)
		{
			PlayField newField = field.makeMove(PlayField::CellIdx::GetCellIdx(i)); 
			TreeNode childNode = TreeNode(newField, node); 
			node->addChild(node, &childNode); 
			CreateTree(field, &childNode); 
		}

	}
}

int main()
{
	int id;
	PlayField field;
	drawStart();
	cout << "Ваш ход:" << endl;
	cin >> id;
	cout << "Идет симуляция, подождите..." << endl;
	field.fieldState[id] = PlayField::csCross;
	cout << "Создание нового поля..." << endl;
	drawField(field);
	cout << "Отрисовка дерева решений..." << endl;
	TreeNode* treeRoot = &TreeNode(field, nullptr);
	CreateTree(field, treeRoot); 
	cout << "Завершение симуляции..." << endl;
	cout << "Кресты выигрывают в " << crossWin << " случаях" <<endl;
	cout << "Выигрывает нолик в " << noughtWin << " случаях" << endl;
	cout << "Ничья в " << drawCount << " случаях" << endl;
}

