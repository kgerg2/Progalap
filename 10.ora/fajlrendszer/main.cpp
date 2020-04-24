#include "directory.h"
#include "file.h"
#include <iostream>

int main() {
    Directory *fileSystem = new Directory();
    fileSystem->add(new File(10));
    Directory *dir2 = new Directory();
    dir2->add(new File(5));
    fileSystem->add(dir2);
    std::cout << fileSystem->getSize() << std::endl;
    return 0;
}
