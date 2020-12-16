import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class 1462B {
    public static void main(String[] args) throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());
        StringBuffer out=new StringBuffer();
        for(int i=0; i<cases; i++){
            int n=Integer.parseInt(reader.readLine());
            String str=reader.readLine();
            boolean match=str.matches("2.*020") || 
                    str.matches("20.*20") ||
                    str.matches("202.*0") ||
                    str.matches("2020") ||
                    str.matches(".*2020") ||
                    str.matches("2020.*");
            out.append(match ? "YES" : "NO");
            out.append("\n");
        }
        System.out.println(out);
    }
}