import java.time.LocalDate;
import java.util.Scanner;
public class Main {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int cases = Integer.parseInt(sc.nextLine());
        int i;
        for(i=0; i<cases; i++){
            System.out.print("Case #" + (i+1) + ": ");
            String date1 = sc.nextLine();
            if(date1.equals("")){
                date1=sc.nextLine();
            }
            String date2 = sc.nextLine();
            LocalDate lDate1=localDateFromString(date1);
            LocalDate lDate2=localDateFromString(date2);
            long days = java.time.temporal.ChronoUnit.DAYS.between(lDate2, lDate1);
            long years = java.time.temporal.ChronoUnit.YEARS.between(lDate2, lDate1);
            if(days<0){
                System.out.println("Invalid birth date");
            }
            else if(years>130){
                System.out.println("Check birth date");
            }
            else{
                System.out.println(years);
            }
        }
    }
    public static LocalDate localDateFromString(String str){
        String[] nums=str.split("/");
        int year=Integer.parseInt(nums[2]);
        int month=Integer.parseInt(nums[1]);
        int day=Integer.parseInt(nums[0]);
        return LocalDate.of(year, month, day);
    }
}
