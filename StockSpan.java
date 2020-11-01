// Stock span problem - stack application

import java.util.*;

class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0){
            int n = sc.nextInt();

            int[] a = new int[n];

            for (int i = 0; i < n; i++){
                a[i] = sc.nextInt();
            }

            solve(a);
        }
    }

    static void solve(int[] a){
        int[] span = new int[a.length];

        Stack<Integer> stack = new Stack<>();

        span[0] = 1;
        stack.push(0);

        for (int i = 1; i < a.length; i++){
            while (!stack.empty() && a[stack.peek()] <= a[i]){
                stack.pop();
            }
            if (stack.empty()){
                span[i] = i + 1;
            } else {
                span[i] = i - stack.peek();
            }
            stack.push(i);
        }

        display(span);
    }

    static void display(int[] span){
        for (int i = 0; i < span.length; i++){
            System.out.print(span[i] + " ");
        }
        System.out.println();
    }
}
