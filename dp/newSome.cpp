// // #include<bits/stdc++.h>
// // using namespace std;

// // void setIO(string name = "") {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);
// //     if (name.size()) {
// //         freopen((name + ".in").c_str(), "r", stdin);
// //         freopen((name + ".out").c_str(), "w", stdout);
// //     }
// // }


// // struct Rect {
// //     long long x1, y1, x2, y2;
// // };

// // int main() {
// //     setIO("check");
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int N;
// //     if (!(cin >> N)) return 0;

// //     vector<Rect> rects(N);
// //     vector<long long> xs;          // all vertical borders
// //     xs.reserve(2 * N);

// //     for (auto &r : rects) {
// //         cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
// //         xs.push_back(r.x1);
// //         xs.push_back(r.x2);
// //     }

// //     sort(xs.begin(), xs.end());
// //     xs.erase(unique(xs.begin(), xs.end()), xs.end());

// //     long long total = 0;

// //     for (size_t i = 0; i + 1 < xs.size(); ++i) {
// //         long long x_left  = xs[i];
// //         long long x_right = xs[i + 1];
// //         long long width   = x_right - x_left;
// //         if (width == 0) continue;

// //         // collect y-segments of rectangles covering this x-strip
// //         vector<pair<long long, long long>> segs;
// //         for (const auto &r : rects)
// //             if (r.x1 <= x_left && r.x2 >= x_right)
// //                 segs.emplace_back(r.y1, r.y2);

// //         if (segs.empty()) continue;

// //         sort(segs.begin(), segs.end());   // by y1

// //         // merge and compute total covered height on this strip
// //         long long covered = 0;
// //         long long curL = segs[0].first, curR = segs[0].second;
// //         for (size_t j = 1; j < segs.size(); ++j) {
// //             if (segs[j].first > curR) {   // disjoint interval
// //                 covered += curR - curL;
// //                 curL = segs[j].first;
// //                 curR = segs[j].second;
// //             } else {                      // overlap → extend
// //                 curR = max(curR, segs[j].second);
// //             }
// //         }
// //         covered += curR - curL;

// //         total += width * covered;
// //     }

// //     cout << total;
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// class rectangle {
// public:
//     int x1, y1, x2, y2;
//     rectangle() {}
//     rectangle(int a1, int b1, int a2, int b2) {
//         x1 = a1; y1 = b1;
//         x2 = a2; y2 = b2;
//     }
// };

// long long totalArea(int n, rectangle r[]) {
//     long long A = 0;

//     vector<long long> x_coords;
//     for (int i = 0; i < n; ++i) {
//         x_coords.push_back(r[i].x1);
//         x_coords.push_back(r[i].x2);
//     }

//     sort(x_coords.begin(), x_coords.end());
//     x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

//     for (size_t i = 0; i + 1 < x_coords.size(); ++i) {
//         long long x_start = x_coords[i];
//         long long x_end = x_coords[i + 1];
//         long long width = x_end - x_start;
//         if (width == 0) continue;

//         vector<pair<long long, long long>> y_segments;
//         for (int j = 0; j < n; ++j) {
//             if (r[j].x1 <= x_start && r[j].x2 >= x_end) {
//                 y_segments.emplace_back(r[j].y1, r[j].y2);
//             }
//         }

//         if (y_segments.empty()) continue;
//         sort(y_segments.begin(), y_segments.end());

//         long long height = 0;
//         long long curL = y_segments[0].first, curR = y_segments[0].second;
//         for (size_t j = 1; j < y_segments.size(); ++j) {
//             if (y_segments[j].first > curR) {
//                 height += curR - curL;
//                 curL = y_segments[j].first;
//                 curR = y_segments[j].second;
//             } else {
//                 curR = max(curR, y_segments[j].second);
//             }
//         }
//         height += curR - curL;

//         A += width * height;
//     }

//     return A;
// }

// int main() {
//     int n;
//     cin >> n;
//     rectangle r[n];
//     for (int i = 0; i < n; ++i) {
//         cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
//     }
//     cout << totalArea(n, r);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

struct Rect {
    long long x1, y1, x2, y2;
};

long long totalArea(const vector<Rect>& r) {
    vector<long long> xs;
    xs.reserve(r.size() * 2);
    for (auto& rec : r) { xs.push_back(rec.x1); xs.push_back(rec.x2); }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    long long area = 0;
    for (size_t i = 0; i + 1 < xs.size(); ++i) {
        long long xL = xs[i], xR = xs[i + 1], w = xR - xL;
        if (!w) continue;

        vector<pair<long long,long long>> seg;
        for (auto& rec : r)
            if (rec.x1 <= xL && rec.x2 >= xR)
                seg.emplace_back(rec.y1, rec.y2);

        if (seg.empty()) continue;
        sort(seg.begin(), seg.end());

        long long cov = 0, cL = seg[0].first, cR = seg[0].second;
        for (size_t j = 1; j < seg.size(); ++j)
            if (seg[j].first > cR) { cov += cR - cL; cL = seg[j].first; cR = seg[j].second; }
            else cR = max(cR, seg[j].second);


        cov += cR - cL;
        area += w * cov;
    }
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Rect> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        if (r[i].x1 > r[i].x2) swap(r[i].x1, r[i].x2);
        if (r[i].y1 > r[i].y2) swap(r[i].y1, r[i].y2);
    }
    cout << totalArea(r) << '\n';
}
