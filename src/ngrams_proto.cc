#include "ngrams_proto.h"
#include "fnv.h"
#include "slice.h"

#include <iostream>
#include <fstream>
#include <iomanip>


template<typename... Ts>
void Ngrams_Prototype::add(const std::tuple<Ts...>& t) {
   uint64_t hash = fnv::hash(t);
   if (counts.find(hash) == counts.end()) {
      counts[hash] = 1;
   }
   else {
      ++counts[hash];
   }
}

void Ngrams_Prototype::ngrams(const std::vector<Trigram>& trigrams) {
   for (auto& trigram : trigrams) {
      this->add(trigram);
      this->add(slice<0, 2>(trigram));
      this->add(slice<0, 1>(trigram));
   }
   size = trigrams.size();
}

size_t Ngrams_Prototype::getSize() {
   return size;
}

std::map<uint64_t, float> Ngrams_Prototype::getCountsMap() {
   return counts;
}

void Ngrams_Prototype::load(const std::string& path) {
   std::ifstream in;
   std::ifstream _in;
   std::string _path;
   std::string temp;
   try {
      in.open(path, std::ios::in | std::ios::binary);
      while (!in.eof()) {
         std::pair<uint64_t, float> p;
         in.read((char*)&p.first, sizeof(uint64_t));
         in.read((char*)&p.second, sizeof(float));
         this->counts.insert(p);
      }
      // get total word count from file
      _path = path.substr(0, path.size() - 4) + "_size.txt";
      _in.open(_path);
      std::getline(_in, temp);
      this->size = std::stoi(temp);
   }
   catch (std::exception& e) {
      throw "no file found named: " + path;
   }
}

void Ngrams_Prototype::save(const std::string& path) {
   std::ofstream os;
   std::ofstream _os;
   std::string _path;
   try {
      os.open(path, std::ios::out | std::ios::binary);
      for (auto& p : this->counts) {
         os.write((char*)&p.first, sizeof(uint64_t));
         os.write((char*)&p.second, sizeof(float));
      }
      // save total word count to file
      _path = path.substr(0, path.size() - 4) + "_size.txt";
      _os.open(_path);
      _os << this->size;
   }
   catch (std::exception& e) {
      throw "no file found named: " + path;
   }
}

Ngrams_Prototype::Ngrams_Prototype() {}