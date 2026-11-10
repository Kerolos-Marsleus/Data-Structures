#include "01_Binary_Search_tree.hpp"
#include <stack>
bool BST::isEmpty() const{
    return root == nullptr;
}

bool BST::insert_helper(std::unique_ptr<Node> & ptr, int value){
    if(ptr == nullptr){
        ptr = std::make_unique<Node>(value);
        return true;
    }else if(ptr->value == value){
        return false;
    }else if(value > ptr->value){
        return insert_helper(ptr->right,value);
    }else{
        return insert_helper(ptr->left,value);
    }
}

bool BST::insert(int val){
    return insert_helper(root, val);
}

void BST::inorder_helper(const Node *ptr, std::vector<int> &vec)const{
    if(ptr == nullptr){
        return;
    }
    inorder_helper(ptr->left.get(), vec);
    vec.push_back(ptr->value);
    inorder_helper(ptr->right.get(), vec);
}


void BST::preorder_helper(const Node *ptr, std::vector<int> &vec)const{
    if(ptr == nullptr){
        return;
    }
    vec.push_back(ptr->value);
    preorder_helper(ptr->left.get(), vec);
    preorder_helper(ptr->right.get(), vec);
}

void BST::postorder_helper(const Node *ptr, std::vector<int> &vec)const{
    if(ptr == nullptr){
        return;
    }
    postorder_helper(ptr->left.get(), vec);
    postorder_helper(ptr->right.get(), vec);
    vec.push_back(ptr->value);
}

std::vector<int> BST::inorder() const{
    std::vector<int> ans;
    inorder_helper(root.get(), ans);
    return ans;
}

std::vector<int> BST::preorder() const{
    std::vector<int> ans;
    preorder_helper(root.get(), ans);
    return ans;
}
std::vector<int> BST::postorder() const{
    std::vector<int> ans;
    postorder_helper(root.get(), ans);
    return ans;
}

bool BST::contains(int val) const{
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


const BST::Node* BST::find_min(const Node *ptr)const{
    if(ptr == nullptr){
        return  nullptr;
    }
    const Node* cur = ptr;
    while(cur->left != nullptr){
        cur = cur->left.get();
    }
    return cur;
}

const BST::Node* BST::find_max(const Node *ptr)const{
    if(ptr == nullptr){
        return  nullptr;
    }
    const Node* cur = ptr;
    while(cur->right != nullptr){
        cur = cur->right.get();
    }
    return cur;
}
bool BST::remove_helper(std::unique_ptr<Node> & ptr, int value){
    if(ptr == nullptr){
        return false;
    }
    if(value > ptr->value) return remove_helper(ptr->right, value);
    else if(value < ptr->value) return remove_helper(ptr->left, value);
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
    return remove_helper(ptr->right,ptr->value);
}

bool BST::remove(int val){
    return remove_helper(root, val);
}
void BST::clear() {
    root.reset();
}

void BST::buildFromPreorder(const std::vector<int>& values){
    clear();
    if(values.empty()){
        return;
    }
    root = std::make_unique<Node>(values[0]);
    std::stack<Node*> st;
    st.push(root.get());
    for(std::size_t i  = 1; i < values.size(); i++){
        if(values[i] < st.top()->value){
            st.top()->left = std::make_unique<Node>(values[i]);
            st.push(st.top()->left.get());
        }else{
            Node* parent = nullptr;
            while(!st.empty() && st.top()->value < values[i]){
                parent = st.top();
                st.pop();
            }
            parent->right = std::make_unique<Node>(values[i]);
            st.push(parent->right.get());
        }
    }
}


