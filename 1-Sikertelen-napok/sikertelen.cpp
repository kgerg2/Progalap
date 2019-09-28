# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int i, hossz, bev, max, kezd, maxkezd, maxhossz;
    //ifstream be (".\\1-Sikertelen-napok\\be2.txt");
    cin >> hossz;
    i = kezd = 0;
    maxkezd = -2;
    max = maxhossz = -1;
    while(cin >> bev){
        if(bev > max){
            max = bev;
            kezd = i + 1;
        } else{
            if(i - kezd > maxhossz){
                maxhossz = i - kezd;
                maxkezd = kezd;
            }
        }
        
        i++;
    }
    cout << ++maxhossz << endl;
    cout << ++maxkezd << endl;
    return 0;
}