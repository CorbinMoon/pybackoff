#ifndef NGRAMS_H
#define NGRAMS_H


#include "ngrams_proto.h"
#include "python_utils.h"


class Ngrams {

private:
   py::dict counts;
   Ngrams_Prototype ngrams_proto;

public:
   Ngrams();
   ngrams(const py::list& trigrams);
   void load(const std::string& corpus);
   void save(const std::string& path);
   size_t size();
   py::dict counts();

};

#endif // NGRAMS_H