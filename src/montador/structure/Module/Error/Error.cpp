//
// Created by Ricardo Santos on 14/07/21.
//

#include "Error.h"

Error::Error(const std::string &error, const std::string &errorType, int line) :
error(error), error_type(errorType), line(line) {}