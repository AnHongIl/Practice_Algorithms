#include <string>
#include <vector>

using namespace std;

string getString(int num){
    string ret = "";
    switch(num){
        case 10:
            ret = 'A';
            break;
        case 11:
            ret = 'B';
            break;
        case 12:
            ret = 'C';
            break;
        case 13:
            ret = 'D';
            break;
        case 14:
            ret = 'E';
            break;
        case 15:
            ret = 'F';
            break;
        default:
            ret = to_string(num);
            break;
    }
    return ret;
}
string conversion(int num, int base){
    if(num < base)
        return getString(num);
    
    return conversion(num / base, base) + getString(num % base);
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string game = "";

    for(int i=0; ; i++){
        if(game.size() >= m*t)
            break;
        game += conversion(i, n);        
    }

    for(int i=0; i<game.size() & answer.size() < t; i++)
        if(i % m == p-1)
            answer += game[i];
    
    return answer;
}