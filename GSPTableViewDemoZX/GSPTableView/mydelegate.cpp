#include "mydelegate.h"

//…Ë÷√±‡º≠∑Ω Ω
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
