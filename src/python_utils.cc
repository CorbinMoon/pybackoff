#include "python_utils.h"


namespace py = boost::python;


template<class T>
T pytupleToTrigram(const py::tuple& t) {
   return std::make_tuple(
      py::extract<T>(t[0]),
      py::extract<T>(t[1]),
      py::extract<T>(t[2])
   );
}

template<class T>
py::tuple trigramToPytuple(const T& t) {
   py:tuple tuple(
      std::get<0>(t),
      std::get<1>(t),
      std::get<2>(t)
   );
   return tuple;
}

template<class T>
std::vector<T> pytupleListToVector(const py::list& l) {
   std::vector<T> v;

   for (size_t i = 0; i < py::len(l); i++) {
      auto& t = py::extract<py::tuple>(l[i]);
      auto& trigram = pytupleToTrigram<T>(t);
      v.push_back(trigram);
   }

   return trigrams;
}

template<class K, class V>
std::map<K, V> pydictToMap(const py::dict& d) {
   py::list items = d.items();
   std::map<K, V> map;

   for (size_t i = 0; i < py::len(items); i++) {
      auto& key = py::extract<K>(items[i][0]);
      auto& val = py::extract<V>(items[i][1]);
      map[key] = val;
   }

   return map;
}


template<class K, class V>
py::dict mapToPydict(const std::map<K, V>& map) {
   py::dict dict;

   for (auto& p : map) 
      dict[p.first] = p.second;
  
   return dict;
}

template<class K, class V>
py::dict mapToScoreDict(const std::map<K, V>& map) {
   py::dict dict;

   for (auto& p : map) {
      auto& t = trigramToPytuple<std::string>(p.first);
      dict[p.first] = p.second;
   }

   return dict;
}

template<class T>
py::tuple vectorToPytupleList(std::vector<T>& v) {
   py::list list;

   for (auto& elem : v) {
      auto& t = trigramToPytuple<T>(elem);
      list.append(t);
   }

   return list;
}