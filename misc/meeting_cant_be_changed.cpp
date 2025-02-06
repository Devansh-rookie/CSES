#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool right_max_time = false, left_max_time = false;

 double get_time( double location, vector< double> &vs, vector< double> &xs){
    // maximum time it takes to reach would be the answer\

    // if the time max from both the sides then we have reached the best position we can
    right_max_time = false, left_max_time = false;
     double timee = 0;
    int n = vs.size();
    for(int i = 0;i < n;i++){
        if(location == xs[i]) continue;
         double curr_time = abs(location - xs[i])/vs[i];
        if(curr_time > timee){
            timee = curr_time;
            right_max_time = false;
            left_max_time = false;
            if(location < xs[i]){
                right_max_time = true;
            }
            else{
                left_max_time = true;
            }
        }
        else if(curr_time == timee){
            // time = curr_time; // not needed
            if(location < xs[i]){
                right_max_time = true;
            }
            else{
                left_max_time = true;
            }
        }
    }

    return timee;
}

int main() {
    setIO("check");
    int n;
    cin >> n;

    vector< double> xs(n);
    vector< double> vs(n);
     double maxxi = 0;
    for(int i = 0;i < n;i++){
        cin >> xs[i];
        maxxi = max(maxxi, ( double)xs[i]);
    }
    for(int i = 0;i < n;i++){
        cin >> vs[i];
    }

    cout << setprecision(10);

     double ans = ( double)1e18;
     double high = maxxi;
     double low = 0;
    const  double accuracy = 10e-10;
    // or use time's binary search
    double curr_time;
    double mid;
    while(high - low > accuracy){
        mid = (high + low)/2;
        // check the distance, find the minimum time for it
        // and also check for the thing like which is farther from the actual location
        // so what we can do is if left is showing the minimum one then the issue is with the left
        // so search in the left that would be better
        //

        curr_time = get_time(mid, vs, xs);

        // if both max then best, if one is max then search in that space
        //
        ans = min(ans, curr_time);
        if(right_max_time && left_max_time){
            break;
        }
        else if(left_max_time)high = mid;
        else{
            low = mid;
        }
    }

    cout << fixed << ans;

    return 0;
}
