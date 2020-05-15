package cn.az.code.other.slidewindow;

import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

/**
 * @author az
 * @date 5/14/2020
 */
public class MinimumWindowSubstring {

    public String minWindow(String s, String t) {
        // corner case
        if (s == null || t == null || s.length() == 0 || t.length() == 0 || s.length() < t.length()) {
            return "";
        }

        // construct model
        int minLeft = 0, minRight = 0;
        int min = s.length();
        boolean flag = false;

        Map<Character, Integer> map = new HashMap<>();
        // the number of characters that I need to match
        int count = t.length();
        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // unfixed sliding window, 2 pointers
        int i = 0, j = 0;
        while (j < s.length()) {
            char c = s.charAt(j);
            if (map.containsKey(c)) {
                map.put(c, map.get(c) - 1);
                if (map.get(c) >= 0) {
                    count--; // if still unmatched characters, then count--
                }
            }

            // if found a susbtring
            while (count == 0 && i <= j) {
                // update global min
                flag = true;
                int curLen = j + 1 - i;
                if (curLen <= min) {
                    minLeft = i;
                    minRight = j;
                    min = curLen;
                }

                // shrink left pointer
                char leftC = s.charAt(i);
                if (map.containsKey(leftC)) {
                    map.put(leftC, map.get(leftC) + 1);
                    if (map.get(leftC) >= 1) {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }

        return flag ? s.substring(minLeft, minRight + 1) : "";
    }
}
