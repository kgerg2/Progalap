# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int i, j, uthossz, fdb, min, harom, regi, maxhossz, szhossz, szakaszon;
    //ifstream be (".\\6-Ut\\be2.txt");
    cin >> uthossz >> fdb;
    int l[fdb][2], ut[uthossz];
    for(i=0; i<uthossz; i++) ut[i] = 0;
    i = 0;
    min = uthossz + 1;
    while(cin >> l[i][0] >> l[i][1]){
        if(l[i][1] - l[i][0] < min){
            min = l[i][1] - l[i][0];
        }
        for(j=l[i][0]; j<l[i][1]; j++){
            ut[j]++;
        }
        i++;
    }
    //be.close();

    cout << min << endl;

    harom = -1;
    regi = 0;
    maxhossz = 0;
    szhossz = 0;
    szakaszon = 0;
    for(i=0; i<uthossz; i++){
        if(harom == -1 && ut[i] >= 3){
            harom = i;
        }
        if(ut[i] == 0){
            regi++;
        }
        if(szakaszon){
            if(ut[i] == 0){
                szhossz++;
                if(szhossz > maxhossz){
                    maxhossz = szhossz;
                }
            } else{
                szakaszon = 0;
            }
        } else if(ut[i] == 0){
            szakaszon = 1;
            szhossz = 1;
            if(szhossz > maxhossz){
                maxhossz = szhossz;
            }
        }
    }
    cout << harom << endl;
    
    cout << regi << endl;

    cout << maxhossz << endl;
    return 0;
}