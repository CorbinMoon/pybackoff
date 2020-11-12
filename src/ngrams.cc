#include "ngrams.h"


Ngrams::Ngrams() {};

Ngrams::ngrams(const py::list& trigrams) {
   auto& t = pytupleListToVector<std::string>(trgirams);
   this->ngrams_proto.ngrams(t);
   auto& c = this->ngrams_proto.getCountsMap();
   this->counts = mapToPydict<uint64_t, float>(c);
}

Ngrams::load(const std::string& corpus) {
   this->ngrams_proto.load(corpus);
   auto& c = this->ngrams_proto.getCountsMap();
   this->counts = mapToPydict<uint64_t, float>(c);
}

Ngrams::save(const std::string& path) {
   this->ngrams_proto.save(path);
}

Ngrams::size() {
   this->ngrams_proto.getSize();
}

Ngrams::counts() {
   this->counts;
}