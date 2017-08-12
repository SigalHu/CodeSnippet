//#include <iostream>
//#include "gtest.h"
#include <vector>
using namespace std;

// 归并排序
void merge(int *arr, int start, int end) {
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    merge(arr, start, mid);
    merge(arr, mid + 1, end);
    vector<int> tmp;
    tmp.reserve(end - start + 1);
    int ii = start, jj = mid + 1;
    while (ii <= mid || jj <= end) {
        if (ii <= mid && jj <= end) {
            if (arr[ii] < arr[jj]) {
                tmp.emplace_back(arr[ii++]);
            } else {
                tmp.emplace_back(arr[jj++]);
            }
        } else if (ii <= mid) {
            tmp.emplace_back(arr[ii++]);
        } else {
            tmp.emplace_back(arr[jj++]);
        }
    }
    for (int &aa:tmp) {
        arr[start++] = aa;
    }
}

void merge_sort(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;;
    merge(arr, 0, len - 1);
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