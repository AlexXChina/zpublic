#pragma once
#include "SavesDef.h"

///> �浵������
class CSavesMgr
{
public:
    CSavesMgr();
    ~CSavesMgr();

public:
    bool Load();

    int Save();
};

