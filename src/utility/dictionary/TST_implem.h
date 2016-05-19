/*! \brief Tst implementation file. Is in '.h' for template reasons
 *
 * \file TST_implem.h
 * \author Christopher Browne
 * \date 29.04.2015
 */

#ifndef TST_IMPLEM_H_INCLUDED
#define TST_IMPLEM_H_INCLUDED

#include <cstring>
#include "TST.h"

using namespace std;

template <typename T>
Tst<T>::Tst() : root(nullptr)
{

}

template <typename T>
Tst<T>::~Tst()
{
    delete_sub_tree(root);
}

template <typename T>
void Tst<T>::insert(string const &key, const T& value)
{
    root = put(root, key, 0, value);
}

template <typename T>
void Tst<T>::remove(string const &key)
{
    Node<T> *x = get(root, key, 0);
    if(x != nullptr)
        x->value = nullptr;
}

template <typename T>
void Tst<T>::removeAll(string const &key)
{
    vector<pair<string, Node<T>*>> *nodes = traverseTST(key);

    pair<string, Node<T> *> tmp;
    if(nodes) {
        for(int i = 0; i < nodes->size(); ++i) {
            tmp = nodes->at(i);
            tmp.second->value = nullptr;
        }
    }

    delete nodes;
}

template <typename T>
const T *Tst<T>::valueOf(string const &key) const
{
    Node<T> *x = get(root, key, 0);
    return x ? x->value : nullptr;
}

template <typename T>
vector<pair<string, T>> *Tst<T>::findPairs(string const &key) const
{
    vector<pair<string, T>> *pairs = new vector<pair<string, T>>();
    vector<pair<string, Node<T>*>> *nodes = traverseTST(key);

    pair<string, Node<T> *> tmp;
    for(int i = 0; i < nodes->size(); ++i) {
        tmp = nodes->at(i);
        pairs->push_back(make_pair(tmp.first, *(tmp.second->value)));
    }

    delete nodes;

    return pairs;
}

template <typename T>
int Tst<T>::height(Node<T> *x) const
{
    return x ? x->height : -1;
}

template <typename T>
void Tst<T>::update_height(Node<T> *x)
{
    x->height = max(height(x->left), height(x->right)) + 1;
}

template <typename T>
Node<T> *Tst<T>::rotate_left(Node<T> *x)
{
    Node<T> *y = x->right;
    x->right = y->left;
    y->left = x;
    update_height(x);
    update_height(y);
    return y;
}

template <typename T>
Node<T> *Tst<T>::rotate_right(Node<T> *x)
{
    Node<T> *y = x->left;
    x->left = y->right;
    y->right = x;
    update_height(x);
    update_height(y);
    return y;
}

template <typename T>
int Tst<T>::balance(Node<T> *x) const
{
    return x ? height(x->left) - height(x->right) : 0;
}

template <typename T>
Node<T> *Tst<T>::restore_balance(Node<T> *x)
{
    if(balance(x) < -1) {
        if (balance(x->right) > 0)
            x->right = rotate_right(x->right);
        x = rotate_left(x);
    } else if(balance(x) > 1) {
        if (balance(x->left) < 0)
            x->left = rotate_left(x->left);
        x = rotate_right(x);
    } else {
        update_height(x);
    }
    return x;
}

template <typename T>
void Tst<T>::delete_sub_tree(Node<T> *x)
{
    if(!x)
        return;
    delete_sub_tree(x->left);
    delete_sub_tree(x->middle);
    delete_sub_tree(x->right);
    delete x;
}

template <typename T>
 Node<T> *Tst<T>::put(Node<T> *x, string const &key, size_t index, const T& value)
{
    char c = key[index];
    if(!x)
        x = new Node<T>(c);
    if(c < x->key)
        x->left = put(x->left, key, index, value);
    else if(x->key < c)
        x->right = put(x->right, key, index, value);
    else if(index < key.size() - 1)
        x->middle = put(x->middle, key, index + 1, value);
    else
        x->value = &value;
    return restore_balance(x);
}

template <typename T>
Node<T> *Tst<T>::get(Node<T> *x, string const &key, size_t index) const
{
    if(!x)
        return nullptr;
    char c = key[index];
    if(c < x->key)
        return get(x->left, key, index);
    else if(x->key < c)
        return get(x->right, key, index);
    else if(index < key.size() - 1)
        return get(x->middle, key, index + 1);
    else
        return x;
}

template <typename T>
void Tst<T>::traverseTSTUtil(Node<T> *root, char* buffer, int depth, vector<pair<string,Node<T>*>> *nodes) const
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth, nodes);

        // Store the character of this Node
        buffer[depth] = root->key;
        if (root->value)
        {
            buffer[depth+1] = '\0';
            nodes->push_back(make_pair(buffer,root));
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->middle, buffer, depth + 1, nodes);

        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth, nodes);
    }
}

template <typename T>
vector<pair<string, Node<T>*>> *Tst<T>::traverseTST(const string &key) const
{
    vector<pair<string, Node<T>*>> *nodes = new vector<pair<string, Node<T>*>>();
    char buffer[MAX];

    if(key.length() == 0){
        traverseTSTUtil(root, buffer, 0, nodes);
    } else {
        //if exact word exists
        Node<T> *startPoint = get(root, key, 0);
        if(startPoint) {
            if(startPoint->value)
                nodes->push_back(make_pair(key, startPoint));

            memcpy(buffer, key.c_str(), key.length());
            traverseTSTUtil(startPoint->middle, buffer, key.length(), nodes);
        }
    }

    return nodes;
}

#endif //TST_IMPLEM_H_INCLUDED
