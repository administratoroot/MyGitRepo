#ifndef MYFUNCTION_H
#define MYFUNCTION_H
#include "GEPCustomFunction.h"

class MyFunction : public CGEPCustomFunction
{
public:
    GString GSPMETHODCALLTYPE name();
    GEPDataType GSPMETHODCALLTYPE resultDataType();
    GEPDataMatchType GSPMETHODCALLTYPE matchParam(long paramCount, IGEPNodeList * params);
    void GSPMETHODCALLTYPE execute(long paramCount, IGEPNodeList *params, IGEPData *result);
};
#endif // MYFUNCTION_H
