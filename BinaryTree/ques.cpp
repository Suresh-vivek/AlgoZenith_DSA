

#include<bits/stdc++.h>
using namespace std;


int checkPerfectSquare(int N){
        // code here 
        
        int i=1;
        
        while(i*i <= N){
            
            if(i*i ==N){
                return 1;
            }
            i++;
        }
        
        return 0;
    }

https://www.linkedin.com/in/itzvivek/
int main(){

      int arr[] = {2, 4, 7 , 16, 21 ,25};

      for(int i= 0 ;i < 6;i++){
        if(checkPerfectSquare(arr[i])){
                cout<<arr[i] <<endl;
        }
      }

}