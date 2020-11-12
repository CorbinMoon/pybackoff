#ifndef PYTHON_UTILS_H
#define PYTHON_UTILS_H


#include <iostream>
#include <boost/python/list.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/dict.hpp>
#include <boost/python.hpp>
#include "ngrams_proto.h"


namespace py = boost::python;


Trigram pytupleToTrigram(const py::tuple& t);

std::vector<Trigram> pytupleListToVector(const py::list& l);

std::map<uint64_t, float> pydictToCountsMap(const py::dict& d);

py:tuple trigramToPytuple(const Trigram& t);


#endif //PYTHON_UTILS_H