import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
public class Main {
     public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BigDecimal n = new BigDecimal(Double.parseDouble(bf.readLine()));
        BigDecimal temp = new BigDecimal("0");
        int cont=1;
        temp=temp.add(n);
        temp=temp.setScale(2, BigDecimal.ROUND_HALF_EVEN);
        while(temp.compareTo(new BigDecimal("360"))!=0){
            temp=temp.add(n);
            temp=temp.setScale(2, BigDecimal.ROUND_HALF_EVEN);
            if(temp.compareTo(new BigDecimal("360"))>0){
                temp=temp.subtract(new BigDecimal("360"));
            }
            cont++;
            //System.out.println(temp);
        }
        System.out.println(cont);
     }
}
