import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s="";
        try{
            s = bf.readLine();
        }
        catch(Exception e){}
        int i, cont=0, buk[] = new int[3];
        for(i=0; i<s.length(); i++){
            if(s.charAt(i)-'0'>=0){
                buk[s.charAt(i)-'0'-1]++;
                cont++;
            }
        }
        for(i=0; i<3; i++){
            while(buk[i]-->0){
                System.out.printf("%d", i+1);
                cont--;
                if(cont>=1) System.out.print("+");
            }
        }
    }
    
}
