// Given an array of N distinct elements, the task is to find all elements in array except two greatest elements.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, ele, i, j;
    vector<int> numbers; 

    cout<<"Number of test cases?\n";
    cin>>t;

    for(i = 0; i < t; i++){
        numbers.clear();
        cout<<"Test case "<<i+1<<endl;
        cout<<"Enter the number of elements"<<endl;
        cin>>n;
        if(n <= 1){
            cout<<"Not enough elements to remove\n";
            continue;
        }
        cout<<"Enter the elements\n";
        for(j = 0; j < n; j++){
            cin>>ele;
            numbers.push_back(ele);
        }
        sort(numbers.begin(), numbers.end());
        numbers.pop_back();
        numbers.pop_back();
        cout<<"The remaining elements are: "<<endl;
        if(numbers.size() == 0){
            cout<<"Array is empty";
        }
        for (int j = 0; j < numbers.size(); j++) 
        cout << numbers[j] << " "; 
        cout<<"\n";
    }

}