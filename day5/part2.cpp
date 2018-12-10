#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    string polymer;
    string tmp;
    map<char,long> chars;
    getline(cin, polymer);

    // cout << polymer << endl;

    for (auto& c: polymer) {
        chars[tolower(c)] = 0;
    }

    for (auto& p: chars) {
        string polym = polymer;
        for (auto& c: polym) {
            if (tolower(c) != p.first) {
                tmp.push_back(c);
            }
        }

        polym = tmp;
        tmp = "";

        // cout << p.first << ": " << polym;

        while(1) {
            if (polym.length() == 1)break;

            bool change = false;
            for(long i = 1 ; i < polym.length() ; i++) {
                // cout << polym[i-1 ] << " " << polym[i] << " " << abs(polym[i] - polym[i-1]) ;
                if (abs(polym[i] - polym[i-1]) != 32) {
                    // cout << " different";
                    tmp.push_back(polym[i-1]);
                
                } else {
                    // cout << " same";
                    change = true;
                    i++;
                }
                if(polym.length() == i+1)
                    tmp.push_back(polym[i]);
                // cout << endl;
            }

            // cout << tmp << " " << tmp.length() << endl;

            polym = tmp;
            tmp = "";
            if (!change) break;
        }

        // cout << " " << polym << endl;

        p.second = polym.length();

        // long found = 0;
        // for(long i = 1 ; i < polym.length() ; i++) {
        //     if (tolower(polym[i]) == tolower(polym[i-1])) {
        //         found++;
        //     }
        // }
    }
    
    long min = __LONG_MAX__;
    for (auto& p: chars) {
        if (p.second < min) min = p.second;
        // cout << p.first << ": " << p.second << endl;
    }

    cout << min << endl;

    return 0;
}
