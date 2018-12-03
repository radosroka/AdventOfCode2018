#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    long freq = 0;
    while (getline(cin, line)){
        long value = stol(line ,nullptr, 10);
        freq += value;
    }

    cout << "Resulting frequency is: " << freq << endl;

    return 0;
}
