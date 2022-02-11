#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct GAME{ int score = 0 ; int table[4][4] ;};
void show( GAME &g ){
	for( int i = 0 ; i < 4 ; ++i ){
		for( int j = 0 ; j < 4 ; ++j ) cout << setw(5) << g.table[i][j] << ",";
		cout << "\n\n" ;
	}
	cout << "              score : " << g.score << "\n------------------------------\n";
}
void up(GAME &g){
	for ( int r = 0 ; r < 4 ; ++r ){
		for( int i = 0 ; i < 3 && g.table[0][r] == 0 ; i++ ){
			g.table[0][r] = g.table[1][r];
			g.table[1][r] = g.table[2][r];
			g.table[2][r] = g.table[3][r];
			g.table[3][r] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[1][r] == 0 ; i++ ){
			g.table[1][r] = g.table[2][r];
			g.table[2][r] = g.table[3][r];
			g.table[3][r] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[2][r] == 0 ; i++ ){
			g.table[2][r] = g.table[3][r];
			g.table[3][r] = 0;
		}
		if( g.table[0][r] == g.table[1][r] ){
			g.table[0][r] += g.table[1][r];
			g.table[1][r] = g.table[2][r];
			g.table[2][r] = g.table[3][r];
			g.table[3][r] = 0;
			g.score += g.table[0][r];
		}
		if( g.table[1][r] == g.table[2][r] ){
			g.table[1][r] += g.table[2][r];
			g.table[2][r] = g.table[3][r];
			g.table[3][r] = 0;
			g.score += g.table[1][r];
		}
		if( g.table[2][r] == g.table[3][r] ){
			g.table[2][r] += g.table[3][r];
			g.table[3][r] = 0;
			g.score += g.table[2][r];
		}
    }
}
void down(GAME &g){
	for ( int r = 0 ; r < 4 ; ++r ){
		for( int i = 0 ; i < 3 && g.table[3][r] == 0 ; i++ ){
			g.table[3][r] = g.table[2][r];
			g.table[2][r] = g.table[1][r];
			g.table[1][r] = g.table[0][r];
			g.table[0][r] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[2][r] == 0 ; i++ ){
			g.table[2][r] = g.table[1][r];
			g.table[1][r] = g.table[0][r];
			g.table[0][r] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[1][r] == 0 ; i++ ){
			g.table[1][r] = g.table[0][r];
			g.table[0][r] = 0;
		}
		if( g.table[3][r] == g.table[2][r] ){
			g.table[3][r] += g.table[2][r];
			g.table[2][r] = g.table[1][r];
			g.table[1][r] = g.table[0][r];
			g.table[0][r] = 0;
			g.score += g.table[3][r];
		}
		if( g.table[2][r] == g.table[1][r] ){
			g.table[2][r] += g.table[1][r];
			g.table[1][r] = g.table[0][r];
			g.table[0][r] = 0;
			g.score += g.table[2][r];
		}
		if( g.table[1][r] == g.table[0][r] ){
			g.table[1][r] += g.table[0][r];
			g.table[0][r] = 0;
			g.score += g.table[1][r];
		}
    }
}
void left(GAME &g){
	for ( int c = 0 ; c < 4 ; ++c ){
		for( int i = 0 ; i < 3 && g.table[c][0] == 0 ; i++ ){
			g.table[c][0] = g.table[c][1];
			g.table[c][1] = g.table[c][2];
			g.table[c][2] = g.table[c][3];
			g.table[c][3] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[c][1] == 0 ; i++ ){
			g.table[c][1] = g.table[c][2];
			g.table[c][2] = g.table[c][3];
			g.table[c][3] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[c][2] == 0 ; i++ ){
			g.table[c][2] = g.table[c][3];
			g.table[c][3] = 0;
		}
		if( g.table[c][0] == g.table[c][1] ){
			g.table[c][0] += g.table[c][1];
			g.table[c][1] = g.table[c][2];
			g.table[c][2] = g.table[c][3];
			g.table[c][3] = 0;
			g.score += g.table[c][0];
		}
		if( g.table[c][1] == g.table[c][2] ){
			g.table[c][1] += g.table[c][2];
			g.table[c][2] = g.table[c][3];
			g.table[c][3] = 0;
			g.score += g.table[c][1];
		}
		if( g.table[c][2] == g.table[c][3] ){
			g.table[c][2] += g.table[c][3];
			g.table[c][3] = 0;
			g.score += g.table[c][2];
		}
    }
}
void right(GAME &g){
	for ( int c = 0 ; c < 4 ; ++c ){
		for( int i = 0 ; i < 3 && g.table[c][3] == 0 ; i++ ){
			g.table[c][3] = g.table[c][2];
			g.table[c][2] = g.table[c][1];
			g.table[c][1] = g.table[c][0];
			g.table[c][0] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[c][2] == 0 ; i++ ){
			g.table[c][2] = g.table[c][1];
			g.table[c][1] = g.table[c][0];
			g.table[c][0] = 0;
		}
		for( int i = 1 ; i < 3 && g.table[c][1] == 0 ; i++ ){
			g.table[c][1] = g.table[c][0];
			g.table[c][0] = 0;
		}
		if( g.table[c][3] == g.table[c][2] ){
			g.table[c][3] += g.table[c][2];
			g.table[c][2] = g.table[c][1];
			g.table[c][1] = g.table[c][0];
			g.table[c][0] = 0;
			g.score += g.table[c][3];
		}
		if( g.table[c][2] == g.table[c][1] ){
			g.table[c][2] += g.table[c][1];
			g.table[c][1] = g.table[c][0];
			g.table[c][0] = 0;
			g.score += g.table[c][3];
		}
		if( g.table[c][1] == g.table[c][0] ){
			g.table[c][1] += g.table[c][0];
			g.table[c][0] = 0;
			g.score += g.table[c][1];
		}
    }
}
void new_num(GAME &g){
    int a = rand() % 16;
    while( g.table[a/4][a%4] != 0 ) a++ ;
    g.table[a/4][a%4] = 2*(rand()%2) + 2;
}
int main() {
	GAME g;
	char control;
	int rep;
	for( int i = 0 ; i < 4 ; i++ ) for( int j = 0 ; j < 4 ; j++ ) g.table[i][j]=0;
	new_num(g);show(g);

    while( cin >> control ){
        if( control == 'w' ) rep = 1;
        if( control == 'a' ) rep = 2;
        if( control == 's' ) rep = 3;
        if( control == 'd' ) rep = 4;
        switch( rep ){
    	case 1 : up(g);	show(g);new_num(g); break;
    	case 2 : left(g); show(g);new_num(g);break;
        case 3 : down(g); show(g);new_num(g);break;
        case 4 : right(g);show(g);new_num(g);break;
        }
    }
	return 0;
}