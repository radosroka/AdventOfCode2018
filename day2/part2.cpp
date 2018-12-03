#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;

    vector<string> v;

    while (getline(cin, line)){
        v.push_back(line);
    }

    for(long int i = 0; i < v.size(); i++) {
        for(long int j = i+1; j < v.size(); j++) {
            int diff = 0;
            string s;
            for(int k = 0; k < v[i].size(); k++) {
                if(v[i][k] == v[j][k]) {
                    s.push_back(v[i][k]);
                    continue;
                } else {
                    diff++;
                }
            }

            if (diff == 1) {
                cout << i << ": " << v[i] << endl;
                cout << j << ": " << v[j] << endl;
                cout << "Result: " << s << endl;
                cout << endl;
            }
        }
    }

    return 0;
}
