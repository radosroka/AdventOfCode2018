#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    long two = 0, three = 0;
    while (getline(cin, line)){
        map<char, int> m;
        for(char c: line) {
            m[c]++;
        }

        cout << endl <<  line << endl;

        for(auto p: m) {
            if (p.second == 2) {
                two++;
                cout << p.first << " " << p.second << endl;
                break;
            }
        }

        for(auto p: m) {
            if (p.second == 3) {
                three++;
                cout << p.first << " " << p.second << endl;
                break;
            }
        }
    }
    cout << endl;
    cout << "Two occurences: " << two << endl;
    cout << "Three occurences: " << three << endl;
    cout << "Checksum: " << two * three << endl;


    return 0;
}
