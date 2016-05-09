#ifndef TST_SET_H_INCLUDED
#define TST_SET_H_INCLUDED

#include <string>
#include <list>

#define MAX 256

template <typename T>
class tst_set
{
public:
    tst_set() : root(nullptr) {}

    ~tst_set()
    {
        delete_sub_tree(root);
    }

    void insert(std::string const &key, const T& value)
    {
        root = put(root, key, 0, value);
    }

    const T* valueOf(std::string const &key) const
    {
        Node *x = get(root, key, 0);
        return x ? x->value : nullptr;
    }

    std::list<T> find(std::string const &key) const
    {
        Node *x = get(root, key, 0);
        if (!x)
            return nullptr;
        traverseTST(x);
    }

    int height() const {
        return height(root);
    }

private:

    // Noeud du TST
    struct Node
    {
        Node *left;
        Node *middle;
        Node *right;
        int height;
        char key;
        const T *value;

        // Constructeur
        Node(char key_) : left(nullptr), middle(nullptr), right(nullptr), height(0), key(key_), value(nullptr) {}
    };

    // Racine
    Node *root;

    // Hauteur
    int height(Node *x) const
    {
        return x ? x->height : -1;
    }

    // Mise a jour de la hauteur
    void update_height(Node *x)
    {
        x->height = std::max(height(x->left), height(x->right)) + 1;
    }

    // Rotation a gauche
    Node *rotate_left(Node *x)
    {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        update_height(x);
        update_height(y);
        return y;
    }

    // Rotation a droite
    Node *rotate_right(Node *x)
    {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        update_height(x);
        update_height(y);
        return y;
    }

    // Balance
    int balance(Node *x) const
    {
        return x ? height(x->left) - height(x->right) : 0;
    }

    // Reequilibrage
    Node *restore_balance(Node *x)
    {
        if(balance(x) < -1)
        {
            if (balance(x->right) > 0)
                x->right = rotate_right(x->right);
            x = rotate_left(x);
        }
        else if(balance(x) > 1)
        {
            if (balance(x->left) < 0)
                x->left = rotate_left(x->left);
            x = rotate_right(x);
        }
        else
            update_height(x);
        return x;
    }

    // Suppression totale
    void delete_sub_tree(Node *x)
    {
        if(!x)
            return;
        delete_sub_tree(x->left);
        delete_sub_tree(x->middle);
        delete_sub_tree(x->right);
        delete x;
    }

    // Ajout
    Node *put(Node *x, std::string const &key, size_t index, const T& value)
    {
        char c = key[index];
        if(!x)
            x = new Node(c);
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

    // Acces
    Node *get(Node *x, std::string const &key, size_t index) const
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

    void traverseTSTUtil(struct Node* root, char* buffer, int depth)
    {
        if (root)
        {
            // First traverse the left subtree
            traverseTSTUtil(root->left, buffer, depth);

            // Store the character of this Node
            buffer[depth] = root->data;
            if (root->isEndOfString)
            {
                buffer[depth+1] = '\0';
                printf( "%s\n", buffer);
            }

            // Traverse the subtree using equal pointer (middle subtree)
            traverseTSTUtil(root->eq, buffer, depth + 1);

            // Finally Traverse the right subtree
            traverseTSTUtil(root->right, buffer, depth);
        }
    }

    // The main function to traverse a Ternary Search Tree.
    // It mainly uses traverseTSTUtil()
    void traverseTST(struct Node* root)
    {
        char buffer[MAX];
        traverseTSTUtil(root, buffer, 0);
    }
};

#endif // TST_SET_H_INCLUDED
