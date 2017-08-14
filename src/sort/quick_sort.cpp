//#include "gtest.h"
//using namespace std;

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
