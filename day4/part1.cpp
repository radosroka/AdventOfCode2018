#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Date {
    long year, month, day, hour, min;

    void parse(string s) {
        year = stol(s, nullptr, 10);
        month = stol(s.substr(5), nullptr, 10);
        day = stol(s.substr(8), nullptr, 10);
        hour = stol(s.substr(11), nullptr, 10);
        min = stol(s.substr(14), nullptr, 10);
    }

    long toMinutes() {
        return min + (hour * 60);
    }

    long diff(Date& d) {
        return abs(this->toMinutes() - d.toMinutes());
    }

    void print() {
        cout << year << "-" << month << "-" << day << " " << hour << ":" << min << endl;
    }
};

struct Guard {
    long id;
    long asleep;

    map<long, long> minutes;

    Guard(long id) : id(id), asleep(0) {}
    Guard() {};

    void countMinutes() {
        long sum = 0;
        for (auto& minute: this->minutes) {
            sum += minute.second;
        }

        this->asleep = sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> input;
    map<long, Guard> guards;
    string line;
    while (getline(cin, line)){
        input.push_back(line);
    }

    sort(input.begin(), input.end());

    Date last;
    long actual_guard;

    for(auto s: input) {

        Date date;
        date.parse(s.substr(s.find_first_of("[")+1, s.find_last_of("]")-1));

        // cout << s << endl;
        // cout << "actual: " << date.toMinutes() << endl;
        // cout << "last: " << last.toMinutes() << endl;

        size_t pos = -1;
        if ((pos = s.find('#')) != string::npos) {
            // cout << "found id" << endl << endl;
            long res = stol(s.substr(pos+1));
            guards[res].id = res;
            actual_guard = res;
            continue;
        }

        if (s.find("falls asleep") != string::npos) {
            // cout << "falling asleep" << endl << endl;
            last = date;
            continue;
        }

        if (s.find("wakes up") != string::npos) {
            // cout << "waking up" << endl;
            guards[actual_guard].asleep += date.diff(last);
            // cout << "diff: " << date.diff(last) << endl << endl;
            for (long i = last.toMinutes() ; i < date.toMinutes() ; i++) {
                // cout << "minute: " << i << ";" << " marking: " << i%60 << endl;
                guards[actual_guard].minutes[i%60]++;
            }
            continue;
        }
    }

    Guard t = guards[0];
    for (auto& g: guards) {
        g.second.countMinutes();
        if (g.second.asleep > t.asleep) {
            t = g.second;
        }
    }  

    std::pair<long, long> max;
    for (auto& minute: t.minutes) {
        if (minute.second > max.second) {
            max = minute;
        }
        cout << minute.first << " " << minute.second << "x" << endl;
    }

    cout << endl << t.id << " " << t.asleep << endl;
    cout << "most sleeped minute ";
    cout << max.first << " " << max.second << endl << endl;

    cout << "Result is: " << t.id << " x " << max.first << " = " << t.id * max.first << endl;

    return 0;
}
