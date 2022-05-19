#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <map>
using namespace std;

map<string,int> park;
unordered_map<string,string> um;
int base_time, base_cost,unit_time,unit_cost;

int cal_fee(string car, int time){
    if(time <=base_time) return base_cost;
    time -= base_time;
    if(time % unit_time ==0) time /= unit_time;
    else time = time / unit_time+1;
    return base_cost + time*unit_cost;
    
}
int cal_time(string car, string in_time, string out_time){
    int hour = (stoi(out_time.substr(0,2)) - stoi(in_time.substr(0,2)))* 60;
    int min = stoi(out_time.substr(3,2)) - stoi(in_time.substr(3,2));
    return hour+min;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    base_time = fees[0];
    base_cost  = fees[1];
    unit_time  = fees[2];
    unit_cost = fees[3];
    
    for(string s : records){
        string time, car, op;
        stringstream ss(s);
        ss >> time >> car >>op;
        cout <<time << car << op <<endl;
        if(op =="OUT"){
            //해당 차량 기록이 있으면 == out
            string in_time = um[car];
            if(park.find(car) != park.end()) park[car] += cal_time(car,in_time, time);
            else park.insert(make_pair(car,cal_time(car,in_time, time)));
            um.erase(car);
        }
        else{
            //없으면 추가해주기.
            um.insert(make_pair(car, time));
        }
    }
    // 23:59로 간주할 차량들
    for(auto car : um){
        park[car.first] += cal_time(car.first, car.second,"23:59");
    }
    //계산하자~~
    for(auto car=park.begin(); car!=park.end(); car++){
        cout << car->first <<" " <<car->second <<endl;
        park[car->first] = cal_fee(car->first, car->second);
        answer.push_back(park[car->first]);
    }
    return answer;
}