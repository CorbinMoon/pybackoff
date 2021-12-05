#include <boost/python.hpp>
#include <Python.h>
#include "ngrams.h"
#include "sbmodel.h"


namespace py = boost::python;


BOOST_PYTHON_MODULE(pybackoff) {

   py::class_<Ngrams>("Ngrams", py::init<>())
      .def("ngrams", &Ngrams::ngrams)
      .def("load", &Ngrams::load)
      .def("save", &Ngrams::save)
      .def("size", &Ngrams::size)
      .def("counts", &Ngrams::countsDict);

   py::class_<SBModel>("SBModel", py::init<py::dict, size_t>())
      .def("score", &SBModel::score);

}