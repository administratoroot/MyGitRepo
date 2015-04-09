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
#endif // MYDELEGATE_H
