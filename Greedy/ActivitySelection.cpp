#include<iostream>
#include<vector>

using namespace std;

int maxActivity(vector<int> start, vector<int> end){
    //sorting on end time

    int count = 1;
    int currEndTime= end[0];
    
    for (int i = 0; i < start.size(); i++)      //overlapping cond
    {
        if (start[i] >= currEndTime)
        {
            count++;
            currEndTime = end[i];
        }
        
    }
    return count;
}

int main(){
    vector<int> start= {1,3,0,5,8,5};
    vector<int> end= {2,4,6,7,9,9};

    cout<< maxActivity(start, end)<<endl;
    return 0;
}