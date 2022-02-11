#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

bool legal = true;

void legal_check( string check )
{
	if ( check.size() != 4 ){
		cout << "Wrong input length. Please enter again.\n";
		legal = false;
	}
	else if((check[0] != '0' && check[0] != '1' && check[0] != '2' && check[0] != '3' && check[0] != '4' &&
			 check[0] != '5' && check[0] != '6' && check[0] != '7' && check[0] != '8' && check[0] != '9' )||
			(check[1] != '0' && check[1] != '1' && check[1] != '2' && check[1] != '3' && check[1] != '4' &&
			 check[1] != '5' && check[1] != '6' && check[1] != '7' && check[1] != '8' && check[1] != '9' )||
			(check[2] != '0' && check[2] != '1' && check[2] != '2' && check[2] != '3' && check[2] != '4' &&
			 check[2] != '5' && check[2] != '6' && check[2] != '7' && check[2] != '8' && check[2] != '9' )||
			(check[3] != '0' && check[3] != '1' && check[3] != '2' && check[3] != '3' && check[3] != '4' &&
			 check[3] != '5' && check[3] != '6' && check[3] != '7' && check[3] != '8' && check[3] != '9' )){
			 cout << "Illegal character detected. Please enter again.\n";
			legal = false;
	}

	else if ( check[0] == check[1] || check[0] == check[2] || check[0] == check[3] ||
			  check[1] == check[2] || check[1] == check[3] || check[2] == check[3] ){
			cout << "Duplicate digit detected. Please enter again.\n";
			legal = false;
	}
}

int main(){
	srand(time(0));
	cout << "Please choose mode. 1-random , or  2-user input :\n" ;
	int mode;
	cin >> mode;
	string answer, guess;
	int t = 0;
	if ( mode == 1 ){
        do{ for( int i=0;i<4 ;i++){
                t++;
                switch(rand()%10){
                    case 0 : answer.append("0");break; case 1 :answer.append("1");break;
                    case 2 : answer.append("2");break; case 3 :answer.append("3");break;
                    case 4 : answer.append("4");break; case 5 :answer.append("5");break;
                    case 6 : answer.append("6");break; case 7 :answer.append("7");break;
                    case 8 : answer.append("8");break; case 9 :answer.append("9");break;
                }
        if (t == 1000) {
        cout << "Are you sure? give you a chance to choose again.\n\n";
            main();
        }
        }
        }while( answer[0] == answer[1] || answer[0] == answer[2] || answer[0] == answer[3] ||
			  answer[1] == answer[2] || answer[1] == answer[3] || answer[2] == answer[3] );
	}
	else if( mode == 2 ){
		cout << "Please enter correct answer :\n";
		do{ legal = true;cin >> answer; legal_check(answer);} while ( !legal );
	}
	else return 0;
	for (int times = 1 ,n,m; times <= 7 ; ++times){
        n = 0;
        m = 0;
		cout << "Please enter your guess number :\n";
		do{ legal = true; cin >> guess; legal_check(guess);} while(!legal);
		for (int i = 0; i < 4; ++i)	if (guess[i] == answer[i]  ) n++;
		for (int i = 0; i < 3; ++i)	if (guess[i] == answer[i+1]) m++;
		for (int i = 0; i < 3; ++i)	if (guess[i+1] == answer[i]) m++;
		for (int i = 0; i < 2; ++i)	if (guess[i] == answer[i+2]) m++;
		for (int i = 0; i < 2; ++i)	if (guess[i+2] == answer[i]) m++;
		for (int i = 0; i < 1; ++i)	if (guess[i] == answer[i+3]) m++;
		for (int i = 0; i < 1; ++i)	if (guess[i+3] == answer[i]) m++;
		cout << "Hint " << times << " : " << n << "A" << m << "B\n";
		if ( n == 4 ) {
			cout << "Correct! You only guessed for " << times << " times.";
			break;
		}
		if ( n != 4 && times == 7) cout << "You lose this game! QQ\nThe correct answer is : " << answer << "\n\n";
	}
	cout << "Do you want to play again ???(yes/no)\n\n";
	string again;
	cin >> again;
	if (again == "yes") {
        cout << endl;
        main();
	}
	else return 0;
}
