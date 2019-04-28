//package test;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static class Date{
        LocalDate lDate;
        int gap;
        public Date(int year, int month, int day){
            lDate=LocalDate.of(year, month, day);
        }
    }
    
    static class SortByDesc implements Comparator<Date>{
        public int compare(Date d1, Date d2){
            return d1.lDate.getDayOfYear()-d2.lDate.getDayOfYear();
        }
    }
    static class SortFromOct29 implements Comparator<Date>{
        public int compare(Date d1, Date d2){
            int t1=d1.lDate.getDayOfYear();
            int t2=d2.lDate.getDayOfYear();
            if(t1<=301){
                t1+=365;
            }
            if(t2<=301){
                t2+=365;
            }
            return t1-t2;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Date> dates=new ArrayList<>();
        ArrayList<Date> maxDates=new ArrayList<>();
        int i;
        int n=sc.nextInt();
        int actualMonth, actualDay;
        String tmpDate;
        for(i=0; i<n; i++){
            sc.next();
            tmpDate=sc.next();
            actualMonth=Integer.parseInt(tmpDate.split("-")[0]);
            actualDay=Integer.parseInt(tmpDate.split("-")[1]);
            Date actualDate = new Date(2014, actualMonth, actualDay);
            dates.add(actualDate);
        }
        dates.sort(new SortByDesc());
        
        int maxGap=0;
        for(i=0; i<dates.size(); i++){
            int prev=i-1;
            if(prev==-1){
                prev=dates.size()-1;
            }
            dates.get(i).gap=getGapBetween(dates.get(i).lDate, dates.get(prev).lDate);
            maxGap=maxN(maxGap, dates.get(i).gap);
            //print(dates.get(i).lDate + " gap of " + dates.get(i).gap);
        }
        for(i=0; i<dates.size(); i++){
            if(dates.get(i).gap==maxGap){
                maxDates.add(dates.get(i));
            }
        }
        maxDates.sort(new SortFromOct29());
        printDate(maxDates.get(0).lDate.minusDays(1));
        
    }
    
    public static int maxN(int n1, int n2){
        return n1>n2 ? n1 : n2;
    }
    
    public static int getGapBetween(LocalDate lDate1, LocalDate lDate2){
        if(lDate2.getDayOfYear()>lDate1.getDayOfYear()){
            return (365-lDate2.getDayOfYear())+lDate1.getDayOfYear();
        }
        return lDate1.getDayOfYear()-lDate2.getDayOfYear();
    }
    
    public static void printDate(LocalDate date){
        int day=date.getDayOfMonth();
        int month=date.getMonthValue();
        if(month<10){
            System.out.print("0");
        }
        System.out.print(month+"-");
        if(day<10){
            System.out.print("0");
        }
        System.out.print(day + "\n");
    }
    
    public static void print(Object msg){
        System.out.println(msg);
    }
    
}
