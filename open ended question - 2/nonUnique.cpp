#include<iostream>
using namespace std;

// O(n) time, n = Range of numbers given | O(1) space
void uniqueNumbers(int L, int R){
    int array[10] = {0}; // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
    int digit;
    int flag, num;
    for(int i = L; i <= R; i++){
        flag = 0;
        num = i;
        while(num != 0){
            digit = num%10;
            num = num/10;
            if(array[digit] == 0){
                array[digit] = 1;
            }
            else{
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<i<<" ";
        }
        // Set array back to all zeroes for the next number
        for(int j = 0; j < 10; j++){
            array[j] = 0;
        }
        flag = 0;

    }
}

int main(){
    cout<<"Enter L and R\n";
    int L, R;
    cin>>L>>R;
    uniqueNumbers(L, R);
}