#ifndef NGRAMS_PROTO_H
#define NGRAMS_PROTO_H


#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>


typedef std::tuple<std::string, std::string, std::string> Trigram;

class Ngrams_Prototype {

private:
   std::map<uint64_t, float> counts;
   size_t size = 0;

   template<typename... Ts>
   void add(const std::tuple<Ts...>& t);

public:
   void ngrams(const std::vector<Trigram>& trigrams);
   void load(const std::string& corpus);
   void save(const std::string& path);

   size_t getSize();
   std::map<uint64_t, float> getCountsMap();
   Ngrams_Prototype();

};


#endif //NGRAMS_PROTO_H
