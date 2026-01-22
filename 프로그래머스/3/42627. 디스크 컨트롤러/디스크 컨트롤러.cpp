#include<bits/stdc++.h>

using namespace std;
struct Job{
    int idx;
    int req;
    int time;
    
    Job(int idx, int req, int time) : idx(idx), req(req), time(time){}  
    // 작업의 소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것 순
    // 올림차순, 올림차순, 올림차순
    bool operator < (const Job & a) const {
        if(time == a.time){
            if(req == a.req){
                return idx > a.idx;
            }
            return req > a.req;
        }
        return time > a.time;
    }
};

bool cmp(vector<int> & a, vector<int> & b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int now = 0;
    int i = 0; 
    
    sort(jobs.begin(), jobs.end(), cmp);
    priority_queue<Job> pq;
    
    while(i < jobs.size() || !pq.empty()){
        // 이전에 도착한 요청들 대기큐에 집어넣기
        while(i < jobs.size() && now >= jobs[i][0]){
            pq.push(Job(i, jobs[i][0], jobs[i][1]));
            i++;
        }
        
        if(!pq.empty()){
            Job curr = pq.top();
            pq.pop();
            now += curr.time;
            answer += (now - curr.req);
        }else{
            now++;
        }
    }
    
    answer = answer / jobs.size();
    return answer;
}