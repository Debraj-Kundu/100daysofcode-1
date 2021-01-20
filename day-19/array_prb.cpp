#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Subarray equal to sum
 */
vector<int> subarraySum(int arr[], int n, int s){
  int curr_sum = arr[0];
  int start=0, end=0;
  while(end < n){
    if(curr_sum == s){
      return {start+1, end+1};
    }
    if(curr_sum < s){
      curr_sum += arr[++end];
    }
    if(curr_sum > s){
      curr_sum -= arr[start];
      start++;
    }
  }
  return {-1};
}

int main() {
	
	
	return 0;
}