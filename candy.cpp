#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii > vii;
typedef vector<int> vi;
class Solution {
public:

    int augment(int cIndex, vector<int> &ratings, vi &candies){
        int n = 1;
        if(cIndex > 0 && cIndex < (ratings.size() - 1)){
            int m1 = ratings[cIndex - 1] == ratings[cIndex] ? 1 : candies[cIndex - 1] + 1;
            int m2 = ratings[cIndex + 1] == ratings[cIndex] ? 1 : candies[cIndex + 1] + 1;
            n = max(m1, m2);
        }else if(cIndex > 0){
            int m1 = ratings[cIndex - 1] == ratings[cIndex] ? 1 : candies[cIndex - 1] + 1;
            n = m1;
        }else if(cIndex < (ratings.size() - 1)){
            int m2 = ratings[cIndex + 1] == ratings[cIndex] ? 1 : candies[cIndex + 1] + 1;
            n = m2;
        }

        return n;
    }

    int candy(vector<int> &ratings) {
        vector<ii > rankSort(ratings.size());
        int totalcandies = 0;
        vi candies(ratings.size(), 0);
        int index = 0;
        for(vi::iterator it = ratings.begin(); it != ratings.end(); ++it){
            rankSort[index] = ii(*it, index);
            index ++;
        }
        sort(rankSort.begin(), rankSort.end(), less<ii >());
        
        for(vii::iterator it = rankSort.begin(); it != rankSort.end(); ++it){
            candies[it->second] = augment(it->second, ratings, candies);
            totalcandies += candies[it->second];
            
        }
        return totalcandies;
    }

};

int main() {
    Solution s;
    vi t;
    t.push_back(2);
    t.push_back(2);
    printf("%d\n",s.candy(t));
}