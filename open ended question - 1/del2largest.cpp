// Given an array of N distinct elements, the task is to find all elements in array except two greatest elements.

// O(nlog(n)) time | O(n) space
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, ele, i, j, secondMax, max;
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
        for(j = 0; j < n; j++){
            cout<<numbers[j]<<" ";
        }

        if(numbers[0] < numbers[1]){
            secondMax = numbers[0];
            max = numbers[1];
        }
        else{
            secondMax = numbers[1];
            max = numbers[0];
        }
        cout<<"MAX: "<<max<<"  secondMAX: "<<secondMax<<endl;

        for(j = 2; j < n; j++){
            if(numbers[j] < secondMax){
                continue;
            }
            else if(numbers[j] > max){
                max = numbers[j];
            }
            else{
                secondMax = numbers[j];
            }
        }
        

        
        cout<<"The remaining elements are: "<<endl;
        if(numbers.size() == 0){
            cout<<"Array is empty";
        }
        cout<<"MAX: "<<max<<"  secondMAX: "<<secondMax<<endl;
        for(j = 0; j < n; j++){
            if(numbers[j] != secondMax && numbers[j] != max){
                cout<<numbers[j]<<" ";
            }
        }
        cout<<"\n";
    }

}