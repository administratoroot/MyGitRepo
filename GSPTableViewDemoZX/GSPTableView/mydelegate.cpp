#include "mydelegate.h"

//���ñ༭��ʽ
GEditStyle MyDelegate::editStyle(GSPCustomRowNode *rowNode, int dataCol, bool &readOnly) const
{
    if (3 == dataCol)
    {
        return esDropDown;
    }
    else
    {
        return GSPDefaultItemDelegate::editStyle(rowNode, dataCol, readOnly);
    }
}
