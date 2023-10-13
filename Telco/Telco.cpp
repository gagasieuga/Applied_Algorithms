//C++ 
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int total_calls = 0, incorrect_call_num = 0;
map<string, int> call_time, call_num;

bool is_correct_phone(string tel){
    if(tel.length() != 10) return false;
    for (int i = 0; i < tel.length(); i++){
        if (tel[i] < '0' || tel[i] > '9') return false;
    }
    return true;
}

// hour format: 00:00:00
int duration(string start_time, string end_time){
    int start_hour = stoi(start_time.substr(0, 2));
    int start_minute = stoi(start_time.substr(3, 2));
    int start_second = stoi(start_time.substr(6, 2));
    int end_hour = stoi(end_time.substr(0, 2));
    int end_minute = stoi(end_time.substr(3, 2));
    int end_second = stoi(end_time.substr(6, 2));
    int start_total_second = start_hour * 3600 + start_minute * 60 + start_second;
    int end_total_second = end_hour * 3600 + end_minute * 60 + end_second;
    return end_total_second - start_total_second;
}
    
void input(){
    string type, from_tel, to_tel, date, start_time, end_time;
    do {
        cin >> type;
        if (type == "#") continue;
        cin >> from_tel >> to_tel >> date >> start_time >> end_time;
        if (!is_correct_phone(from_tel) || !is_correct_phone(to_tel)) {
            incorrect_call_num++;
            continue;
        }
        total_calls++;
        call_num[from_tel]++;
        call_time[from_tel] += duration(start_time, end_time);
    }
    while (type != "#");
}

void solve(){
    string type,tel;
    do{
        cin >> type;
        if(type =="#") continue;
        else if(type == "?check_phone_number") cout << (incorrect_call_num ? 0:1) << endl;
        else if(type == "?number_total_calls") cout << total_calls <<endl;
        else if(type == "?number_calls_from"){
            cin >> tel;
            cout << call_num[tel] <<endl;
        }
        else if (type == "?count_time_calls_from"){
            cin >> tel;
            cout << call_time[tel] <<endl;
        }
    }while(type != "#");
}


int main() {
    freopen("data.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}