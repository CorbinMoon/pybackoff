#include "sbmodel.h"


SBModel::SBModel(const py::dict& counts, size_t N) {
   auto& c = pydictToMap<uint64_t, float>(counts);
   this->sbmodel_proto.init(c, N);
}

SBModel::score(const py::list& trigrams) {
   auto& t = pytupleListToVector<Trigram>(trigrams);
   auto& scores = this->sbmodel_proto.score(t);
   return mapToScoreDict<Trigram, float>(scores);
}