#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Job{
    public:
    int id;
    int dead;
    int profit;
};
static bool cmp(Job a, Job b){
    return a.profit>b.profit;

}
vector<int> jobSeq(Job arr[],int n, int &profitt){

    int maxDeadline=INT_MIN;
    for(int i=0;i<n;i++){
        maxDeadline=max(maxDeadline,arr[i].dead);
    }
    sort(arr,arr+n,cmp);
    // making schedule array - size will be equal to max deadline
    // 1 based indexing
    vector<int> schedule(maxDeadline+1,-1);
    int maxProfit=0;
    for(int i=0;i<n;i++){
        int currID = arr[i].id;
        int currProfit = arr[i].profit;
        int currDead = arr[i].dead;
        for(int k = currDead;k>0;k--){
            if(schedule[k] == -1){
                schedule[k]=currID;
                maxProfit+=currProfit;
                break;
            }
        }
    }
    profitt=maxProfit;
    return schedule;

}
int main(){
    cout<<"Enter the number of jobs";
    int n;
    cin>>n;
    Job arr[100];
    for(int i=0;i<n;i++){
        int ID,deadline,p;
        cout<<"Enter the id, deadline and profit corresponding to the job"<<i+1<<" ";
        cin>>ID>>deadline>>p;

        arr[i].dead=deadline;
        arr[i].profit=p;
        arr[i].id=ID;
    }
    int profitt=0;
    vector<int> schedule=jobSeq(arr,n,profitt);
    cout<<"The corresponding deadline and teh schedule for it is "<<endl;
    for(int i=1;i<schedule.size();i++){
    cout<< i<<"--->"<<"Job "<<schedule[i]<<endl;
    }
    cout<<"Profit earned : "<<profitt;
    return 0;
}
