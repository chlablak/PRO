/*! \brief Serialize EGLI data structure
 *
 * \file serialize.h
 * \author Patrick Champion
 * \date 26.05.2016
 */

#ifndef EGLI_SERIALIZE_H_INCLUDED
#define EGLI_SERIALIZE_H_INCLUDED

#include <string>

#include "Data.h"
#include "Interpreter.h"

namespace egli
{
/*! \brief Serialize the Data structure
 *
 * \param data - The Data structure to serialize
 * \return The serialized output
 */
std::string serialize(const Data &data);

/*! \brief Deserialize an input to a Data structure
 *
 * \param data - The destination data structure
 * \param input - The serialized input
 *
 * \pre Call data.clear()
 * \throw Exception if an error occurs
 */
void deserialize(Data &data, const std::string &input);

/*! \brief Deserialize an input to a Data structure
 *
 * \param interpreter - The interpreter to use
 * \param data - The destination data structure
 * \param input - The serialized input
 *
 * \pre Call data.clear()
 * \throw Exception if an error occurs
 */
void deserialize(Interpreter &interpreter, Data &data, const std::string &input);
}

#endif // EGLI_SERIALIZE_H_INCLUDED
