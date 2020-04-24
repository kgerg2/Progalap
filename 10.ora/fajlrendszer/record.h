#pragma once

class Record {
public:
    virtual int getSize() const = 0;
    virtual ~Record() {};
};