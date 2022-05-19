#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

class Car {
    public:
        string id;
        vector<string> in;
        vector<string> out;
        int cul_time();
        int cul_fee(vector<int> fees, int time);
};
    
int Car::cul_time() {
    int cnt = min(in.size(), out.size());
    int total_time = 0;
    int hour, minute;
    for (int i = 0; i < cnt; i++) {
        hour = (stoi(out[i].substr(0, 2)) - stoi(in[i].substr(0, 2)));
        minute = (stoi(out[i].substr(3, 2)) - stoi(in[i].substr(3, 2)));
        // cout << hour << " " << minute << endl;
        total_time += hour*60 + minute;
    }
    if (in.size() != out.size()) {
        hour = 23 - stoi(in[in.size()-1].substr(0, 2));
        minute = 59 - stoi(in[in.size()-1].substr(3, 2));
        total_time += hour*60 + minute;
    }
    return total_time;
}
    
int Car::cul_fee (vector<int> fees, int time) {
    if (fees[0] < time) {
        return fees[1] +  (ceil(time - fees[0] / fees[2]) * fees[3]);
    }
    else {
        return fees[1]; // 기본요금
    }
}

bool comp(Car& a, Car& b) {
    return a.id < b.id;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<Car> cars;
    map<string, int> m; // id, vector_idx
    
    int idx = 0;
    for (int i = 0; i < records.size(); i++) {
        string id = records[i].substr(6, 4);
        string t = records[i].substr(0, 5);
        string m = records[i].substr(11, 2);
        
        auto it = m.find(id);
        if (it != m.end()) {
            vector<string> v = {t};
            if (m == "IN") {
                cars[it->second].in.push(v);
            }
            else {
                cars[it->second].out.push(v);
            }
        }
        else {
            Car c;
            c.id = id;
            vector<string> v = {t};
            if (m == "IN") {
                c.in = v;
            }
            else {
                c.out = v;
            }
            cars.push(c);
            m.push({id, idx++});
        }
    }
    
    // cars id 기준 오름차순
    sort(cars.begin(), cars.end(), comp);
    
    for (int i = 0; i < cars.size(); i++) {
        int t = cars[i].cul_time();
        answer.push(cars[i].cul_fee(fees, t));
    }
    
    return answer;
}
