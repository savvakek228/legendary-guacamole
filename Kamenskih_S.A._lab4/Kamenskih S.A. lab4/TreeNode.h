#pragma once
#include "PlayField.h"
class TreeNode
{
public:
	TreeNode(PlayField newField, TreeNode* newNodeParent)
	{
		field = newField;
		nodeParent = newNodeParent;
	}
	const PlayField& value(TreeNode node);
	TreeNode& operator[](int index);
	bool isTerminal(TreeNode node);
	void addChild(TreeNode* node, TreeNode* child);
	int childCount(TreeNode node);
	int GetLevel(TreeNode node) { return childQty(node); };
private:
	int childQty(TreeNode node);
	std::vector<TreeNode*> childNodes;
	PlayField field;
	TreeNode* nodeParent = nullptr;
};

