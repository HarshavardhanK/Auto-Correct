//
//  BinaryTree.h
//  Algorithms
//
//  Created by Harshavardhan K K on 14/08/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#define POSTORDER 1
#define PREORDER 0

#include <exception>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct BinaryTreeNode {
    
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode<T>* parent;
    
    T data;
    
    BinaryTreeNode<T>(T data) {
        this->data = data;
        this->left = this->right = NULL;
        
    }
    
    BinaryTreeNode<T>() {
        this->left = this->right = NULL;
    }
    
};

template<typename T>

class BinaryTree {
    
public:
    
    BinaryTree<T>(T data) {
        root_node = new BinaryTreeNode<T>(data);
    }
    
    BinaryTree<T>() {
        root_node = NULL;
    }
    
    BinaryTreeNode<T>* get_root() {
        return root_node;
    }
    
    void preOrder(BinaryTreeNode<T>* node) {
        
        if (node == NULL) {
            return;
        }
        
        std::cout << node->data << " ";
        
        if(node->left != NULL) {
            preOrder(node->left);
        }
        
        
        if(node->right != NULL) {
            preOrder(node->right);
        }
        
        
    }
    
    void postOrder(BinaryTreeNode<T>* node) {
        
        if (node == NULL) {
            return;
        }
        
        if(node != NULL) {
            
            postOrder(node->left);
            postOrder(node->right);
            
            std::cout << node->data << " ";
            
        }
        
    }
    
    void traverse(int order) {
        
        if (order == POSTORDER) {
            postOrder(this->root_node);
            
        } else if(order == PREORDER) {
            preOrder(this->root_node);
        }
        
    }
    
    void insert(T data) {
        
        BinaryTreeNode<T>* childNode = new BinaryTreeNode<T>(data);
        BinaryTreeNode<T>* node = root_node;
        BinaryTreeNode<T>* auxiliaryNode = NULL;
        
        while (node != NULL) {
            auxiliaryNode = node;
            
            if(data < node->data) {
                node = node->left;
                
            } else {
                node = node->right;
                
            }
        }
        
        childNode->parent = auxiliaryNode;
        
        if(auxiliaryNode == NULL) {
            root_node = childNode;
            
        } else if (childNode->data < auxiliaryNode->data) {
            auxiliaryNode->left = childNode;
            
        } else {
            auxiliaryNode->right = childNode;
        }
    }
    
    void tree_delete(T key) {
        
        BinaryTreeNode<T>* node = search(root_node, key);
        
        if(node == NULL) {
            cout << "Key doenst exist\n";
            return;
        }
        
        if(node->left == NULL) {
            transplant(node, node->right);
            
        } else if (node->right == NULL) {
            transplant(node, node->left);
            
        } else {
            
            BinaryTreeNode<T>* child = tree_min(node->right);
            
            if(child->parent != node) {
                
                transplant(child, child->right);
                child->right = node->right;
                child->right->parent = child;
            }
        
            transplant(node, child);
            child->left = node->left;
            child->left->parent = child;
        }
        
        cout << "Succesfully deleted " << node->data << endl;
    }
    
    void successor(int key) {
        
        BinaryTreeNode<T> *node = search(root_node, key);
        
        if(node != NULL) {
            
            int key_node = node->data;

            BinaryTreeNode<T> *succ = successor(node);
            
            if(succ != NULL) {
                cout << "Successor of " << key_node << " is " << succ->data << endl;
 
            } else {
                cout << "Successor of " << key_node << " doesnt exist\n";
            }
            
        } else {
            cout << "Node with key "<< key << " Doesnt exist!\n";
        }
    }
    
    void lowest_common_ancestor(int value1, int value2) {
        
        BinaryTreeNode<T>* node = lowest_common_ancestor(root_node, value1, value2);
        
        if(node != NULL) {
            cout << "LCA of " << value1 << " and " << value2 << " is " << node->data << endl;
            
        } else {
            cout << "Doesnt exist\n";
        }
    }
    
    void search(T key) {
        BinaryTreeNode<T>* node = search(root_node, key);
        
        if(node != NULL) {
            cout << node->data << " exists\n";
            
        } else {
            cout << key << " doesnt exist\n";
        }
    }
    
    int height() {
        return height(root_node);
    }
    
    void print_helper() {
        print_tree(root_node, 0);
    }
    
    void minimum() {
        
        BinaryTreeNode<T>* child = tree_min(root_node);
        cout << child->data << endl;
        
    }
    
    bool iter_search(T value) {
        
        BinaryTreeNode<T> *node = root_node;
        bool found = false;
        
        while(node != NULL) {
            
            cout << "W ";
            
            if(value < node->data) {
                node = node->left;
                
            } else if(value > node->data){
                node = node->right;
                
            } else {
                found = true;
               // break;
            }
            
            
        }
        
        return found;
    }
    
private:
    
    BinaryTreeNode<T>* root_node;
    
    void print_helper(BinaryTreeNode<T>* node, int indent, int order);
    
    class BinaryTreeException: public std::exception {
    public:
        
