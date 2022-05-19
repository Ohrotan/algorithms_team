#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> res; // 차량번호, 요금
int MIN_TIME;
int MIN_FEE;
int TIME_UNIT;
int FEE_UNIT;

struct ParkingInfo {
    string id; // car number
    int i_h = -1; // start hour
    int i_m = -1; // start min
    int o_h = 23;
    int o_m = 59;
};

map<string, ParkingInfo> parkedList;

int countTime(string id) {
    auto item = parkedList.find(id)->second;
    int min = item.o_m - item.i_m;
    if (min < 0) {
        min += 60;
        item.o_h--;
    }
    int hour = item.o_h - item.i_h;
    return min + hour * 60;
}

int calcFee(int time) {
    int result = 0;
    time -= MIN_TIME;
    result += MIN_FEE;
    if (time > 0) {
        int units = time / TIME_UNIT;
        if (time % TIME_UNIT != 0) {
            units++;
        }
        result += units * FEE_UNIT;
    }
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    MIN_TIME = fees[0];
    MIN_FEE = fees[1];
    TIME_UNIT = fees[2];
    FEE_UNIT = fees[3];

    for (auto rec: records) {
        ParkingInfo info;
        info.id = rec.substr(6, 4);
        auto item = parkedList.find(info.id);
        if (item == parkedList.end()) { // if ("IN" == rec.substr(11)) {
            info.i_m = std::stoi(rec.substr(3, 2));
            info.i_h = std::stoi(rec.substr(0, 2));
            parkedList.insert({info.id, info});
        } else {  // if ("OUT" == rec.substr(11)) {
            item->second.o_h = std::stoi(rec.substr(0, 2));
            item->second.o_m = std::stoi(rec.substr(3, 2));
            if (res.find(info.id) == res.end()) {
                res.insert({info.id, countTime(info.id)});
            } else {
                res.find(info.id)->second += countTime(info.id);
            }
            parkedList.erase(info.id);
        }
    }
    for(auto a:parkedList) {
        if (res.find(a.first) == res.end()) {
            res.insert({a.first, countTime(a.first)});
        } else {
            res.find(a.first)->second += countTime(a.first);
        }
    }

    vector<int> answer;
    for (auto a: res) {
        answer.push_back(calcFee(a.second));
    }
    return answer;
}
