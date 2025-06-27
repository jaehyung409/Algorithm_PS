package javaPoet.gold;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class g9019 {
    public static int D(Integer i) {
        return (i * 2) % 10000;
    }

    public static int S(Integer i) {
        return (i + 9999) % 10000;
    }

    public static int L(Integer i) {
        return (i % 1000) * 10 + (i / 1000);
    }

    public static int R(Integer i) {
        return (i / 10) + (i % 10) * 1000;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n;
        n = Integer.parseInt(br.readLine());
        int[] trace = new int[10000];
        int[] queue = new int[10001];
        Character[] operations = new Character[10000];
        int front, rear;
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int start = Integer.parseInt(input[0]);
            int end = Integer.parseInt(input[1]);
            Arrays.fill(trace, -1); // zero handling
            front = 0;
            rear = 0;
            queue[rear++] = start;
            while (front < rear) {
                int current = queue[front++];
                if (current == end) {
                    StringBuilder result = new StringBuilder();
                    int temp = end;
                    while (temp != start) {
                        result.append(operations[temp]);
                        temp = trace[temp];
                    }
                    sb.append(result.reverse()).append("\n");
                    break;
                }
                int d = D(current);
                if (trace[d] == -1) {
                    trace[d] = current;
                    operations[d] = 'D';
                    queue[rear++] = d;
                }
                int s = S(current);
                if (trace[s] == -1) {
                    trace[s] = current;
                    operations[s] = 'S';
                    queue[rear++] = s;
                }
                int l = L(current);
                if (trace[l] == -1) {
                    trace[l] = current;
                    operations[l] = 'L';
                    queue[rear++] = l;
                }
                int r = R(current);
                if (trace[r] == -1) {
                    trace[r] = current;
                    operations[r] = 'R';
                    queue[rear++] = r;
                }
            }
        }
        System.out.print(sb);
    }
}
