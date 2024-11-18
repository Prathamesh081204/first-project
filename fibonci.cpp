#include<iostream>
using namespace std ;

int fibi(int n){
    if(n < 2){
        return 1 ;
    }

    return fibi(n-2)+fibi(n-1) ;
}
int main(){

    int n ;
    cin>> n ;

    for(int i =0 ; i<n ;i++){
        cout<< fibi(i)<<endl ;
    }

    return 0 ;
}