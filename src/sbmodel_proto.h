#ifndef SBMODEL_PROTO
#define SBMODEL_PROTO


#include "ngrams_proto.h"


class SBModel_Prototype {

private:
   const float ALPHA = 0.4;
   std::map<uint64_t, float> counts;
   size_t N;

   float __score(const Trigram& trigram, size_t n);

public:
   std::map<Trigram, float> score(const std::vector<Trigram>& trigrams);
   SBModel_Prototype(const std::map<uint64_t, float>& counts, size_t N);

};


#endif //SBMODEL_PROTO
