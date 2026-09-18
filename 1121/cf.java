import java.util.*;

public class cf{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n=sc.nextInt();
            int m=sc.nextInt();
            int[] a=new int[n];
            for(int i=0;i<n;i++){
                a[i]=sc.nextInt();
            }
            int[] ma=new int[n];
            if(n==1){
                System.out.println(a[0]);
                continue;
            }
            ma[n-1]=a[n-1];
            // ma[n-2]=a[n-2];
            for(int i=n-2;i>=0;i--){
                ma[i]=Math.max(ma[i+1],a[i]);
            }
            PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());
            int ans=Integer.MIN_VALUE;
            for(int i=0;i<n-1;i++){
                pq.add(a[i]);
                if(pq.size()==m-1){
                    int sum=0;
                    for(int x:pq){
                        sum+=x;
                    }
                    ans=Math.max(ans,(-1)*(sum)+m*ma[i+1]);
                    
                }else if(pq.size()>m-1){
                    pq.poll();
                    int sum=0;
                    for(int x:pq){
                        sum+=x;
                    }
                    ans=Math.max(ans,(-1)*(sum)+m*ma[i+1]);
                }
            }
            System.out.println(ans);
        }
    }
}