#pragma once
#include <iostream>
using namespace std;

namespace ariel{

    template<class T>
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        Node(T data): data(data), right(nullptr), left(nullptr), parent(nullptr){}
    };

    template<class T>
    class BinaryTree {

        private:
            Node<T>* root;

        public:
            BinaryTree(): root(nullptr){}
            BinaryTree& add_root(T data){ root = new Node(data); return *this;}
            BinaryTree& add_left(T parent, T lChild){return *this;}
            BinaryTree& add_right(T parent, T rChild){return *this;}
            friend ostream& operator<<(ostream& os,const BinaryTree<T>& bt){return os;}

            class postorder{
                private:
                    Node<T>* p_curr_node;

                public:
                    postorder(Node<T>* ptr = nullptr): p_curr_node(ptr){};

                    T& operator*() const {
                    return p_curr_node->data;
                    }

                    T* operator->() const {
                    return &(p_curr_node->data);
                    }

                    // ++i;
                    postorder& operator++() {
                        p_curr_node = p_curr_node->left;

                        /*****postorder algo for next*****/
                        
                        return *this;
		            }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    const postorder operator++(int) {
                        postorder tmp= *this;

                        /*****postorder algo for next*****/

                        p_curr_node= p_curr_node->left;
                        return tmp;
                    }

                    bool operator==(const postorder& rhs) const {
                    return p_curr_node == rhs.p_curr_node;
                    }

                    bool operator!=(const postorder& rhs) const {
                        return p_curr_node != rhs.p_curr_node;
                    }

                    friend ostream& operator<<(ostream& os,const postorder& n){return os;};

            };

            class inorder{
                private:
                    Node<T>* p_curr_node;

                public:
                    inorder(Node<T>* ptr = nullptr): p_curr_node(ptr){};

                    T& operator*() const {
                    return p_curr_node->data;
                    }

                    T* operator->() const {
                    return &(p_curr_node->data);
                    }

                    // ++i;
                    inorder& operator++() {
                        p_curr_node = p_curr_node->left;

                        /*****inorder algo for next*****/
                        
                        return *this;
		            }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    const inorder operator++(int) {
                        inorder tmp= *this;

                        /*****inorder algo for next*****/
                        
                        p_curr_node= p_curr_node->left;
                        return tmp;
                    }

                    bool operator==(const inorder& rhs) const {
                    return p_curr_node == rhs.p_curr_node;
                    }

                    bool operator!=(const inorder& rhs) const {
                        return p_curr_node != rhs.p_curr_node;
                    }
                    friend ostream& operator<<(ostream& os,const inorder& n){return os;};

            };
            class preorder{
                private:
                    Node<T>* p_curr_node;

                public:
                    preorder(Node<T>* ptr = nullptr): p_curr_node(ptr){};

                    T& operator*() const {
                    return p_curr_node->data;
                    }

                    T* operator->() const {
                    return &(p_curr_node->data);
                    }

                    // ++i;
                    preorder& operator++() {
                        p_curr_node = p_curr_node->left;

                        /*****preorder algo for next*****/
                        
                        return *this;
		            }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    const preorder operator++(int) {
                        preorder tmp= *this;

                        /*****preorder algo for next*****/
                        
                        p_curr_node= p_curr_node->left;
                        return tmp;
                    }

                    bool operator==(const preorder& rhs) const {
                    return p_curr_node == rhs.p_curr_node;
                    }

                    bool operator!=(const preorder& rhs) const {
                        return p_curr_node != rhs.p_curr_node;
                    }

                    friend ostream& operator<<(ostream& os,const preorder& n){return os;}
            };

            inorder begin(){
                return begin_inorder();
            };
            inorder end(){
                return end_inorder();
            };
            postorder begin_postorder(){
                return postorder(root);
            }
            postorder end_postorder(){
                return postorder();
            }
            inorder begin_inorder(){
                return inorder(root);
            }
            inorder end_inorder(){
                return inorder();
            }
            preorder begin_preorder(){
                return preorder(root);
            }
            preorder end_preorder(){
                return preorder();
            }
        
    };
}