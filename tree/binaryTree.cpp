#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node( int value ) : data( value ), left( nullptr ), right( nullptr ) {}
};

class BinaryTree {
    Node *root;
    void insert( Node *&, int );
    void inOrderTraversal( Node * );
    void preOrderTraversal( Node * );
    void postOrderTraversal( Node * );

    public:
        BinaryTree() : root( nullptr ) {}

        void insert( int value ) {
            insert( root, value );
        }

        void inOrderTraversal() {
            std::cout << "In-Order Traversal: ";
            inOrderTraversal( root );
        }

        void preOrderTraversal() {
            std::cout << "\nPre-Order Traversal: ";
            preOrderTraversal( root );
        }

        void postOrderTraversal() {
            std::cout << "\nPost-Order Traversal: ";
            postOrderTraversal( root );
        }


};

void BinaryTree::insert( Node *&node, int value ) {
    if( node == nullptr ) {
        node = new Node( value );
    } else if( value < node -> data ) {
        insert( node -> left, value );
    } else {
        insert( node -> right, value );
    }
}

void BinaryTree::inOrderTraversal( Node *node ) {
    if( node != nullptr ) {
        inOrderTraversal( node -> left );
        std::cout << node -> data << "  ";
        inOrderTraversal( node -> right );
    }
}

void BinaryTree::preOrderTraversal( Node *node ) {
    if( node != nullptr ) {
        std::cout << node -> data << "  ";
        preOrderTraversal( node -> left );
        preOrderTraversal( node -> right );
    }
}

void BinaryTree::postOrderTraversal( Node *node ) {
    if( node != nullptr ) {
        preOrderTraversal( node -> left );
        preOrderTraversal( node -> right );
        std::cout << node -> data << "  ";
    }
}
int main() {
    BinaryTree tree;
    
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();

    return 0;
}