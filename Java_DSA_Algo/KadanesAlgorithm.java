public class KadanesAlgorithm {
    public static int kadanesAlgorithm(int[] nums) {
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];

        for (int i = 1; i < nums.length; i++) {
            maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }

    public static void main(String[] args) {
        int[] arr = {-2, -3, 4, -1, -2, 1, 5, -3};
        int maxSubArraySum = kadanesAlgorithm(arr);
        System.out.println("Maximum subarray sum: " + maxSubArraySum); // Output: 7
    }
}
