#include <iostream>
#include "recipeEnor.h"

int main() {
    RecipeEnor e("inp.txt");
    e.first();
    Recipe elem = e.current();
    int max = elem.count;
    for (e.next(); !e.end(); e.next()) {
        if (max < e.current().count) {
            elem = e.current();
            max = elem.count;
        }
    }
    std::cout << "Max: " << elem.name << " (" << elem.count << ")" << std::endl;
    return 0;
}