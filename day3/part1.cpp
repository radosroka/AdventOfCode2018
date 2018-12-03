#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Rect {
    long id;
    long off_x, off_y;
    long x, y;
};

void addRow(vector<vector<long>>& v){
    // cout << "addRow" << endl;
    v.push_back(vector<long>());

    if(v.size() == 1) return;

    for(long i = 0; i < v[0].size(); i++){
        v.back().push_back(0);
    }
}

void addColumn(vector<vector<long>>& v) {
    // cout << "addColumn" << endl;
    for(auto& i: v) {
        i.push_back(0);
    }  
}

void printArray(vector<vector<long>>& v) {
    for(auto& i: v) {
        for(long& l: i) {
            cout << l << " ";
        }
        cout << endl;
    }
}

void drawRect(vector<vector<long>>& v, Rect& r){
    cout << r.off_x << " " << r.off_y << endl;
    cout << r.x << " " << r.y << endl;
    while (r.off_y + r.y + 1 > v.size()) {
        addRow(v);
        // cout << "added row" << endl;
        // printArray(v);
    }
    while (r.off_x + r.x + 1 > v[0].size()) {
        addColumn(v);
        // cout << "added column" << endl;
        // printArray(v);
    }
    // cout << endl;

    for(long i = r.off_x; i < r.off_x + r.x; i++) {
        for(long j = r.off_y; j < r.off_y + r.y; j++) {
            v[j][i]++;
        }
    }

}

long getOverlaps(vector<vector<long>>& v) {
    long count = 0;
    for(auto& i: v) {
        for(long& l: i) {
            if(l > 1) count++;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    vector<vector<long>> map;

    string line;

    
    while (getline(cin, line)){
        Rect r;

        // cout << line << endl;

        size_t end = 0;
        string s = line.substr(1);
        r.id = stol(s, &end, 10);

        s = s.substr(end+3);
        r.off_x = stol(s, &end, 10);

        s = s.substr(end+1);
        r.off_y = stol(s, &end, 10);

        s = s.substr(end+2);
        r.x = stol(s, &end, 10);
        
        s = s.substr(end+1);
        r.y = stol(s, &end, 10);

        // cout << id << " " << off_x << " " << off_y << " " << x << " " << y << endl << endl;

        drawRect(map, r);
        //printArray(map);
    }
    cout << "Overlaping: " << getOverlaps(map) << endl;
    return 0;
}
