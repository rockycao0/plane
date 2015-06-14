#include<string>
#include<sstream>
using namespace std;
string tostr(int score)
{
    stringstream ss;
    ss<<score;
    string str = ss.str();
    return str;
}
