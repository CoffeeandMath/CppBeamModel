#include "Node.h"

Node::Node()
{
    X.setZero();

    Fnode.setZero();

    FreeNode = true;
    globalNodes.setZero();
}
void Node::setX(Eigen::Vector3d &Xset)
{
    X = Xset;
}
Eigen::Vector3d Node::getX()
{
    return X;
}

// Setting External force F
void Node::setFnode(Eigen::Vector3d F)
{
    Fnode = F;
}
Eigen::Vector3d Node::getFnode()
{
    return Fnode;
}

// Setting global node locations
void Node::setGlobalNodes(Eigen::Vector3i GN)
{
    globalNodes = GN;
}
Eigen::Vector3i Node::getGlobalNodes()
{
    return globalNodes;
}

// Setting FreevsFixedNodes
void Node::FreeNodeLoc(bool fn)
{
    FreeNode = fn;
}
