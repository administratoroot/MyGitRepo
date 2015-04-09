#include "testeventhandle.h"

//queryCell改变值
void TestEventHandle::onQueryCellValue(GSPCustomRowNode *rowNode, int col, GSPField field, GSPRecord record, GVariant &value, bool &handled)
{
    G_UNUSED(handled);
    G_UNUSED(record);
    G_UNUSED(field);
//    if ((4 == col) && (2 == rowNode->rowNo()))
//    {
//        QImage oImage = QImage(":/res/res/Add16.png");
//        oImage.setText("Image", "..\\bin\\Add16.png");
//        value = oImage;
//    }
//    else if ((4 == col) && (1 == rowNode->rowNo()))
//    {
//        QImage oImage = QImage(":/res/res/back.png");
//        oImage.setText("Image", "..\\bin\\back.png");
//        value = oImage;
//    }
}

//设置queryCellAttribute
void TestEventHandle::onQueryCellAttribute(GSPCustomRowNode *rowNode, int col, GSPField field, GSPRecord record, int role, GVariant &attribute, bool &handled)
{
    G_UNUSED(handled);
    G_UNUSED(rowNode);
    if (3 == col)
    {
        if (role == Qt::BackgroundColorRole)
        {
            attribute = QColor(0xFF, 0xFF, 0xC8);
        }
    }
    else if (4 == col)
    {
        if (Qt::TextAlignmentRole == role)
        {
            attribute = Qt::AlignHCenter;
        }
    }
}
