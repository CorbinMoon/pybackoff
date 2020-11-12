#include "sbmodel_proto.h"
#include "fnv.h"
#include "slice.h"

SBModel_Prototype::SBModel_Prototype() {}

SBModel_Prototype::init(const std::map<uint64_t, float>& counts, size_t N) {
    this->counts = counts;
    this->N = N;
}

float SBModel_Prototype::__score(const Trigram& trigram, size_t n) {
    if (n == 1) {
        uint64_t hash = fnv::hash(slice<2, 3>(trigram));
        return counts[hash] / (float)N;
    }
    if (n == 2) {
        uint64_t hash = fnv::hash(slice<1, 3>(trigram));
        if (counts[hash] > 0) {
            uint64_t hash1 = fnv::hash(slice<1, 2>(trigram));
            return counts[hash] / counts[hash1];
        }
        return ALPHA * this->__score(trigram, n - 1);
    }
    uint64_t hash = fnv::hash(trigram);
    if (counts[hash] > 0) {
        uint64_t hash1 = fnv::hash(slice<0, 2>(trigram));
        return counts[hash] / counts[hash1];
    }
    return ALPHA * this->__score(trigram, n - 1);

}

std::map<Trigram, float> SBModel_Prototype::score(const std::vector<Trigram>& trigrams) {
    std::map<Trigram, float> scores;
    for (auto& trigram : trigrams) {
        scores[trigram] = this->__score(trigram, 3);
    }
    return scores;
}