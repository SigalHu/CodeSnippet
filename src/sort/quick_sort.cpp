//#include "gtest.h"
#include <algorithm>
#include "my_sort.h"
using namespace std;

// 快速排序（递归）
void partition(int *arr, int start, int end) {
    if (start >= end)
        return;
    int base = arr[start];
    int ii = start, jj = end;
    while (true) {
        while (ii < jj && arr[jj] >= base)
            --jj;
        if (ii == jj)
            break;
        arr[ii++] = arr[jj];

        while (ii < jj && arr[ii] < base)
            ++ii;
        if (ii == jj)
            break;
        arr[jj--] = arr[ii];
    }
    arr[ii] = base;
    partition(arr, start, ii - 1);
    partition(arr, ii + 1, end);
}

void quick_sort(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    partition(arr, 0, len - 1);
}


// 快速排序改进（三项取中）
void partition2(int *arr, int start, int end) {
    if (start >= end)
        return;
    swap(arr[start + 1], arr[(start + end) / 2]);
    if (arr[start] > arr[start + 1])
        swap(arr[start], arr[start + 1]);
    if (arr[start] > arr[end])
        swap(arr[start], arr[end]);
    if (arr[start + 1] > arr[end])
        swap(arr[start + 1], arr[end]);

    int base = arr[start + 1];
    int ii = start + 1, jj = end - 1;
    while (ii <= jj) {
        while (ii < jj && arr[jj] >= base)
            --jj;
        if (ii == jj)
            break;
        arr[ii++] = arr[jj];

        while (ii < jj && arr[ii] < base)
            ++ii;
        if (ii == jj)
            break;
        arr[jj--] = arr[ii];
    }
    arr[ii] = base;
    partition2(arr, start, ii - 1);
    partition2(arr, ii + 1, end);
}

void quick_sort2(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;
    partition2(arr, 0, len - 1);
}

// 快速排序改进
// 1. 当序列长度小于16时，使用插入排序
// 2. 减少递归次数
void partition3(int *arr,int start,int end){
    const int min_len = 16;
    int base,ii,jj;
    while (end - start > min_len){
        swap(arr[start+1],arr[(start+end)/2]);
        if(arr[start] > arr[start+1])
            swap(arr[start],arr[start+1]);
        if(arr[start] > arr[end])
            swap(arr[start],arr[end]);
        if(arr[start+1] > arr[end])
            swap(arr[start+1],arr[end]);

        base = arr[start+1];
        ii = start+1;
        jj = end-1;
        while(ii <= jj){
            while(ii < jj && arr[jj] >= base)
                --jj;
            if(ii == jj)
                break;
            arr[ii++] = arr[jj];

            while(ii < jj && arr[ii] < base)
                ++ii;
            if(ii == jj)
                break;
            arr[jj--] = arr[ii];
        }
        arr[ii] = base;
        partition3(arr,ii+1,end);
        end = ii-1;
    }
    insertion_sort2(&arr[start],end-start+1);
}

// 另一种实现
void partition33(int *arr,int start,int end){
    const int min_len = 16;
    int base,ii,jj;
    while (end - start > min_len){
        swap(arr[start+1],arr[(start+end)/2]);
        if(arr[start] > arr[start+1])
            swap(arr[start],arr[start+1]);
        if(arr[start] > arr[end])
            swap(arr[start],arr[end]);
        if(arr[start+1] > arr[end])
            swap(arr[start+1],arr[end]);

        base = arr[start+1];
        ii = start+2;
        jj = end-1;
        while(ii <= jj){
            while (arr[ii] <= base)
                ++ii;
            while (arr[jj] > base)
                --jj;
            if (ii >= jj)
                break;
            swap(arr[ii++],arr[jj++]);
        }
        partition33(arr,ii,end);
        end = jj;
    }
    insertion_sort2(&arr[start],end-start+1);
}

void quick_sort3(int *arr,int len){
    if (arr == nullptr || len <= 0)
        return;
    partition3(arr,0,len-1);
}

//class Gtest : public testing::Test {
//public:
//    vector<int> v;
//    default_random_engine random_eng;
//
//    void reset_data() {
//        uniform_int_distribution<int> random(0, 100000);
//        v.resize(10000);
//        for (int &vv:v) {
//            vv = random(random_eng);
//        }
//    }
//};
//
//TEST_F(Gtest, SortTest) {
//    for (int ii = 0; ii < 100; ii++) {
//        cout << "start testing " << ii + 1 << "..." << endl;
//        reset_data();
//        EXPECT_EQ(false, is_sorted(v.begin(), v.end()));
//        quick_sort(v.data(), v.size());
//        ASSERT_EQ(true, is_sorted(v.begin(), v.end()));
//    }
//}
//
//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
