/*! \brief Heterogenous dynamic array class
 *
 * \file Array.h
 * \author Patrick Champion
 * \date 26.04.2016
 */

#ifndef EGLI_ARRAY_H_INCLUDED
#define EGLI_ARRAY_H_INCLUDED

#include <vector>

#include "Exception.h"
#include "detail/EnumValue.h"

namespace egli
{
/*! \brief Heterogenous dynamic array
 */
class Array
{
public:

    /*! \brief Constructor
     */
    Array();

    /*! \brief Copy constructor
     *
     * \param a - The array to copy
     */
    Array(const Array &a);

    /*! \brief Constructor
     *
     * \param v - A vector to copy
     */
    template<typename T>
    Array(const std::vector<T> &v);

    /*! \brief Destructor
     */
    ~Array();

    /*! \brief Copy assignement
     *
     * \param a - The other array to copy
     * \return *this
     */
    Array &operator=(const Array &a);

    /*! \brief Get the array size
     *
     * \return The array size
     */
    size_t size() const;

    /*! \brief Add a value at the end of the array
     *
     * \param value - the new value
     */
    template<typename T>
    void add(const T &value);

    /*! \brief Get the Type at index i
     *
     * \param i - index
     * \return The Type at index i
     *
     * \throw Exception if i >= size()
     */
    Type typeOf(size_t i) const;

    /*! \brief Get the value at index i
     *
     * \param i - index
     * \return A constant reference to the value
     *
     * \throw Exception if typeOf(i) != T
     */
    template<typename T>
    const T &get(size_t i) const;

    /*! \brief Get a std::vector from the Array
     *
     * \return The resulting vector
     *
     * \throw Exception if the cast is not possible
     */
    template<typename T>
    std::vector<T> toVector() const;

private:

    // Associate a void* with a Type
    struct Element
    {
        Type type;
        void *ptr;
    };

    // data members
    std::vector<Element> elements;
};
} // namespace egli

template<typename T>
egli::Array::Array(const std::vector<T> &v) :
    elements()
{
    for (const T &val : v)
        add(val);
}

template<typename T>
void egli::Array::add(const T &value)
{
    elements.push_back({
        detail::EnumValue<T>::value,
        static_cast<void*>(new T(value))});
}

template<typename T>
const T &egli::Array::get(size_t i) const
{
    if (typeOf(i) != detail::EnumValue<T>::value) // do the index check
        throw Exception("bad type cast", "egli::Array::get<T>");

    return *static_cast<T*>(elements[i].ptr);
}

template<typename T>
std::vector<T> egli::Array::toVector() const
{
    std::vector<T> r;
    for (const Element &e : elements) {
        if (e.type != detail::EnumValue<T>::value)
            throw Exception("bad type cast", "egli::Array::toVector<T>");
        r.push_back(*static_cast<T*>(e.ptr));
    }
    return r;
}

#endif // EGLI_ARRAY_H_INCLUDED
