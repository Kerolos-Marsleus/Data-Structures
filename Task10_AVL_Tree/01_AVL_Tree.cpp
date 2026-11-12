#include "01_AVL_Tree.hpp"
#include <algorithm>
#include <utility>
int AVL_Tree::getHeight(const Node* node){
            if(node == nullptr){
                return 0;
            }
            return node->height;
}

void AVL_Tree::updateHeight(Node* node){
    node->height = 1 + std::max(getHeight(node->left.get()), getHeight(node->right.get()));
}

int AVL_Tree::balanceFactor(const Node* node){
    if(node == nullptr) return 0;
    return (getHeight(node->left.get()) - getHeight(node->right.get()));
}

void AVL_Tree::rotateRight(std::unique_ptr<Node> &node){
    std::unique_ptr<AVL_Tree::Node> newRoot = std::move(node->left);
    node->left = std::move(newRoot->right);
    newRoot->right = std::move(node);
    node = std::move(newRoot);

    updateHeight(node->right.get());
    updateHeight(node.get());
}

void AVL_Tree::rotateLeft(std::unique_ptr<Node> &node){
    std::unique_ptr<AVL_Tree::Node> newRoot = std::move(node->right);
    node->right = std::move(newRoot->left);
    newRoot->left = std::move(node);
    node = std::move(newRoot);

    updateHeight(node->left.get());
    updateHeight(node.get());
}

void AVL_Tree::reBalance(std::unique_ptr<Node> &node){
    if(node.get() == nullptr)return;
    updateHeight(node.get());
    int loc_balanceFactorParent = balanceFactor(node.get());
    if(loc_balanceFactorParent > 1){
        int loc_balanceFactorChild = balanceFactor(node->left.get());
        if(loc_balanceFactorChild >= 0){
            rotateRight(node);
        }else{
            rotateLeft(node->left);
            rotateRight(node);
        }
    }else if(loc_balanceFactorParent < -1){
        int loc_balanceFactorChild = balanceFactor(node->right.get());
        if(loc_balanceFactorChild <= 0){
            rotateLeft(node);
        }else{
            rotateRight(node->right);
            rotateLeft(node);
        }
    }
}

bool AVL_Tree::insert_helper(std::unique_ptr<Node> & ptr, int value){
    if(ptr == nullptr){
        ptr = std::make_unique<Node>(value);
        return true;
    }else if(ptr->value == value){
        return false;
    }else if(value > ptr->value){
        bool ret = insert_helper(ptr->right,value);
        if(ret) reBalance(ptr);
        return ret;
    }else{
        bool ret =  insert_helper(ptr->left,value);
        if(ret) reBalance(ptr);
        return ret;
    }
}

bool AVL_Tree::insert(int value){
    return insert_helper(root,value);
}

void AVL_Tree::inorder_helper(const Node *ptr, std::vector<int> &vec)const{
    if(ptr == nullptr){
        return;
    }
    inorder_helper(ptr->left.get(), vec);
    vec.push_back(ptr->value);
    inorder_helper(ptr->right.get(), vec);
}


void AVL_Tree::preorder_helper(const Node *ptr, std::vector<int> &vec)const{
    if(ptr == nullptr){
        return;
    }
    vec.push_back(ptr->value);
    preorder_helper(ptr->left.get(), vec);
    preorder_helper(ptr->right.get(), vec);
}

void AVL_Tree::postorder_helper(const Node *ptr, std::vector<int> &vec)const{
    if(ptr == nullptr){
        return;
    }
    postorder_helper(ptr->left.get(), vec);
    postorder_helper(ptr->right.get(), vec);
    vec.push_back(ptr->value);
}

std::vector<int> AVL_Tree::inorder() const{
    std::vector<int> ans;
    inorder_helper(root.get(), ans);
    return ans;
}

std::vector<int> AVL_Tree::preorder() const{
    std::vector<int> ans;
    preorder_helper(root.get(), ans);
    return ans;
}
std::vector<int> AVL_Tree::postorder() const{
    std::vector<int> ans;
    postorder_helper(root.get(), ans);
    return ans;
}

bool AVL_Tree::contains(int val) const{
    const Node* cur = root.get();
    while(cur != nullptr){
        if(val > cur->value){
            cur = cur->right.get();
        }else if(val < cur->value){
            cur = cur->left.get();
        }else{
            return true;
        }
    }
    return false;
}


const AVL_Tree::Node* AVL_Tree::find_min(const Node *ptr)const{
    if(ptr == nullptr){
        return  nullptr;
    }
    const Node* cur = ptr;
    while(cur->left != nullptr){
        cur = cur->left.get();
    }
    return cur;
}

const AVL_Tree::Node* AVL_Tree::find_max(const Node *ptr)const{
    if(ptr == nullptr){
        return  nullptr;
    }
    const Node* cur = ptr;
    while(cur->right != nullptr){
        cur = cur->right.get();
    }
    return cur;
}

void AVL_Tree::clear() {
    root.reset();
}

bool AVL_Tree::isEmpty() const{
    return root == nullptr;
}

int AVL_Tree::height() const{
    return getHeight(root.get());
}

bool AVL_Tree::remove_helper(std::unique_ptr<Node> & ptr, int value){
    if(ptr == nullptr){
        return false;
    }
    if(value > ptr->value){
        bool ret = remove_helper(ptr->right, value);
        if(ret) reBalance(ptr);
        return ret;
    } 
    else if(value < ptr->value) {
        bool ret =  remove_helper(ptr->left, value);
        if(ret) reBalance(ptr);
        return ret;
    }
    // else you found the node

    // if leaf
    if(ptr->left == nullptr && ptr->right == nullptr){
        ptr = nullptr;
        return true;
    }

    // if it has only one
    if(ptr->left == nullptr){
        auto child = std::move(ptr->right);
        ptr = std::move(child);
        return true;
    }
    if(ptr->right == nullptr){
        auto child = std::move(ptr->left);
        ptr = std::move(child);
        return true;
    }

    // two children
    auto successor = find_min(ptr->right.get());
    ptr->value = successor->value;
    bool ret = remove_helper(ptr->right,ptr->value);
    if(ret) reBalance(ptr);
    return ret;
}

bool AVL_Tree::remove(int val){
    return remove_helper(root, val);
}