#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b ;
    bool prime;
    while ( a < b ) {
        prime = true;
        for (int i = 2 ; i*i<=a  ; i++)
            if(a % i == 0){
                prime = false;
                break;
            }
        if(prime && ( a!=1 ))
            cout << a << ", ";
        a++;
    }
    return 0;
}
