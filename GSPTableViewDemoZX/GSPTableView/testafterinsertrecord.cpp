#include "testafterinsertrecord.h"

//插入后触发引擎的事件
void TestAfterInsertRecord::afterInsertRecord(GSPRecord &record)
{
    G_UNUSED(record);
    //QMessageBox::information(NULL, "Test", "Insert Ok", QMessageBox::Ok);
}
