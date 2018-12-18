#include <string>
#include <algorithm>
#include <regex>
#include <tuple>
#include <utility>

using namespace std;

tuple<string, int, string> getTuple(const string& a){
    regex num("[0-9]+");
    smatch m;
    
    regex_search(a, m, num);
    string s(m[0]);
    return make_tuple(a.substr(0, a.find(s)), stoi(s), a.substr(a.find(s) + s.size()));
}

bool cmp(const string& a, const string& b){    
    tuple<string, int, string> t1 = getTuple(a);
    tuple<string, int, string> t2 = getTuple(b);

    transform(get<0>(t1).begin(), get<0>(t1).end(), get<0>(t1).begin(), ::tolower);
    transform(get<0>(t2).begin(), get<0>(t2).end(), get<0>(t2).begin(), ::tolower);
    
    if(get<0>(t1) < get<0>(t2))
        return true;
    else if(get<0>(t1) > get<0>(t2))
        return false;
    else
        if(get<1>(t1) < get<1>(t2))
            return true;
        else
            return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
   
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}