public class Main {
    public static void main(String[] args) {
        int[] array = {0, 3, 0, 2, 0, 4, 0, 1};
        moveZeros(array);
        for (int num : array) {
            System.out.print(num + " ");
        }
    }

    public static void moveZeros(int[] nums) {
        int ind = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[ind++] = num;
            }
        }
        while (ind < nums.length) {
            nums[ind++] = 0;
        }
    }
}
