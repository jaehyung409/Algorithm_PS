package javaPoet.silver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class s5525 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m;
        String s;
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        s = br.readLine();
        int i = 0, ans = 0;
        for (Character c : s.toCharArray()) {
            if (i % 2 == 0 && c == 'I') {
                i++;
            } else if (i % 2 == 1 && c == 'O') {
                i++;
            } else {
                if ((i - 1) / 2 >= n) {
                    ans += ((i - 1) / 2) - n + 1;
                }
                i = c == 'I' ? 1 : 0; // Reset i based on the current character
            }
        }
        if ((i - 1) / 2 >= n) {
            ans += ((i - 1) / 2) - n + 1;
        }
        System.out.println(ans);
    }
}
