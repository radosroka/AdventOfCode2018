#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    long freq = 0;

    map<long, bool> m;
    vector<long> v;

    while (getline(cin, line)){
        long value = stol(line ,nullptr, 10);
        v.push_back(value);

        // cout << freq << endl;

 
    }

    while(1) {
        for(long l: v) {
            freq += l;

            if (m.count(freq) > 0) {
                cout << "Frequency reached twice: " << freq << endl;
                return 0;
            } else {
                m[freq] = true;
            }
        }
    }

    return 0;
}
