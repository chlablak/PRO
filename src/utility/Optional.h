/*! \brief Optional value class
 *
 * \file Optional.h
 * \author Patrick Champion
 * \date 25.04.2016
 */

#ifndef UTILITY_OPTIONAL_H_INCLUDED
#define UTILITY_OPTIONAL_H_INCLUDED

#include <utility>

namespace utility
{
namespace detail
{
// For optional with no value
struct OptionalNone
{};

// Constant in header trick
template<typename T>
struct OptionalNoneInstance
{
    static const T instance;
};

template<typename T>
const T OptionalNoneInstance<T>::instance = T();
}

// Thanks boost.optional
namespace
{
/*! \brief For Optional with no value
 *
 * \note Exemple: Optional<int> v = none;
 */
const detail::OptionalNone &none
    = detail::OptionalNoneInstance<detail::OptionalNone>::instance;
}

/*! \brief Class for optional value
 */
template<typename T>
class Optional
{
public:

    /*! \brief Type of the contained value
     */
    using value_type = T;

    /*! \brief Constructor
     */
    Optional();

    /*! \brief Copy constructor
     *
     * \param o
     */
    Optional(const Optional &o);

    /*! \brief Move constructor
     *
     * \param o
     */
    Optional(Optional &&o);

    /*! \brief Value constructor
     *
     * \param value
     */
    Optional(const value_type &value);

    /*! \brief Move value constructor
     *
     * \param value
     */
    Optional(value_type &&value);

    /*! \brief none constructor
     *
     * \param not used
     *
     * \see utility::none
     */
    Optional(detail::OptionalNone);

    /*! \brief Destructor
     */
    ~Optional();

    /*! \brief Copy assignement
     *
     * \param o
     * \return *this
     */
    Optional &operator=(const Optional &o);

    /*! \brief Move assignement
     *
     * \param o
     * \return *this
     */
    Optional &operator=(Optional &&o);

    /*! \brief Value assignement
     *
     * \param value
     * \return *this
     */
    Optional &operator=(const value_type &value);

    /*! \brief Move value assignement
     *
     * \param value
     * \return *this
     */
    Optional &operator=(value_type &&value);

    /*! \brief none assignement
     *
     * \param not used
     * \return *this
     *
     * \see utility::none
     */
    Optional &operator=(detail::OptionalNone);

    /*! \brief Get the value contained
     *
     * \return A constant reference to the value contained
     *
     * \note Unexpected behavior if !hasValue()
     */
    const value_type &value() const;

    /*! \brief Get the value contained, or a default value instead
     *
     * \param orValue - The default value
     * \return A constant reference to the value
     */
    const value_type &valueOr(const value_type &orValue) const;

    /*! \brief Does the Optional have a value ?
     *
     * \return true if there is a contained value
     */
    bool hasValue() const;

private:

    // data member
    value_type *valuePtr;
};
} // namespace utility

template<typename T>
utility::Optional<T>::Optional() :
    valuePtr(nullptr)
{}

template<typename T>
utility::Optional<T>::Optional(const Optional &o) :
    valuePtr(o.hasValue() ? new value_type(o.value()) : nullptr)
{}

template<typename T>
utility::Optional<T>::Optional(Optional &&o) :
    valuePtr(std::move(o.valuePtr))
{}

template<typename T>
utility::Optional<T>::Optional(const value_type &value) :
    valuePtr(new value_type(value))
{}

template<typename T>
utility::Optional<T>::Optional(value_type &&value) :
    valuePtr(new value_type(std::move(value)))
{}

template<typename T>
utility::Optional<T>::Optional(detail::OptionalNone) :
    valuePtr(nullptr)
{}

template<typename T>
utility::Optional<T>::~Optional()
{
    delete valuePtr;
}

template<typename T>
utility::Optional<T> &utility::Optional<T>::operator=(const Optional &o)
{
    if (this != &o) {
        delete valuePtr;
        valuePtr = nullptr;
        if (o.hasValue())
            valuePtr = new value_type(o.value());
    }
    return *this;
}

template<typename T>
utility::Optional<T> &utility::Optional<T>::operator=(Optional &&o)
{
    if (this != &o) {
        delete valuePtr;
        valuePtr = std::move(o.valuePtr);
    }
    return *this;
}

template<typename T>
utility::Optional<T> &utility::Optional<T>::operator=(const value_type &value)
{
    if (hasValue())
        *valuePtr = value;
    else
        valuePtr = new value_type(value);
    return *this;
}

template<typename T>
utility::Optional<T> &utility::Optional<T>::operator=(value_type &&value)
{
    if (hasValue())
        *valuePtr = std::move(value);
    else
        valuePtr = new value_type(std::move(value));
    return *this;
}

template<typename T>
utility::Optional<T> &
    utility::Optional<T>::operator=(detail::OptionalNone)
{
    if (hasValue()) {
        delete valuePtr;
        valuePtr = nullptr;
    }
    return *this;
}

template<typename T>
const typename utility::Optional<T>::value_type &
    utility::Optional<T>::value() const
{
    return *valuePtr;
}

template<typename T>
const typename utility::Optional<T>::value_type &
    utility::Optional<T>::valueOr(const value_type &orValue) const
{
    return hasValue() ? value() : orValue;
}

template<typename T>
bool utility::Optional<T>::hasValue() const
{
    return valuePtr != nullptr;
}

#endif // UTILITY_OPTIONAL_H_INCLUDED
