//#include <iostream>
//#include "gtest.h"
#include <vector>
using namespace std;

// 直接插入排序
void insertion_sort(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    for (int ii = 1, jj, tmp; ii < len; ++ii) {
        tmp = arr[ii];
        for (jj = ii - 1; jj >= 0 && arr[jj] > tmp; --jj) {
            arr[jj + 1] = arr[jj];
        }
        arr[jj + 1] = tmp;
    }
}

// 二分插入排序
void insertion_sort2(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    for (int ii = 1, start, end, mid, tmp; ii < len; ++ii) {
        tmp = arr[ii];
        start = 0;
        end = ii - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (arr[mid] > tmp)
                end = mid - 1;
            else
                start = mid + 1;
        }
        for (int jj = ii - 1; jj > end; --jj) {
            arr[jj + 1] = arr[jj];
        }
        arr[end + 1] = tmp;
    }
}

// 2-路插入排序
void insertion_sort3(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    vector<int> arr_tmp(len);
    arr_tmp[0] = arr[0];
    int start = 0, end = 0;
    for (int ii = 1, jj; ii < len; ++ii) {
        if (arr[ii] >= arr_tmp[end]) {
            arr_tmp[++end] = arr[ii];
        } else if (arr[ii] <= arr_tmp[start]) {
            start = (start - 1 + len) % len;
            arr_tmp[start] = arr[ii];
        } else if (arr[ii] >= arr_tmp[0]){
            ++end;
            for (jj = end-1; jj >= 0 && arr[ii] < arr_tmp[jj]; --jj) {
                arr_tmp[jj+1] = arr_tmp[jj];
            }
            arr_tmp[jj+1] = arr[ii];
        } else {
            start = (start-1+len)%len;
            for(jj=start+1;jj<len && arr[ii] > arr_tmp[jj];++jj){
                arr_tmp[jj-1] = arr_tmp[jj];
            }
            arr_tmp[jj-1] = arr[ii];
        }
    }
    for (int ii = 0; ii < len; ++ii, start = (++start) % len) {
        arr[ii] = arr_tmp[start];
    }
}

// 希尔排序
void shell_sort(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    for (int ii = len / 2, tmp; ii >= 1; ii /= 2) {
        for (int jj = 0; jj < ii; ++jj) {
            for (int mm = jj + ii, nn; mm < len; mm += ii) {
                tmp = arr[mm];
                for (nn = mm - ii; nn >= 0 && arr[nn] > tmp; nn -= ii) {
                    arr[nn + ii] = arr[nn];
                }
                arr[nn + ii] = tmp;
            }
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
//        insertion_sort3(v.data(),v.size());
//        ASSERT_EQ(true, is_sorted(v.begin(),v.end()));
//    }
//}
//
//int main(int argc, char** argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
