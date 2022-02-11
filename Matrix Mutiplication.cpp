#include <iostream>
using namespace std;

int main(){
    int a[115][115], b[115][115], c[115][115], m, n, p;
    cin >> m >> n ;

    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cin >> n >> p ;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            cin >> b[i][j];

    for(int row = 0; row < m; row++)
        for(int column = 0; column < p; column++)
            for(int cnt = 0; cnt < n; cnt++)
                c[row][column] += a[row][cnt] * b[cnt][column];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
            cout << c[i][j] << ((j != p - 1)? " ":"\n");

    return 0;
}
