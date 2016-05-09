/*! \brief Function caller base implementation
 *
 * \file FunctionImpl.h
 * \author Patrick Champion
 * \date 27.04.2016
 */

#ifndef EGLI_DETAIL_FUNCTIONIMPL_H_INCLUDED
#define EGLI_DETAIL_FUNCTIONIMPL_H_INCLUDED

#include <vector>
#include <string>
#include <functional>

#include "../Type.h"
#include "../VariableTable.h"
#include "../Exception.h"
#include "EnumValue.h"

namespace egli
{
namespace detail
{
/*! \brief Base class for function wrapping
 */
class FunctionCallerImpl
{
public:

    // Quick writing
    using parameters_t = const std::vector<std::string>&;
    using table_t = VariableTable&;
    using name_t = VariableTable::name_t;

    /*! \brief Destructor
     */
    virtual ~FunctionCallerImpl()
    {}

    /*! \brief Get the return type
     *
     * \return the Type
     */
    virtual Type returnType() const = 0;

    /*! \brief Get a parameter type
     *
     * \param i - index of the parameter (begin at 0)
     * \return the Type
     *
     * \throw Exception if i >= arity()
     */
    virtual Type parameterType(size_t i) const = 0;

    /*! \brief Get the function arity
     *
     * \return The function arity
     */
    virtual size_t arity() const = 0;

    /*! \brief Check if the variables types matches the parameters types
     *
     * \param table - The VariableTable
     * \param params - The variables
     * \return true if the match is complete
     */
    virtual bool match(const table_t table, parameters_t params) const = 0;

    /*! \brief Execute the function
     *
     * \param table - The VariableTable
     * \param dst - The destination variable name (for the result)
     * \param params - The variables
     */
    virtual void execute(table_t table, name_t dst, parameters_t params)const = 0;
};

/* Helper for FunctionImpl */
/* ----------------------- */

// Fetcher removes the const and the reference from T for convenience
template<typename T>
struct Fetcher
{
    using cref = const T&;

    static cref get(const VariableTable &table, const std::string &name)
    {
        return table.get<T>(name);
    }
};

// Remove const
template<typename T>
struct Fetcher<const T> :
    Fetcher<T>
{};

// Remove reference
template<typename T>
struct Fetcher<T&> :
    Fetcher<T>
{};

/* FunctionImpl for 0 to 10 parameters */
/* ----------------------------------- */

// Function with 10 parameters (MAXIMUM)
template<typename R, typename P0 = void, typename P1 = void, typename P2 = void,
                     typename P3 = void, typename P4 = void, typename P5 = void,
                     typename P6 = void, typename P7 = void, typename P8 = void,
                     typename P9 = void>
class FunctionImpl :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2, P3, P4, P5, P6, P7, P8, P9)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            case 3: return EnumValue<P3>::value;
            case 4: return EnumValue<P4>::value;
            case 5: return EnumValue<P5>::value;
            case 6: return EnumValue<P6>::value;
            case 7: return EnumValue<P7>::value;
            case 8: return EnumValue<P8>::value;
            case 9: return EnumValue<P9>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 10;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2)
            && table.typeOf(params[3]) == parameterType(3)
            && table.typeOf(params[4]) == parameterType(4)
            && table.typeOf(params[5]) == parameterType(5)
            && table.typeOf(params[6]) == parameterType(6)
            && table.typeOf(params[7]) == parameterType(7)
            && table.typeOf(params[8]) == parameterType(8)
            && table.typeOf(params[9]) == parameterType(9);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        typename Fetcher<P3>::cref p3 = Fetcher<P3>::get(table, params[3]);
        typename Fetcher<P4>::cref p4 = Fetcher<P4>::get(table, params[4]);
        typename Fetcher<P5>::cref p5 = Fetcher<P5>::get(table, params[5]);
        typename Fetcher<P6>::cref p6 = Fetcher<P6>::get(table, params[6]);
        typename Fetcher<P7>::cref p7 = Fetcher<P7>::get(table, params[7]);
        typename Fetcher<P8>::cref p8 = Fetcher<P8>::get(table, params[8]);
        typename Fetcher<P9>::cref p9 = Fetcher<P9>::get(table, params[9]);
        table.set(dst, func(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9));
    }

private:

    function_t func;
};

// Function with 9 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5, typename P6, typename P7,
                     typename P8>
