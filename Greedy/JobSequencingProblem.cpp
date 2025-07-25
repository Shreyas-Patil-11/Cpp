#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2 ){
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs){
    sort(jobs.begin(), jobs.end());

    int profit = jobs[0].second;
    int safeDeadline = 2;

    for (int i = 1; i < jobs.size(); i++)
    {
        if (jobs[i].first >= safeDeadline)
        {
            profit+= jobs[i].second;
            safeDeadline++;
        }
    }
    cout<< "Max Profit from jobs : " << profit<< endl;
    return profit; 
}

int main(){
    int n= 4;
    vector<pair<int, int>> jobs(n, make_pair(0,0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);
    maxProfit(jobs);
    return 0;
}