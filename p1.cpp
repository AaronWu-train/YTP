#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int ax1, ax2, ax3,ay1, ay2, ay3, bx1,bx2,bx3 , by1, by2, by3;
    int q;
    cin>>ax1>>ay1>>ax2>>ay2>>ax3>>ay3>>bx1>>by1>>bx2>>by2>>bx3>>by3>>q;
    vector<int> a(3);
    vector<int> b(3);
    a[0]=abs(ax1-ax2)*abs(ax1-ax2)+abs(ay1-ay2)*abs(ay1-ay2);
    a[1]=abs(ax2-ax3)*abs(ax2-ax3)+abs(ay2-ay3)*abs(ay2-ay3);
    a[2]=abs(ax1-ax3)*abs(ax1-ax3)+abs(ay1-ay3)*abs(ay1-ay3);
    b[0]=abs(bx1-bx2)*abs(bx1-bx2)+abs(by1-by2)*abs(by1-by2);
    b[1]=abs(bx2-bx3)*abs(bx2-bx3)+abs(by2-by3)*abs(by2-by3);
    b[2]=abs(bx1-bx3)*abs(bx1-bx3)+abs(by1-by3)*abs(by1-by3);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> s(3);
    while(q--){
        int qx1, qx2, qx3,qy1, qy2, qy3;
        cin>>qx1>>qy1>>qx2>>qy2>>qx3>>qy3;
        s[0]=abs(qx1-qx2)*abs(qx1-qx2)+abs(qy1-qy2)*abs(qy1-qy2);
        s[1]=abs(qx2-qx3)*abs(qx2-qx3)+abs(qy2-qy3)*abs(qy2-qy3);
        s[2]=abs(qx1-qx3)*abs(qx1-qx3)+abs(qy1-qy3)*abs(qy1-qy3);
        sort(s.begin(), s.end());
        bool isa=true, isb=true;
        for(int r=0; r<3; r++){
            if(a[r]!=s[r]) isa=false;
            if(b[r]!=s[r]) isb=false;
        }
        if(isa) cout<<"Nijika"<<'\n';
        else if(isb) cout<<"Doritos"<<'\n';
        else cout<<"None"<<'\n';
    }
}