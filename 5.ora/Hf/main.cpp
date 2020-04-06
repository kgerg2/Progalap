#include <iostream>
#include <fstream>
#include "dishEnor.h"

using namespace std;

int main()
{
    string file;
    cout << "File: ";
    cin >> file;
    dishEnor e(file);
    e.first();
    int max = 0;
    Dish elem = e.current();
    for (e.next(); !e.end(); e.next()) {
        if (max < e.current().price * e.current().count)
        {
            elem = e.current();
            max = elem.price * elem.count;
        }
    }
    cout << "Max: " << elem.name << " (" << max << " Ft)" << endl;
    return 0;
}