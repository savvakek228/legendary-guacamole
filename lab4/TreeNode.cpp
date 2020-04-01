#include "TreeNode.h"
#include <cassert>

const PlayField& TreeNode::value(TreeNode node) 
{
	return node.field;
}

bool TreeNode::isTerminal(TreeNode node)
{
	return (childQty(node) == 0 || node.field.checkFieldStatus() != PlayField::fsNormal);
}

void TreeNode::addChild(TreeNode* node, TreeNode* child)
{
	assert(childQty(*node) != 0);
	child->nodeParent = node;
	TreeNode n = *node;
	n.childNodes.push_back(child);
}

TreeNode& TreeNode::operator[](int index)
{
	return *childNodes[index];
}

int TreeNode::childQty(TreeNode node) 
{
	return node.field.getEmptyCells().size();
}

int TreeNode::childCount(TreeNode node)
{
	return node.childNodes.size();
}