class FunctionImpl<R, P0, P1, P2, P3, P4, P5, P6, P7, P8, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2, P3, P4, P5, P6, P7, P8)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            case 3: return EnumValue<P3>::value;
            case 4: return EnumValue<P4>::value;
            case 5: return EnumValue<P5>::value;
            case 6: return EnumValue<P6>::value;
            case 7: return EnumValue<P7>::value;
            case 8: return EnumValue<P8>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 9;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2)
            && table.typeOf(params[3]) == parameterType(3)
            && table.typeOf(params[4]) == parameterType(4)
            && table.typeOf(params[5]) == parameterType(5)
            && table.typeOf(params[6]) == parameterType(6)
            && table.typeOf(params[7]) == parameterType(7)
            && table.typeOf(params[8]) == parameterType(8);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        typename Fetcher<P3>::cref p3 = Fetcher<P3>::get(table, params[3]);
        typename Fetcher<P4>::cref p4 = Fetcher<P4>::get(table, params[4]);
        typename Fetcher<P5>::cref p5 = Fetcher<P5>::get(table, params[5]);
        typename Fetcher<P6>::cref p6 = Fetcher<P6>::get(table, params[6]);
        typename Fetcher<P7>::cref p7 = Fetcher<P7>::get(table, params[7]);
        typename Fetcher<P8>::cref p8 = Fetcher<P8>::get(table, params[8]);
        table.set(dst, func(p0, p1, p2, p3, p4, p5, p6, p7, p8));
    }

private:

    function_t func;
};

// Function with 8 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5, typename P6, typename P7>
class FunctionImpl<R, P0, P1, P2, P3, P4, P5, P6, P7, void, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2, P3, P4, P5, P6, P7)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            case 3: return EnumValue<P3>::value;
            case 4: return EnumValue<P4>::value;
            case 5: return EnumValue<P5>::value;
            case 6: return EnumValue<P6>::value;
            case 7: return EnumValue<P7>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 8;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2)
            && table.typeOf(params[3]) == parameterType(3)
            && table.typeOf(params[4]) == parameterType(4)
            && table.typeOf(params[5]) == parameterType(5)
            && table.typeOf(params[6]) == parameterType(6)
            && table.typeOf(params[7]) == parameterType(7);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        typename Fetcher<P3>::cref p3 = Fetcher<P3>::get(table, params[3]);
        typename Fetcher<P4>::cref p4 = Fetcher<P4>::get(table, params[4]);
        typename Fetcher<P5>::cref p5 = Fetcher<P5>::get(table, params[5]);
        typename Fetcher<P6>::cref p6 = Fetcher<P6>::get(table, params[6]);
        typename Fetcher<P7>::cref p7 = Fetcher<P7>::get(table, params[7]);
        table.set(dst, func(p0, p1, p2, p3, p4, p5, p6, p7));
    }

private:

    function_t func;
};

// Function with 7 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5, typename P6>
class FunctionImpl<R, P0, P1, P2, P3, P4, P5, P6, void, void, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2, P3, P4, P5, P6)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            case 3: return EnumValue<P3>::value;
            case 4: return EnumValue<P4>::value;
            case 5: return EnumValue<P5>::value;
            case 6: return EnumValue<P6>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 7;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2)
            && table.typeOf(params[3]) == parameterType(3)
            && table.typeOf(params[4]) == parameterType(4)
            && table.typeOf(params[5]) == parameterType(5)
            && table.typeOf(params[6]) == parameterType(6);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        typename Fetcher<P3>::cref p3 = Fetcher<P3>::get(table, params[3]);
        typename Fetcher<P4>::cref p4 = Fetcher<P4>::get(table, params[4]);
        typename Fetcher<P5>::cref p5 = Fetcher<P5>::get(table, params[5]);
        typename Fetcher<P6>::cref p6 = Fetcher<P6>::get(table, params[6]);
        table.set(dst, func(p0, p1, p2, p3, p4, p5, p6));
    }

private:

    function_t func;
};

// Function with 6 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5>
class FunctionImpl<R, P0, P1, P2, P3, P4, P5, void, void, void, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2, P3, P4, P5)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            case 3: return EnumValue<P3>::value;
            case 4: return EnumValue<P4>::value;
            case 5: return EnumValue<P5>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 6;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2)
            && table.typeOf(params[3]) == parameterType(3)
            && table.typeOf(params[4]) == parameterType(4)
            && table.typeOf(params[5]) == parameterType(5);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        typename Fetcher<P3>::cref p3 = Fetcher<P3>::get(table, params[3]);
        typename Fetcher<P4>::cref p4 = Fetcher<P4>::get(table, params[4]);
        typename Fetcher<P5>::cref p5 = Fetcher<P5>::get(table, params[5]);
        table.set(dst, func(p0, p1, p2, p3, p4, p5));
    }

private:

    function_t func;
};

// Function with 5 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4>
class FunctionImpl<R, P0, P1, P2, P3, P4, void, void, void, void, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2, P3, P4)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            case 3: return EnumValue<P3>::value;
            case 4: return EnumValue<P4>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 5;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2)
            && table.typeOf(params[3]) == parameterType(3)
            && table.typeOf(params[4]) == parameterType(4);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        typename Fetcher<P3>::cref p3 = Fetcher<P3>::get(table, params[3]);
        typename Fetcher<P4>::cref p4 = Fetcher<P4>::get(table, params[4]);
        table.set(dst, func(p0, p1, p2, p3, p4));
    }

private:

    function_t func;
};

