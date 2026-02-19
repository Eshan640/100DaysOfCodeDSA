int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int currMax = 0, maxSum = nums[0];
    int currMin = 0, minSum = nums[0];
    
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
        
        // Kadane for maximum subarray
        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(maxSum, currMax);
        
        // Kadane for minimum subarray
        currMin = min(nums[i], currMin + nums[i]);
        minSum = min(minSum, currMin);
    }
    
    // If all numbers are negative, return maxSum
    if (maxSum < 0)
        return maxSum;
    
    // Otherwise, return max of normal subarray and circular subarray
    return max(maxSum, totalSum - minSum);
}
