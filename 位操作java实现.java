public class Main {
    public static  int count1(int n){
        int res=0;
        while(n!=0){
            res+=n&1;
            n>>>=1;
        }
        return res;
    }
    public static int count2(int n){
        int res=0;
        while(n!=0){
            n&=(n-1);
            res++;
        }
        return res;
    }
    public static void main(String[] args) {
        System.out.println("Hello World!");
        int n=7;
        System.out.println(count1(n));
    }
}