// Function with 4 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3>
class FunctionImpl<R, P0, P1, P2, P3, void, void, void, void, void, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2, P3)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            case 3: return EnumValue<P3>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 4;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2)
            && table.typeOf(params[3]) == parameterType(3);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        typename Fetcher<P3>::cref p3 = Fetcher<P3>::get(table, params[3]);
        table.set(dst, func(p0, p1, p2, p3));
    }

private:

    function_t func;
};

// Function with 3 parameters
template<typename R, typename P0, typename P1, typename P2>
class FunctionImpl<R, P0, P1, P2, void, void, void, void, void, void, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1, P2)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            case 2: return EnumValue<P2>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 3;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1)
            && table.typeOf(params[2]) == parameterType(2);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        typename Fetcher<P2>::cref p2 = Fetcher<P2>::get(table, params[2]);
        table.set(dst, func(p0, p1, p2));
    }

private:

    function_t func;
};

// Function with 2 parameters
template<typename R, typename P0, typename P1>
class FunctionImpl<R, P0, P1, void, void, void, void, void, void, void, void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0, P1)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            case 1: return EnumValue<P1>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 2;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0)
            && table.typeOf(params[1]) == parameterType(1);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        typename Fetcher<P1>::cref p1 = Fetcher<P1>::get(table, params[1]);
        table.set(dst, func(p0, p1));
    }

private:

    function_t func;
};

// Function with 1 parameter
template<typename R, typename P0>
class FunctionImpl<R, P0, void, void, void, void, void, void, void, void, void>:
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R(P0)>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        switch (i) {
            case 0: return EnumValue<P0>::value;
            default:
                throw Exception("out of range",
                                "egli::FunctionCaller::parameterType");
        }
    }

    virtual size_t arity() const
    {
        return 1;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity()
            && table.typeOf(params[0]) == parameterType(0);
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        typename Fetcher<P0>::cref p0 = Fetcher<P0>::get(table, params[0]);
        table.set(dst, func(p0));
    }

private:

    function_t func;
};

// Function with 0 parameter
template<typename R>
class FunctionImpl<R, void, void, void, void, void, void, void, void, void,
                      void> :
    public FunctionCallerImpl
{
public:

    using function_t = std::function<R()>;

    FunctionImpl(const function_t &func) :
        func(func)
    {}

    virtual ~FunctionImpl()
    {}

    virtual Type returnType() const
    {
        return EnumValue<R>::value;
    }

    virtual Type parameterType(size_t i) const
    {
        throw Exception("out of range", "egli::FunctionCaller::parameterType");
    }

    virtual size_t arity() const
    {
        return 0;
    }

    virtual bool match(const table_t table, parameters_t params) const
    {
        return params.size() == arity();
    }

    virtual void execute(table_t table, name_t dst, parameters_t params) const
    {
        table.set(dst, func());
    }

private:

    function_t func;
};

/* makeFunction() for 0 to 10 parameters */
/* ------------------------------------- */

// Function with 10 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5, typename P6, typename P7,
                     typename P8, typename P9>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2, P3, P4, P5, P6, P7,
                                              P8, P9))
{
    return new FunctionImpl<R, P0, P1, P2, P3, P4, P5, P6, P7, P8, P9>(func);
}

// Function with 9 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5, typename P6, typename P7,
                     typename P8>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2, P3, P4, P5, P6, P7,
                                              P8))
{
    return new FunctionImpl<R, P0, P1, P2, P3, P4, P5, P6, P7, P8>(func);
}

// Function with 8 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5, typename P6, typename P7>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2, P3, P4, P5, P6, P7))
{
    return new FunctionImpl<R, P0, P1, P2, P3, P4, P5, P6, P7>(func);
}

// Function with 7 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5, typename P6>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2, P3, P4, P5, P6))
{
    return new FunctionImpl<R, P0, P1, P2, P3, P4, P5, P6>(func);
}

// Function with 6 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4, typename P5>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2, P3, P4, P5))
{
    return new FunctionImpl<R, P0, P1, P2, P3, P4, P5>(func);
}

// Function with 5 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3,
                     typename P4>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2, P3, P4))
{
    return new FunctionImpl<R, P0, P1, P2, P3, P4>(func);
}

// Function with 4 parameters
template<typename R, typename P0, typename P1, typename P2, typename P3>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2, P3))
{
    return new FunctionImpl<R, P0, P1, P2, P3>(func);
}

// Function with 3 parameters
template<typename R, typename P0, typename P1, typename P2>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1, P2))
{
    return new FunctionImpl<R, P0, P1, P2>(func);
}

// Function with 2 parameters
template<typename R, typename P0, typename P1>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0, P1))
{
    return new FunctionImpl<R, P0, P1>(func);
}

// Function with 1 parameter
template<typename R, typename P0>
FunctionCallerImpl *makeFunctionImpl(R(*func)(P0))
{
    return new FunctionImpl<R, P0>(func);
}

// Function with 0 parameter
template<typename R>
FunctionCallerImpl *makeFunctionImpl(R(*func)())
{
    return new FunctionImpl<R>(func);
}
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_FUNCTIONIMPL_H_INCLUDED
