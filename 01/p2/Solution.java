// Advent of Code 2021 day 1
// https://adventofcode.com/2021/day/1

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Solution {
    public static int solution(List<Integer> depths) {
        int increases = 0;
        int previous_sum = 0;
        for (int i = 0; i < depths.size() - 3; i++) {
            int sum = depths.get(i) + depths.get(i + 1) + depths.get(i + 2);
            if (previous_sum < sum) {
                increases++;
            }
            previous_sum = sum;
        }

        return increases;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> input = new ArrayList<>();

        while (scanner.hasNextLine()) {
            input.add(Integer.parseInt(scanner.nextLine()));
        }

        System.out.println(solution(input));
    }
}
