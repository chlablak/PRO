/*! \brief Optional value class
 *
 * \file Optional.h
 * \author Patrick Champion
 * \date 25.04.2016
 */

#ifndef UTILITY_OPTIONAL_H_INCLUDED
#define UTILITY_OPTIONAL_H_INCLUDED

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

    /*! \brief Get the value contained
     *
     * \return A reference to the value contained
     *
     * \note Unexpected behavior if !hasValue()
     */
    value_type &value();

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

template<typename T>
Optional<T>::Optional() :
    valuePtr(nullptr)
{}

template<typename T>
Optional<T>::Optional(const Optional &o) :
    valuePtr(o.hasValue() ? new value_type(o.value()) : nullptr)
{}

template<typename T>
Optional<T>::Optional(Optional &&o) :
    valuePtr(std::move(o.valuePtr))
{}

template<typename T>
Optional<T>::Optional(const value_type &value) :
    valuePtr(new value_type(value))
{}

template<typename T>
Optional<T>::Optional(value_type &&value) :
    valuePtr(new value_type(std::move(value)))
{}

template<typename T>
Optional<T>::~Optional()
{
    delete valuePtr;
}

template<typename T>
Optional<T> &Optional<T>::operator=(const Optional &o)
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
Optional<T> &Optional<T>::operator=(Optional &&o)
{
    if (this != &o) {
        delete valuePtr;
        valuePtr = std::move(o.valuePtr);
    }
    return *this;
}

template<typename T>
Optional<T> &Optional<T>::operator=(const value_type &value)
{
    if (hasValue())
        *valuePtr = value;
    else
        valuePtr = new value_type(value);
    return *this;
}

template<typename T>
Optional<T> &Optional<T>::operator=(value_type &&value)
{
    if (hasValue())
        *valuePtr = std::move(value);
    else
        valuePtr = new value_type(std::move(value));
    return *this;
}

template<typename T>
typename Optional<T>::value_type &Optional<T>::value()
{
    return *valuePtr;
}

template<typename T>
const typename Optional<T>::value_type &Optional<T>::value() const
{
    return *valuePtr;
}

template<typename T>
const typename Optional<T>::value_type &
    Optional<T>::valueOr(const value_type &orValue) const
{
    return hasValue() ? value() : orValue;
}

template<typename T>
bool Optional<T>::hasValue() const
{
    return valuePtr != nullptr;
}

#endif // UTILITY_OPTIONAL_H_INCLUDED
