#pragma once

#include "record.h"

class File : public Record {
private:
    int size;

public:
    File(int s) : size(s) {}
    int getSize() const override { return size; }
};