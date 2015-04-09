#include "myfunction.h"

void MyFunction::execute(long paramCount, IGEPNodeList *params, IGEPData *result)
{
    G_UNUSED(paramCount);
    G_UNUSED(params);
    int value = result->asInteger();
    result->setAsInteger(value + 1);
}

GString MyFunction::name()
{
    return "aaa";
}

GEPDataType MyFunction::resultDataType()
{
    return edtInteger;
}

GEPDataMatchType MyFunction::matchParam(long paramCount, IGEPNodeList *params)
{
    G_UNUSED(paramCount);
    G_UNUSED(params);
    return dmtExact;
}
