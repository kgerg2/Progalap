#pragma once

#include "record.h"
#include <vector>

class Directory : public Record {
private:
    std::vector<Record *> records;

public:
    void add(Record *rec) { records.push_back(rec); }
    int getSize() const override;

    ~Directory() {
        for (Record *rec : records)
            delete rec;
    }
};
