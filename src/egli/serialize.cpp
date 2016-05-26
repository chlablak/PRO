/*! \brief Serialize EGLI data structure
 *
 * \file serialize.cpp
 * \author Patrick Champion
 * \date 26.05.2016
 */

#include "serialize.h"
#include "Exception.h"
#include "Interpreter.h"

std::string egli::serialize(const Data &data)
{
    std::string output;
    for (const std::string &name : data.variables().find(""))
        output.append(name + '=' + data.variables().toString(name) + ';');
    output.append(data.preprocessor().raw());
    return output;
}

void egli::deserialize(Data &data, const std::string &input)
{
    data.clear();
    Interpreter interpreter(&data);
    interpreter.writer() << input;
    while (interpreter.available())
        interpreter.next();
}
