#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

// Manacher 算法
// 功能：给定一个字符串，求它的最长回文子串长度
int manacher(string str){
    int min_loc = 0, max_loc = str.size()*2;
    string str1(max_loc+1,'#');
    for(int ii=str.size()-1;ii>=0;--ii){
        str1[2*ii+1] = str[ii];
    }
    vector<int> len(max_loc+1,1);
    int max_len = 0;
    for(int ii=0,right=1,max_right=0;ii<str1.size();ii++,right=1){
        while(true){
            if(ii-right<min_loc || ii+right>max_loc || str1[ii-right]!=str1[ii+right]){
                break;
            }
        }
    }
    return max_len;
}