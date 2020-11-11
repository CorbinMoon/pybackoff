#include "python_utils.h"


namespace py = boost::python;


Trigram pytupleToTrigram(const py::tuple& t) {
   Trigram trigram = std::make_tuple("", "", "");

   std::get<0>(trigram) = py::extract<std::string>(t[0]);
   std::get<1>(trigram) = py::extract<std::string>(t[1]);
   std::get<2>(trigram) = py::extract<std::string>(t[2]);

   return trigram;
}

std::vector<Trigram> pytupleListToVector(const py::list& l) {
   std::vector<Trigram> trigrams;

   for (size_t i = 0; i < py::len(l); i++) {
      auto& t = py::extract<py::tuple>(l[i]);
      auto& trigram = pytupleToTrigram(t);
      trigrams.push_back(trigram);
   }

   return trigrams;
}

std::map<uint64_t, float> pydictToCountsMap(const py::dict& d) {

}

