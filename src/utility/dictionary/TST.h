/*! \brief Tst header for dictionary
 *
 * \file TST.h
 * \author Christopher Browne
 * \date 29.04.2016
 */

#ifndef TST_SET_H_INCLUDED
#define TST_SET_H_INCLUDED

#include <string>
#include <list>
#include <vector>

#include "Node.h"

#define MAX 256

using namespace std;

template <typename T>
class Tst
{
public:
    Tst();
    ~Tst();

    /*! \brief insert a key/value pair
     */
    void insert(string const &key, const T& value);

    /*! \brief remove one key/value pair
     * \param key - to be removed
     * \note if key does not exist, nothing happens
     */
    void remove(string const &key);

    /*! \brief remove all keys starting with ...
     * \param key - start of all keys to be removed
     * \note if key does not exist, nothing happens
     */
    void removeAll(string const & key);

    /*! \brief gets the value of a key
     * \param key - for value retrieval
     * \return pointer to the value
     * \note will return nullptr if key does not exist
     */
    const T *valueOf(string const &key) const;

    /*! \brief finds all pairs starting with a certain key
     * \param key - of the pairs to be returned
     * \return vector of key/value pairs
     */
    vector<pair<string, T>> *findPairs(string const &key) const;

private:
    Node<T> *root;

    int height(Node<T> *x) const;
    void update_height(Node<T> *x);

    /*! \brief balances the TST after insertion
     */
    int balance(Node<T> *x) const;
    Node<T> *restore_balance(Node<T> *x);
    Node<T> *rotate_left(Node<T> *x);
    Node<T> *rotate_right(Node<T> *x);

    void delete_sub_tree(Node<T> *x);

    Node<T> *put(Node<T> *x, string const &key, size_t index, const T& value);
    Node<T> *get(Node<T> *x, string const &key, size_t index) const;

    /*! \brief traverses the TST from a point and adds each element
     *         to a key/Node pair
     */
    void traverseTSTUtil(Node<T> *root, char* buffer, int depth, vector<pair<string,Node<T>*>> *nodes) const;

    /*! \brief Returns a key/Node pair collection of all the Node from a certain key
     * \param key - start key for the return collection
     * \note /!\\ you should call delete on the vector after usage, since this method
     *       creates a new one at each call
     */
    vector<pair<string, Node<T>*>> *traverseTST(const string &key = "") const;
};

#endif // TST_SET_H_INCLUDED
