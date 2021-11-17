#include <bits/stdc++.h>
using namespace std;

double n, m, p, q;

int main(){
    cin >> n >> m >> p >> q;

    bool done = false;
    double slope = q/(n-p);
    for(double k=1;k<=1000000&&!done;k++){
        double y = slope*((k*n)-p);
        double x = (k*m)/slope+p;
        double numheight = (int)((y-(m/2))/m)+1;
        double numwidth = (int)((x-(n/2))/n)+1;
        double a = numheight*m;
        double b = numwidth*n;
        double bounce;
        if(abs(a-y) < 5 || abs(b-x) < 5){
            if(abs(a-y) < 5){
                if(a != y) bounce = k-1+(int)(y/m);
                else bounce = k-1+(int)(y/m)-1;
            }else{
                if(b != x) bounce = k-1+(int)(x/n);
                else bounce = k-1+(int)(x/n)-1;
            }
            cout << bounce;
            done = true;
        }
    }
    if(!done) cout << 0;
}