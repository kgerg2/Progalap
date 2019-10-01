#include <iostream>

using namespace std;

int main()
{
    int hossz, maximum, legh;
    cin >> hossz;
    int l[hossz][6], legjobbak[hossz];
    maximum = 0;
    for(int i=0; i<hossz; i++){
        for(int j=0; j<6; j++){
            cin >> l[i][j];
        }
    }
    legh = 0;
    for(int i=0; i<hossz; i++){
        m = max_element(l[i], l[i] + 6);
        if(*m > maximum){
            maximum = *m;
            legh = 0;
        } else if(*m == maximum){
            legjobbak[legh] = i;
            legh++;
        }
    }
    *max_element(l[i], l[i] + 6)
    cout << "Hello world!" << endl;
    return 0;
}
