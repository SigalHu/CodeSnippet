#include <iostream>
#include "gtest.h"
#include "my_sort.h"
using namespace std;

class Gtest:public testing::Test{
public:
    vector<int> v;
    default_random_engine random_eng;
    void reset_data(){
        uniform_int_distribution<int> random(0,100000);
        v.resize(10000);
        for(int &vv:v){
            vv = random(random_eng);
        }
    }
};

TEST_F(Gtest, SortTest){
    for(int ii=0;ii<100;ii++){
        cout<<"start testing "<<ii+1<<"..."<<endl;
        reset_data();
        EXPECT_EQ(false, is_sorted(v.begin(),v.end()));
        sort(v.begin(),v.end());
        quick_sort3(v.data(),v.size());
        ASSERT_EQ(true, is_sorted(v.begin(),v.end()));
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}