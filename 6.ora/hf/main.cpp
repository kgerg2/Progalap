#include <iostream>
#include "recipeEnor.h"

int main() {
    RecipeEnor e("inp.txt");
    int max = -1;
    e.first();
    Recipe elem = e.current();
    for (e.next(); !e.end(); e.next()) {
        if (max < e.current().count) {
            elem = e.current();
            max = elem.count;
        }
    }
    std::cout << "Max: " << elem.name << " (" << elem.count << ")" << std::endl;
    return 0;
}