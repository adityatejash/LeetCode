class Solution {
    boolean check (ArrayList<Integer> arr1, ArrayList<Integer> arr2) {
        if (arr1.get(arr1.size() - 1) >= arr2.get(arr2.size() - 1)) return true;

        return false;
    }

    public int[] resultArray(int[] nums) {
        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();
    
        arr1.add(nums[0]);
        arr2.add(nums[1]);

        boolean flag = check(arr1, arr2);

        for (int i=2; i<nums.length; i++) {
            if (flag) {
                arr1.add(nums[i]);
            } else {
                arr2.add(nums[i]);
            }

            flag = check(arr1, arr2);
        }

        int a=0; 

        for (int i=0; i<arr1.size(); i++) {
            nums[a++] = arr1.get(i);
        }
        for (int i=0; i<arr2.size(); i++) {
            nums[a++] = arr2.get(i);
        }

       return nums;
    }
}