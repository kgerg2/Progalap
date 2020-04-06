#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("inp.txt");
    bool l = true;
    for( t.first(); l && !t.end(); t.next() ){
        l = t.current();
    }
    if(l) cout << "Mindenki lott nyulat.\n";
    else  cout << "Nem lott mindenki nyulat.\n";
    return 0;
}
