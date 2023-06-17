//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void generateArrays(int n, int k, vector<vector<int>>& res, vector<int> currArray, int lastElement) {
//    if (currArray.size() == k) {
//        res.push_back(currArray);
//        return;
//    }
//
//    for (int i = lastElement + 3; i <= lastElement + 4 && i <= n; i++) {
//        currArray.push_back(i);
//        generateArrays(n, k, res, currArray, i);
//        currArray.pop_back();
//    }
//}