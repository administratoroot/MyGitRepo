#ifndef TESTPARSECONSTEVENT_H
#define TESTPARSECONSTEVENT_H
#include "GSPTableView.h"

class TestParseConstEvent : public GEPQueryConstValueDelegate
{
public:
    void onQueryConstValue(const GString & constCode, GString & value, void * info);
};
#endif // TESTPARSECONSTEVENT_H
