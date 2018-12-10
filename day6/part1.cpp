#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    vector<pair<long, long>> coordinates;
    vector<long> occurencies;
    vector<bool> infinite;

    long x_max = 0;
    long y_max = 0;
    while (getline(cin, line)){
        long x = stol(line ,nullptr, 10);
        long y = stol(line.substr(line.find_first_of(',') + 2));

        coordinates.push_back({x, y});
        occurencies.push_back(0);
        infinite.push_back(false);

        if (x > x_max) x_max = x;
        if (y > y_max) y_max = y;
    }

    x_max++;
    y_max++;

    vector<vector<long>> grid(x_max);

    for(long i = 0 ; i < grid.size() ; i++) {
        grid[i] = vector<long>(y_max);
    }

    for(long i = 0 ; i < x_max ; i++) {
        for(long j = 0 ; j < y_max ; j++) {

            long min = __LONG_MAX__;
            long indexx = 0;
            bool more = false;

            for(long index = 0 ; index < coordinates.size() ; index++) {
                long dx = abs(coordinates[index].first - i);
                long dy = abs(coordinates[index].second - j);

                long total = dx+dy;

                if (total <= min) {
                    if (total == min) more = true;
                    else more = false;
                    min = total;
                    indexx = index;
                }
            }

            if (more) continue;

            occurencies[indexx]++;

            if (i == 0 || j == 0 || i == x_max-1 || j == y_max-1) {
                infinite[indexx] = true;
            }

        }
    }

    long max = 0;
    for(long i = 0 ; i < coordinates.size() ; i++) {
        if (!infinite[i] && occurencies[i] > max) max = occurencies[i];
        //cout << coordinates[i].first << "," << coordinates[i].second << " " << occurencies[i] << " " << infinite[i] << endl;
    }

    cout << max << endl;

    return 0;
}
