#ifndef FNV_H
#define FNV_H


#include <iostream>
#include <tuple>
#include <string>


const uint64_t FNV_PRIME = 0x100000001b3;
const uint64_t FNV_OFFSET_BASIS = 0xcbf29ce484222325;


namespace fnv {

   inline void fnv1_hash(const std::string& v, uint64_t* seed) {
      for (int i = 0; i < v.length(); i++) {
         *seed *= FNV_PRIME;
         *seed ^= v[i];
      }
   }

   inline void fnv1_hash(const unsigned& v, uint64_t* seed) {
      *seed *= FNV_PRIME;
      *seed ^= v;
   }

   template<unsigned index, typename... Ts>
   struct tuple_hash {
      void operator() (const std::tuple<Ts...>& t, uint64_t* seed) {
         auto& item = std::get<index>(t);
         fnv1_hash(item, seed);
         tuple_hash<index - 1, Ts...>{}(t, seed);
      }
   };

   template<typename... Ts>
   struct tuple_hash<0, Ts...> {
      void operator() (const std::tuple<Ts...>& t, uint64_t* seed) {
         auto& item = std::get<0>(t);
         fnv1_hash(item, seed);
      }
   };

   template<typename... Ts>
   uint64_t hash(const std::tuple<Ts...>& t) {
      const size_t size = std::tuple_size<std::tuple<Ts...>>::value;
      uint64_t seed = FNV_OFFSET_BASIS;
      tuple_hash<size - 1, Ts...>{}(t, &seed);
      return seed;
   };

}


#endif //FNV_H
