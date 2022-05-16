#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void InCar(string carNumber, string time);
void OutCar(string carNumber, string time);
int CalculateFee(int idleTime);
int TimeToMinutes(string time);

vector<int> answer;
vector<int> fees;
unordered_map<int, int> carMap;
unordered_map<int, int> totalTime;
unordered_map<int, int> checkOutCar;
priority_queue<int, vector<int>, greater<int>> q;



vector<int> solution(vector<int> feesTemp, vector<string> records) {
    fees = feesTemp;

    for (int i = 0; i < records.size(); i++) {
        stringstream ss;
        ss.str(records[i]);
        string time; string carNumber; string state;
        getline(ss, time, ' ');
        getline(ss, carNumber, ' ');
        getline(ss, state, ' ');

        if (state == "IN") {
            InCar(carNumber, time);
        }
        else {
            OutCar(carNumber, time);
        }
    }

    while (q.size() != 0) {
        if (checkOutCar[q.top()] == 1)
            totalTime[q.top()] = totalTime[q.top()] + 23 * 60 + 59 - carMap[q.top()];

        answer.push_back(CalculateFee(totalTime[q.top()]));
        q.pop();

    }

    return answer;
}


void InCar(string carNumberString, string time) {
    int minutes = TimeToMinutes(time);
    int carNumber = stoi(carNumberString);
    if (carMap[carNumber] == 0)
        q.push(carNumber);
    carMap[carNumber] = minutes;
    checkOutCar[carNumber] = 1;
}

void OutCar(string carNumberString, string time) {
    int minutes = TimeToMinutes(time);
    int carNumber = stoi(carNumberString);

    totalTime[carNumber] = totalTime[carNumber] + minutes - carMap[carNumber];
    checkOutCar[carNumber] = 0;
}

int CalculateFee(int idleTime) {
    int payMoney = 0;
    if (idleTime <= fees[0]) {
        payMoney = fees[1];
    }
    else {
        payMoney = fees[1];
        payMoney = payMoney + (idleTime - fees[0]) / fees[2] * fees[3];

        if ((idleTime - fees[0]) % fees[2] != 0)
            payMoney = payMoney + fees[3];
    }

    return payMoney;
}


int TimeToMinutes(string time) {
    stringstream ss;
    ss.str(time);

    string hourString;
    string minuteString;

    getline(ss, hourString, ':');
    getline(ss, minuteString, ':');

    int hours = stoi(hourString);
    int minutes = stoi(minuteString);

    int totalMinutes = hours * 60 + minutes;


    return totalMinutes;
}