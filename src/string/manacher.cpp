#include <string>
#include <vector>
using namespace std;

// Manacher 算法
// 功能：给定一个字符串，求它的最长回文子串长度
int manacher(string str) {
    int max_loc = str.size() * 2;

    // 初始化字符串
    string str1(max_loc + 1, '#');
    for (int ii = str.size() - 1; ii >= 0; --ii) {
        str1[2 * ii + 1] = str[ii];
    }

    // 遍历字符串
    vector<int> len(max_loc + 1, 1);
    int max_len = 1;
    for (int ii = 1, jj, pos = 0, max_right = 1; ii < str1.size(); ii++) {
        if (ii - pos >= max_right) {
            for (; ii + len[ii] < str1.size() && ii - len[ii] >= 0; len[ii]++) {
                if (str1[ii + len[ii]] != str1[ii - len[ii]])
                    break;
            }
            pos = ii;
            max_right = len[ii];
            max_len = max(max_right, max_len);
        } else {
            jj = pos - (ii - pos);
            if (jj - len[jj] <= pos - max_right) {
                for (len[ii] = pos + max_right - ii; ii + len[ii] < str1.size() && ii - len[ii] >= 0; len[ii]++) {
                    if (str1[ii + len[ii]] != str1[ii - len[ii]])
                        break;
                }
                pos = ii;
                max_right = len[ii];
                max_len = max(max_right, max_len);
            } else {
                len[ii] = len[jj];
            }
        }
    }
    return max_len - 1;
}