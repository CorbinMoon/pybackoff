#include <boost/python.hpp>
#include "ngrams.h"
#include "sbmodel.h"


namespace py = boost::python;


BOOST_PYTHON_MODULE(pybackoff) {

   py::class_<Ngrams>("Ngrams")
      .def("ngrams", &Ngrams::ngrams)
      .def("load", &Ngrams::load)
      .def("save", &Ngrams::save)
      .def("size", &Ngrams::size)
      .def("counts", &Ngrams::countsDict);

}