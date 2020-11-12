#ifndef SBMODEL_H
#define SBMODEL_H


#include "sbmodel_proto.h"
#include "python_utils.h"


class SBModel {

private:
   SBModel_Prototype sbmodel_proto;

public:
   SBModel(const py::dict& counts, size_t N);
   py::dict score(const py::list& trigrams);

};

#endif // SBMODEL_H