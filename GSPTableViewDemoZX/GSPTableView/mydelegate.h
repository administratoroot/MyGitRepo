#ifndef MYDELEGATE_H
#define MYDELEGATE_H
#include "GSPCore.h"
#include "GSPTableView.h"
#include "GSPDefaultItemDelegate.h"
class MyDelegate : public GSPDefaultItemDelegate
{
public:
    GEditStyle editStyle(GSPCustomRowNode *rowNode, int dataCol, bool &readOnly) const;
};

class TestEventHandle : public GSPQueryCellValueEvent, public GSPQueryCellAttributeEvent
{
public:
    void onQueryCellValue(GSPCustomRowNode *rowNode, int col, GSPField field,
                          GSPRecord record, GVariant &value, bool &handled);
    void onQueryCellAttribute(GSPCustomRowNode *rowNode, int col, GSPField field,
                              GSPRecord record, int role, GVariant &attribute, bool &handled);
};
#endif // MYDELEGATE_H
