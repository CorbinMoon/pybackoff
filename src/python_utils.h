#ifndef PYTHON_UTILS_H
#define PYTHON_UTILS_H


#include <iostream>
#include <boost/python/list.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/dict.hpp>
#include <boost/python.hpp>
#include "ngrams_proto.h"


namespace py = boost::python;


template<class T>
T pytupleToTrigram(const py::tuple& t);


template<class T>
py::tuple trigramToPytuple(const T& t);


template<class T>
std::vector<T> pytupleListToVector(const py::list& l);


template<class K, class V>
std::map<K, V> pydictToMap(const py::dict& d);


template<class K, class V>
py::dict mapToPydict(const std::map<K, V>& map);


template<class T>
py::tuple vectorToPytupleList(std::vector<T>& v);


#endif //PYTHON_UTILS_H