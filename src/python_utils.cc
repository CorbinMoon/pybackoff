#include "python_utils.h"


namespace py = boost::python;


Trigram pytupleToTrigram(const py::tuple& t) {
   return std::make_tuple(
      py::extract<std::string>(t[0]),
      py::extract<std::string>(t[1]),
      py::extract<std::string>(t[2])
   );
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
   py::list items = d.items();
   std::map<uint64_t, float> counts;

   for (size_t i = 0; i < py::len(items); i++) {
      auto& key = py::extract<uint64_t>(items[i][0]);
      auto& val = py::extract<float>(items[i][1]);
      counts[key] = val;
   }

   return counts;
}

py::dict countsMapToPydict(const std::map<uint64_t, float>& counts) {
   py::dict dict;

   for (auto& p : counts) dict[p.first] = p.second;
  
   return dict;
}

py::tuple trigramToPytuple(const Trigram& t) {
   py:tuple tuple(
      std::get<0>(t),
      std::get<1>(t),
      std::get<2>(t)
   );
   return tuple;
}

py::tuple vectorToPytupleList(std::vector<Trigram>& v) {
   py::list list;

   for (auto& elem : v) {
      auto& t = trigramToPytuple(elem);
      list.append(t);
   }

   return list;
}