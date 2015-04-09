#ifndef TESTEVENTHANDLE_H
#define TESTEVENTHANDLE_H
#include "GSPActions.h"

class TestEventHandle : public GSPQueryCellValueEvent, public GSPQueryCellAttributeEvent
{
public:
    void onQueryCellValue(GSPCustomRowNode *rowNode, int col, GSPField field,
                          GSPRecord record, GVariant &value, bool &handled);
    void onQueryCellAttribute(GSPCustomRowNode *rowNode, int col, GSPField field,
                              GSPRecord record, int role, GVariant &attribute, bool &handled);
};

#endif // TESTEVENTHANDLE_H
