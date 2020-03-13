#include <iostream>

using namespace std;

class Path{
private:
    int n, i, j;
    bool l;
public:
    Path(int _n): n(_n), i(1), j(1), l(n == 0) {}

    bool end() {
        return l;
    }

    pair<int, int> current() {
        pair<int, int> p(i, j);
        return p;
    }

    void next() {
        if (i <= j+1 && i < n-j+1) {
            j++;
        } else if (i < j && i >= n-j+1) {
            i++;
        } else if (i >= j && i > n-j+1) {
            j--;
        } else if (i > j+1 && i <= n-j+1) {
            i--;
        } else {
            l = true;
        }
    }
};

int main()
{
    int a[100][100], i = 1;
    int s = 10;
    Path p(s);
    while (!p.end()) {
        a[p.current().first-1][p.current().second-1] = i;
        p.next();
        i++;
    }
    for (int i=0; i<s; i++) {
        for(int j=0; j<s; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
