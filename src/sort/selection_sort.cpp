#include <algorithm>
//#include <iostream>
//#include "gtest.h"
using namespace std;

void selection_sort(int *arr,int len){
    if(arr==nullptr || len <= 0)
        return;
    for(int ii=0,ii_min;ii<len;++ii){
        ii_min = ii;
        for(int jj=ii+1;jj<len;++jj){
            if(arr[jj] < arr[ii_min])
                ii_min = jj;
        }
        swap(arr[ii],arr[ii_min]);
    }
}

// 二元选择排序
void selection_sort2(int *arr,int len){
    if(arr==nullptr||len<=0)
        return;
    for(int ii=0,ii_min,ii_max;ii<len;++ii,--len){
        if(arr[ii] <= arr[len-1]){
            ii_min = ii;
            ii_max = len-1;
        } else {
            ii_min = len-1;
            ii_max = ii;
        }
        for(int jj=ii+1;jj<len-1;++jj){
            if(arr[jj] > arr[ii_max])
                ii_max = jj;
            else if(arr[jj] < arr[ii_min])
                ii_min = jj;
        }
        if(ii_min == len-1 && ii_max == ii)
            swap(arr[ii_max],arr[ii_min]);
        else if (ii_min == len-1){
            swap(arr[ii_min],arr[ii]);
            swap(arr[ii_max],arr[len-1]);
        } else {
            swap(arr[ii_max],arr[len-1]);
            swap(arr[ii_min],arr[ii]);
        }
    }
}

// 堆排序
void max_heap(int *arr,int len,int idx){
    if(arr== nullptr || len <= 0 || idx<0 || idx >= len)
        return;
    for(int ii=2*idx+1;ii<len;idx=ii,ii=2*idx+1){
        if(ii+1 < len && arr[ii+1] > arr[ii])
            ii++;
        if(arr[ii] > arr[idx])
            swap(arr[ii],arr[idx]);
        else
            break;
    }
}

void heap_sort(int *arr,int len){
    if(arr== nullptr || len <= 0)
        return;
    for(int ii=len/2-1;ii>=0;--ii){
        max_heap(arr,len,ii);
    }
    for(int ii=len-1;ii>0;--ii){
        swap(arr[0],arr[ii]);
        max_heap(arr,ii,0);
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

//TEST_F(Gtest, SortTest){
//    for(int ii=0;ii<100;ii++){
//        cout<<"start testing "<<ii+1<<"..."<<endl;
//        reset_data();
//        EXPECT_EQ(false, is_sorted(v.begin(),v.end()));
//        heap_sort(v.data(),v.size());
//        ASSERT_EQ(true, is_sorted(v.begin(),v.end()));
//    }
//}
//
//int main(int argc, char** argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}