#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string polymer;
    string tmp;
    getline(cin, polymer);

    cout << polymer << " " << polymer.length() << endl;


    while(1) {
        if (polymer.length() == 1)break;

        bool change = false;
        for(long i = 1 ; i < polymer.length() ; i++) {
            // cout << polymer[i-1 ] << " " << polymer[i] << " " << abs(polymer[i] - polymer[i-1]) ;
            if (abs(polymer[i] - polymer[i-1]) != 32) {
                // cout << " different";
                tmp.push_back(polymer[i-1]);
               
            } else {
                // cout << " same";
                change = true;
                i++;
            }
            if(polymer.length() == i+1)
                tmp.push_back(polymer[i]);
            // cout << endl;
        }

        // cout << tmp << " " << tmp.length() << endl;

        polymer = tmp;
        tmp = "";
        if (!change) break;
    }

    long found = 0;
    for(long i = 1 ; i < polymer.length() ; i++) {
        if (tolower(polymer[i]) == tolower(polymer[i-1])) {
            found++;
        }
    }

    cout << "check: " << found << endl;

    cout << " " << polymer.length() << endl;

    return 0;
}
