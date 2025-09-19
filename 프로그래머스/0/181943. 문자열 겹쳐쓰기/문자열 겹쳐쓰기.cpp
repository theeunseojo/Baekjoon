#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    int part = my_string.length() - (overwrite_string.length() + s);
    answer = my_string.substr(0, s) + overwrite_string + my_string.substr(s + overwrite_string.length(), part);
    return answer;
}