#ifndef TESTAFTERINSERTRECORD_H
#define TESTAFTERINSERTRECORD_H
#include "GSPCore.h"
class TestAfterInsertRecord : public GSPAfterInsertRecordImpl
{
public:
    void afterInsertRecord(GSPRecord &record);
};
#endif // TESTAFTERINSERTRECORD_H
