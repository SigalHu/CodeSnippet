#include <algorithm>
using namespace std;

// 冒泡排序
void bubble_sort(int *arr,int len){
    if(arr==nullptr || len <= 0)
        return;
    for(int ii=len-1;ii>0;--ii){
        for(int jj=0;jj<ii;++jj){
            if(arr[jj]>arr[jj+1])
                swap(arr[jj],arr[jj+1]);
        }
    }
}

// 改进冒泡排序
void bubble_sort2(int *arr,int len){
    if(arr==nullptr || len <= 0)
        return;
    for(int ii=len-1,ii_tmp;ii>0;ii=ii_tmp){
        ii_tmp = 0;
        for(int jj=0;jj<ii;++jj){
            if(arr[jj]>arr[jj+1]){
                swap(arr[jj],arr[jj+1]);
                ii_tmp = jj;
            }
        }
    }
}

// 双向冒泡排序
void bubble_sort3(int *arr,int len){
    if(arr==nullptr || len <= 0)
        return;
    for(int ii=len-1,ii_min=0,ii_tmp;ii>ii_min;){
        ii_tmp = 0;
        for(int jj=0;jj<ii;++jj){
            if(arr[jj]>arr[jj+1]){
                swap(arr[jj],arr[jj+1]);
                ii_tmp = jj;
            }
        }
        ii = ii_tmp;
        for(int jj=ii-1;jj>=ii_min;--jj){
            if(arr[jj]>arr[jj+1]){
                swap(arr[jj],arr[jj+1]);
                ii_tmp = jj;
            }
        }
        ii_min = ii_tmp;
    }
}
