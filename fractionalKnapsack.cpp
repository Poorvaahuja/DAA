#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
class Item{
    public:
    int value;
    int weight;
};
//sort in decreasing order
static bool cmp(pair<pair<double,Item>,int> &a, pair<pair<double,Item>,int>
b){
    return a.first.first>b.first.first;
}
vector<double> fractionalKnapsack(int n, Item arr[],int capacity){
    vector<double> ans(n,0);
    // {per unit value, item store}, index }
    vector<pair<pair<double,Item>,int>> vec;
    for(int i=0;i<n;i++){
        int perUnitValue=(1.0* arr[i].value/arr[i].weight);
        vec.push_back({{perUnitValue,arr[i]},i});
    }
    sort(vec.begin(),vec.end(),cmp);
    int i=0;
    while(capacity){
        if(vec[i].first.second.weight<capacity){
            capacity-=vec[i].first.second.weight;
            ans[vec[i].second]=1;
        }
        else if(vec[i].first.second.weight>=capacity){
            ans[vec[i].second]=(1.0*capacity/vec[i].first.second.weight);
            capacity=0;
            break;
        }
        i++;

    }
    return ans;
}

int main(){
    Item arr[100];
    int item,capacity;
    cout<<"Enter the no of items"<<endl;
    cin>>item;

    for(int i=0;i<item;i++){
        cout<<"Enter the value and weight of item "<<i+1;
        cin>>arr[i].value>>arr[i].weight;
    }
    cout<<"Enter the capacity of the Knapsack";
    cin>>capacity;

    vector<double> sum=fractionalKnapsack(item,arr,capacity);
    double sum1=0;
    cout<<"The fraction of each item taken"<<endl;
    for(int i=0;i<item;i++){
        cout<<i+1<<"--->"<<sum[i]<<endl;
        sum1+=sum[i]*arr[i].value;
    }
    cout<<"The total value is "<<sum1;
}