        virtual const char* what() const throw() {
            return "404: No such data found\n";
            
        }
        
    } noData_excp;
    
    int height(BinaryTreeNode<T>* node) {
        
        if (node == NULL) {
            return 0;
        }
        
        int rightHeight = height(node->right);
        int leftHeight = height(node->left);
        
        if (rightHeight > leftHeight) {
            return rightHeight;
            
        } else {
            return leftHeight + 1;
        }
    }
    
    BinaryTreeNode<T>* tree_min(BinaryTreeNode<T> *node) {
        
        if(node->left == NULL)
            return node;
        
        return tree_min(node->left);
    }
    
    BinaryTreeNode<T>* tree_max(BinaryTreeNode<T> *node) {
        
        if(node->right == NULL) {
            return node;
        }
        
        return tree_max(node->right);
    }
    
    BinaryTreeNode<T>* successor(BinaryTreeNode<T> *node) {
        
        if(node->right != NULL) {
            return tree_min(node->right);
        }
        
        BinaryTreeNode<T>* y = node->parent;
        
        while(y != NULL && node == y->right) {
            node = y;
            y = y->parent;
        }
        
        return y;
    }
    
    BinaryTreeNode<T>* lowest_common_ancestor(BinaryTreeNode<T>* node, T V1, T V2) {
        
        if(root_node->data < V1 && root_node->data < V2) {
            lowest_common_ancestor(root_node->right, V1, V2);
            
        } else if(root_node->data > V1 && root_node->data > V2) {
            lowest_common_ancestor(root_node->left, V1, V2);
           
        }
        
        return node;
    }
    
    BinaryTreeNode<T>* search(BinaryTreeNode<T>* node, T key) {
        
        if(node == NULL || node->data == key) {
            return node;
        }
        
        if(key > node->data) {
            return search(node->right, key);
            
        } else {
            return search(node->left, key);
        }
    }
    
    void transplant(BinaryTreeNode<T>* node, BinaryTreeNode<T>* with_node) {
        
        if(node->parent == NULL)
            root_node = node;
        
        else if(node == node->parent->left)
            node->parent->left = with_node;
        else
            node->parent->right = with_node;
        
        if(with_node != NULL)
            with_node->parent = node->parent;
    }
    
    void print_tree(BinaryTreeNode<T> *node, int indent) {
        if (node == NULL) {
            return;
        }
        
        print_tree(node->right, indent + 1);
        int i;
        
        for(i = 0; i < indent; i++) {
            printf(" ");
        }
        
        std::cout << "[" << node->data << std::endl;
        
        print_tree(node->left, indent + 1);
    }
    
};

bool operator < (const string& str1, const string& str2) {
    
    if(str1.compare(str2) < 0)
        return true;
    
    return false;
}

bool operator > (const string& str1, const string& str2) {
    
    if(str1.compare(str2) > 0)
        return true;
    
    return false;
}

bool operator == (const string& str1, const string& str2) {
    
    if(str1.compare(str2) == 0)
        return true;
    
    return false;
}

// HackerRank Binary Tree question

//void preOrder(Node* node) {
//    
//    std::cout << node->data << " ";
//    
//    if(node->left != NULL) {
//        preOrder(node->left);
//    }
//    
//    if(node->right != NULL) {
//        preOrder(node->right);
//    }
//}

/*
 
 void postOrder(Node root) {
 
 if(root == null) {
 return;
 }
 
 if(root!=null) {
 
 postOrder(root.left);
 postOrder(root.right);
 System.out.print(root.data+" ");
 
 }
 
 }
 
 void inOrder(Node root) {
 
 if(root == null) {
 return;
 }
 
 if(root.left != null){
 inOrder(root.left);
 }
 
 System.out.print(root.data + " ");
 
 if(root.right != null){
 inOrder(root.right);
 }
 
 }
 
 // HEIGHT OF A BINARY TREE / DEPTH
 
 int height(Node node) {
 
 if(node == null) {
 return 0;
 }
 
 int rightDepth = height(node.right);
 int leftDepth = height(node.left);
 
 if(rightDepth > leftDepth) {
 return rightDepth;
 
 } else {
 return leftDepth + 1;
 }
 
 }
 
 TOP VIEW OF A BINARY TREE
 
 void top_view(Node root)
 {
 
 if(root != null) {
 
 top_view(root.left, true);
 
 System.out.print(root.data + " ");
 
 top_view(root.right, false);
 
 }
 
 }
 
 void top_view(Node node, boolean goLeft) {
 
 if(node != null) {
 if(goLeft) {
 top_view(node.left, goLeft);
 System.out.print(node.data + " ");
 } else {
 System.out.print(node.data + " ");
 top_view(node.right, goLeft);
 }
 }
 
 }
 
  Node lca(Node root,int v1,int v2) {
 //Decide if you have to call rekursively
 //Samller than both
 if(root.data < v1 && root.data < v2){
 return lca(root.right,v1,v2);
 }
 //Bigger than both
 if(root.data > v1 && root.data > v2){
 return lca(root.left,v1,v2);
 
 }
 
 //Else solution already found
 return root;
 }
 
 */


#endif /* BinaryTree_h */
