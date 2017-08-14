//#include <iostream>
//#include "gtest.h"
#include <vector>
#include <deque>
using namespace std;

// 归并排序（递归）
void merge(int *arr, int start, int end) {
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    merge(arr, start, mid);
    merge(arr, mid + 1, end);
    if (arr[mid] <= arr[mid + 1])
        return;
    vector<int> tmp;
    tmp.reserve(end - start + 1);
    int ii = start, jj = mid + 1;
    while (ii <= mid && jj <= end) {
        if (arr[ii] < arr[jj]) {
            tmp.emplace_back(arr[ii++]);
        } else {
            tmp.emplace_back(arr[jj++]);
        }
    }
    while (ii <= mid)
        arr[--jj] = arr[mid--];
    for (int &aa:tmp) {
        arr[start++] = aa;
    }
}

void merge_sort(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;;
    merge(arr, 0, len - 1);
}

// 归并排序（非递归）
void merge_sort2(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    vector<int> tmp(len);

    for (int step = 1, start, end, mid, ii, jj, mm; step < len; step *= 2) {
        for (start = 0, end = 2 * step - 1; start < len; start = end + 1, end = start + 2 * step - 1) {
            mid = (start + end) / 2;
            if (mid + 1 < len) {
                if (arr[mid] <= arr[mid + 1])
                    continue;
                if (end >= len)
                    end = len - 1;

                ii = start;
                jj = mid + 1;
                mm = start;
                while (ii <= mid && jj <= end)
                    tmp[mm++] = arr[ii] < arr[jj] ? arr[ii++] : arr[jj++];
                while (ii <= mid)
                    arr[--jj] = arr[mid--];
                while (--mm >= start)
                    arr[mm] = tmp[mm];
            }
        }
    }
}

// 归并排序（自然合并）
void merge_sort3(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    deque<pair<int, int>> idx_que;
    for (int ii = 0, jj; ii < len; ii = jj + 1) {
        jj = ii;
        while (jj + 1 < len && arr[jj] <= arr[jj + 1])
            ++jj;
        idx_que.emplace_back(ii, jj);
    }
    int ii, jj, mm;
    vector<int> tmp(len);
    while (idx_que.size() > 1) {
        if (idx_que[0].second + 1 == idx_que[1].first) {
            ii = idx_que[0].first;
            jj = idx_que[1].first;
            mm = ii;
            while (ii <= idx_que[0].second && jj <= idx_que[1].second)
                tmp[mm++] = arr[ii] < arr[jj] ? arr[ii++] : arr[jj++];
            while (ii <= idx_que[0].second)
                arr[--jj] = arr[idx_que[0].second--];
            while (--mm >= idx_que[0].first)
                arr[mm] = tmp[mm];
            idx_que.emplace_back(idx_que[0].first, idx_que[1].second);
            idx_que.pop_front();
            idx_que.pop_front();
        } else {
            idx_que.emplace_back(idx_que.front());
            idx_que.pop_front();
        }
    }
}

//class Gtest:public testing::Test{
//public:
//    vector<int> v;
//    default_random_engine random_eng;
//    void reset_data(){
//        uniform_int_distribution<int> random(0,100000);
//        v.resize(10000);
//        for(int &vv:v){
//            vv = random(random_eng);
//        }
//    }
//};
//
//TEST_F(Gtest, SortTest){
//    for(int ii=0;ii<100;ii++){
//        cout<<"start testing "<<ii+1<<"..."<<endl;
//        reset_data();
//        EXPECT_EQ(false, is_sorted(v.begin(),v.end()));
//        merge_sort(v.data(),v.size());
//        ASSERT_EQ(true, is_sorted(v.begin(),v.end()));
//    }
//}
//
//int main(int argc, char** argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}