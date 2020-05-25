#include "TreeNode.h"
#include <cassert>

/*
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
}*/
#include <cassert>

#include "TreeNode.h"



TreeNode::TreeNode(PlayField &currentField) : currentField(currentField) { }



bool TreeNode::isTerminal() const {

    PlayField::FieldStatus fieldStatus = currentField.checkFieldStatus();

    return fieldStatus != PlayField::FieldStatus::fsNormal;

}



int TreeNode::childQty() const {

    return currentField.getEmptyCells().size();

}



void TreeNode::addChild(TreeNode &childNode) {

    assert(childNodes.size() + 1 <= childQty());

    childNode.ancestorNode = this;

    childNodes.emplace_back(childNode);

}



TreeNode &TreeNode::operator[](int childIndex) const {

    assert(childIndex < childNodes.size());

    return childNodes[childIndex];

}



int TreeNode::childCount() const {

    return childNodes.size();

}



const PlayField TreeNode::value() const {

    return currentField;

}