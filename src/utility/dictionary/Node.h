/*! \brief Node element for dictionary Tst
 *
 * \file Node.h
 * \author Christopher Browne
 * \date 29.04.2016
 */

template <typename T>
class Node
{
public:
    Node *left;
    Node *middle;
    Node *right;
    int height;
    char key;
    const T *value;

    Node(char key_) : left(nullptr), middle(nullptr), right(nullptr), height(0), key(key_), value(nullptr) {}
};
