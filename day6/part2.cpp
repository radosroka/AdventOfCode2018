#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    vector<pair<long, long>> coordinates;

    long x_max = 0;
    long y_max = 0;
    while (getline(cin, line)){
        long x = stol(line ,nullptr, 10);
        long y = stol(line.substr(line.find_first_of(',') + 2));

        coordinates.push_back({x, y});

        if (x > x_max) x_max = x;
        if (y > y_max) y_max = y;
    }

    x_max++;
    y_max++;

    vector<vector<long>> grid(x_max);

    for(long i = 0 ; i < grid.size() ; i++) {
        grid[i] = vector<long>(y_max);
    }

    long size = 0;
    for(long i = 0 ; i < x_max ; i++) {
        for(long j = 0 ; j < y_max ; j++) {
            
            long sum = 0;
            for(long index = 0 ; index < coordinates.size() ; index++) {
                long dx = abs(coordinates[index].first - i);
                long dy = abs(coordinates[index].second - j);

                long total = dx+dy;
                sum += total;
            }

            if (sum < 10000) size++;
        }
    }

    cout << size << endl;

    return 0;
}
