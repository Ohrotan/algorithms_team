#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct Record {
    string time;
    int inOrOut;
};

int calcTimeDiff(string in, string out) {
    int ret = 0; 
    
    int inHour = 0; 
    int inMinute = 0;
    int outHour = 0; 
    int outMinute = 0;
    
    try {
        inHour = stoi(in.substr(0,2));
        inMinute = stoi(in.substr(3,2));
        outHour = stoi(out.substr(0,2));
        outMinute = stoi(out.substr(3,2));
    } catch(...) {
    }
    
    ret = (60 * outHour + outMinute) - (60 * inHour + inMinute);
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> temp;
    unordered_map<string, vector<Record>> recordMap;
    
    
    for(auto &&e : records) {
        string carNumber = e.substr(6,4); 
        string time = e.substr(0,5);
        int inOrOut = e.substr(11,1) == "I" ? 0 : 1;
        
        Record tempRecord;
        tempRecord.time = time;
        tempRecord.inOrOut = inOrOut;
        
        recordMap[carNumber].push_back(tempRecord);
    }
    
    for(auto &&e : recordMap) {
        int totalFee = 0;
        int totalTime = 0;
        if(e.second.size() % 2 == 1) {
            e.second.push_back({"23:59", 1});    
        }
        
        for(int i = 0; i < e.second.size(); i += 2) {
            totalTime += calcTimeDiff(e.second.at(i).time, e.second.at(i + 1).time);
        }
        
        totalFee = fees.at(1);
        
        if(totalTime > fees.at(0)) {
            totalFee += ceil((double)(totalTime - fees.at(0)) / fees.at(2)) * fees.at(3);
        }
        
        cout << "totalFee = " << totalFee << endl;
        
        temp.push_back({e.first, totalFee});
    }
    
    sort(temp.begin(), temp.end());
    for(auto &&e : temp) {
        answer.push_back(e.second);
    }
       
    return answer;
}
