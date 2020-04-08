
import java.io.BufferedReader;
import java.io.File;import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDate;
import java.util.Scanner;

class Main {

    public static void main(String[] args){
        //BufferedReader bf = new BufferedReader(new FileReader(new File("in.txt")));
        //PrintWriter out = new PrintWriter("out.txt");
        Scanner sc = new Scanner(System.in);
        int cases = Integer.parseInt(sc.nextLine());
        for(int i=1; i<=cases; i++){
            String fechaS = sc.nextLine();
            int m = Integer.parseInt("" + fechaS.charAt(0) + fechaS.charAt(1));
            int d = Integer.parseInt("" + fechaS.charAt(2) + fechaS.charAt(3));
            int y = Integer.parseInt("" + fechaS.charAt(4) + fechaS.charAt(5) + fechaS.charAt(6) + fechaS.charAt(7));
            LocalDate fecha = LocalDate.of(y, m, d);
            fecha = fecha.plusWeeks(40);
            y = fecha.getYear();
            m = fecha.getMonthValue();
            d = fecha.getDayOfMonth();
            String signo = getSigno(d, m);
            System.out.println(String.format("%d %s/%s/%d %s", i, (m>9 ? ""+m : "0"+m), (d>9 ? ""+d : "0"+d), y, signo));
        }
    }

    static String getSigno(int d, int m) {
        String signo="";
        if ((m == 1 && (d >= 1 && d <= 20))) {
            signo = "capricorn";
        }
        if ((m == 1 && (d >= 21 && d <= 31))) {
            signo = "aquarius";
        }
        if ((m == 2 && (d >= 1 && d <= 19))) {
            signo = "aquarius";
        }
        if ((m == 2 && (d >= 20 && d <= 31))) {
            signo = "pisces";
        }
        if ((m == 3 && (d >= 1 && d <= 20))) {
            signo = "pisces";
        }
        if ((m == 3 && (d >= 21 && d <= 31))) {
            signo = "aries";
        }
        if ((m == 4 && (d >= 1 && d <= 20))) {
            signo = "aries";
        }
        if ((m == 4 && (d >= 21 && d <= 31))) {
            signo = "taurus";
        }
        if ((m == 5 && (d >= 1 && d <= 21))) {
            signo = "taurus";
        }
        if ((m == 5 && (d >= 22 && d <= 31))) {
            signo = "gemini";
        }
        if ((m == 6 && (d >= 1 && d <= 21))) {
            signo = "gemini";
        }
        if ((m == 6 && (d >= 22 && d <= 31))) {
            signo = "cancer";
        }
        if ((m == 7 && (d >= 1 && d <= 22))) {
            signo = "cancer";
        }
        if ((m == 7 && (d >= 23 && d <= 31))) {
            signo = "leo";
        }
        if ((m == 8 && (d >= 1 && d <= 21))) {
            signo = "leo";
        }
        if ((m == 8 && (d >= 22 && d <= 31))) {
            signo = "virgo";
        }
        if ((m == 9 && (d >= 1 && d <= 23))) {
            signo = "virgo";
        }
        if ((m == 9 && (d >= 24 && d <= 31))) {
            signo = "libra";
        }
        if ((m == 10 && (d >= 1 && d <= 23))) {
            signo = "libra";
        }
        if ((m == 10 && (d >= 24 && d <= 31))) {
            signo = "scorpio";
        }
        if ((m == 11 && (d >= 1 && d <= 22))) {
            signo = "scorpio";
        }
        if ((m == 11 && (d >= 23 && d <= 31))) {
            signo = "sagittarius";
        }
        if ((m == 12 && (d >= 1 && d <= 22))) {
            signo = "sagittarius";
        }
        if ((m == 12 && (d >= 23 && d <= 31))) {
            signo = "capricorn";
        }
        return signo;
    }
}
