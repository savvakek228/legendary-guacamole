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

PlayField &TreeNode::value() const {
    return currentField;
}
