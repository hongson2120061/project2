#include <iostream>
#include <string>
#include<math.h>
using namespace std;
//so nguyen to
bool prime2(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return n>1;
}
/////////////////////////
//sang so nnguyen to
int prime[10000];
void sieve(int n){
    for(int i=0;i<=n;i++){
        prime[i]=1;
    }
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<=sqrt(n);i++){
        for(int j=i+i;j<=n;j+=i){
            prime[j]=0;
        }
    }
}
/////////////////////////////////////////////
//sang so tren doan a,b
int max(int a,int b){
    if(a>b)return a;
    return b;
}
void sang(int left,int right){
    int prime[right-left+1];
    for(int i=0;i<=right-left;i++){
        prime[i]=1;
    }
    for(int i=2;i<=sqrt(right);i++){
        for(int j=max(i*i,(left+1-i)/i*i);j<=right;j+=i){
            prime[j-left]=0;
        }
    }
    for(int i=max(left,2);i<=right;i++){
        if(prime[i-left])
        printf("%d ",i);
    }
}
//////////////////////////////////////////////////////
//xet chu so cuoi cung co phai la si nguyen to hay khong 
int digitalprime(int n){
    while(n){
        int r=n%10;
        if(r!=2&&r!=3&&r!=5&&r!=7)return 0;
        n/=10;
    }
    return 1;
}
////////////////////////////////////////////////////////
//mot so bang tong cua mot cap so nguyen to nao do
void capsonguyento(int n){
    for(int i=2;i<=n/2;i++){
        if( prime[i]&&prime[n-i]) cout<<i<<"  "<<n-i<<"\n";
    }
}
/////////////////////////////////////////////////////
///so dong nguyen to
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void sodongnguyento(int a,int b){
    for(int i=a;i<b;i++){
        for(int j=i+1;j<=b;j++){
            // cout<<gcd(i,j)<<endl;
            if(gcd(i,j)==1) cout<<"("<<i<<","<<j<<")"<<endl;
        }
    }
}
//////////////////////////////////////////////////////////////////
/////so co 3 uoc so la so binh phuong cua mot so nguyen to
void soco3uoc(int n){
    sieve(n);
    for(int i=1;i<=sqrt(n);i++){
        if(prime[i])cout<<i*i<<endl;
    }
}

//////////////////////////////////////////////////////////////////
/////so co 3 uoc so la so binh phuong cua mot so nguyen to tren doan a,b
void so3uoctrendoan(int left,int right){
    sieve(right-left+1);
    int count=0;
    int a=sqrt(left);
    if(1ll*a*a!=left)a++;
    for(int i=a;i<=sqrt(right);i++){
        if(prime[i])count++;
    }
    cout<<count;
}
/////////////////////////////////////
//tim uoc la so nguyen to nho nhat
//cach1
int timuoclasonguyentonhonhat(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return i;
    }
    return n;
}
//cach 2
int prime[1000001];
void timuoclasonguyentonhonhatcach2(int n){
    for(int i=1;i<=n;i++){
        prime[i]=i;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(prime[j]==j){
                    prime[j]=i;
                }
            }
        }
    }
}
//////////////////////////////
//phan tich thua so nguyen to
void phantichthuasonguyento(int n){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            cout<<i<<"  ";
            n/=i;
        }
    }
    if(n!=1)cout<<n;
}
//////////////////////////////
//chi in mot lan
void phantichthuasonguyento(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<i<<"  ";
            while(n%i==0){            
                n/=i;
            }
        }
    }
    if(n!=1)cout<<n;
}
//////////////////////////////


void phantichthuasonguyento1(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            // cout<<i<<"  ";
            int count=0;
            while(n%i==0){            
                count++;
                n/=i;
            }
            cout<<i<<"("<<count<<")"<<" ";
        }
    }
    if(n!=1){
        cout<<n<<"(1)";
    }
}

//////////////////////////////
void phantichthuasonguyento3(int n){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            cout<<i;
            n/=i;
            if(n!=1) cout<<"x";
        }
    }
    if(n!=1)cout<<n;
}



int main(){
    int n=100;
    sieve(n);
    for(int i=0;i<=n;i++){
        if(prime[i]) cout<<i<<"  ";
    }
    return 0;
}