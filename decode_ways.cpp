#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> mem;
    vector<int> nums;

    int memory(vector<int> &s, int p){
        if(mem[p] != -1) return mem[p];
        return (mem[p] = decodeWays(s,p));
    }
    
    int decodeWays(vector<int> &s, int p){
        int ways = 0;
        
        if(p >= s.size()) return 1;
        //printf("%d %d\n", p, s.size());
        if(s[p] > 0) ways += memory(s,p+1);
        else return 0;
        
        if(p < s.size() -1){
            int secondary = s[p] * 10 + s[p+1];
            if(secondary <= 26) ways += memory(s,p+2);
        }
        
        return ways;
    }
    
    int numDecodings(string s) {
        mem.clear();
        nums.clear();
        
        mem.resize(s.size() + 5, -1);
        nums.resize(s.size());
        
        for(int i = 0; i< s.size(); ++i){
            nums[i] = s[i] - '0';
        }
        if(s.size() == 0) return 0;
        //if(nums[0] == 0) return 0;
        //printf("%d\n", decodeWays(nums, 0));
        return decodeWays(nums,0);
    }
};

int main(){
    Solution s;
    vector<string> tests;
    tests.push_back("");
    tests.push_back("0");
    tests.push_back("1");
    tests.push_back("10");
    tests.push_back("27");

    for(int i = 0; i <tests.size(); ++i)
        cout << "Test \"" << tests[i] << "\": " << s.numDecodings(tests[i]) << endl;
        //printf("%d\n", s.numDecodings(tests[i]));
    return 0;
}