#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

int pow(int x,int exp){
    int y = 1;
    for(int i=1;i<=exp;i++){
        y *= x;
    }
    return y;
}
int main(){
    int n,p=3,i=1;
    bool ctrl[12];
    int place[12]={500,200,200,100,50,20,20,10,5,2,2,1};
    cout<<"\nGive value of Rs : ";
    cin>>n;
    cout<<n<<" = ";
    // starting of loop
    for (int j=p; j >= 0; j--)
    {
        if(j>0){
            // for 5th place value -----------------------
            int a = pow(10,j)/2;
            if(n/a == 1){
                // cout<<i<<"-> 1"<<" "<<a<<endl;
                ctrl[i-1] = true;
                n = n%a;
            }else{
                // cout<<i<<"-> 0"<<" "<<a<<endl;
                ctrl[i-1] = false;
            }
            i++;

            // for 2nd place value -----------------------
            a = pow(10,j)/5;
            if(n/a == 2){
                // cout<<i<<"-> 1"<<" "<<a<<endl;
                // cout<<i+1<<"-> 1"<<" "<<a<<endl;
                ctrl[i-1] = true;
                ctrl[i] = true;
                n = n%a;
            }else if(n/a == 1){
                // cout<<i<<"-> 0"<<" "<<a<<endl;
                // cout<<i+1<<"-> 1"<<" "<<a<<endl;
                ctrl[i-1] = false;
                ctrl[i] = true;
                n = n%a;
            }else{
                // cout<<i<<"-> 0"<<" "<<a<<endl;
                // cout<<i+1<<"-> 0"<<" "<<a<<endl;
                ctrl[i-1] = false;
                ctrl[i] = false;
                n = n%a;
            }
            i += 2;

            // for 1st place value -----------------------
            a = pow(10,j-1);
            if(n/a == 1){
                // cout<<i<<"-> 1"<<" "<<a<<endl;
                ctrl[i-1] = true;
                n = n%a;
            }else{
                // cout<<i<<"-> 0"<<" "<<a<<endl;
                ctrl[i-1] = false;
            }
            i++;
        }
        else{
            // for place value of 1 -----------------------
            if(n == 1){
                // cout<<i<<"-> 1"<<" "<<1<<endl;
                ctrl[i-1] = true;
            }
        }
        
    }
    
    for(int k=0; k<12; k++){
        // cout<<ctrl[k]<<endl;
        if(ctrl[k]){
            cout<<place[k];
            if(k<11){
                cout<<"+";
            }else cout<<endl;
        }
    }
    
    return 0;
}