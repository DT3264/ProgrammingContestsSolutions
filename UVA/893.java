
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.time.LocalDate;
import java.time.Month;
import java.util.GregorianCalendar;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        //BufferedReader bf = new BufferedReader(new FileReader(new File("in.txt")));
        //PrintWriter out = new PrintWriter("out.txt");
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String str;
        while (true) {
            str = bf.readLine();
            Scanner sc = new Scanner(str);
            int dias = sc.nextInt();
            int d = sc.nextInt();
            int m = sc.nextInt();
            int y = sc.nextInt();
            if (dias == 0 && d == 0 && m == 0 && y == 0) {
                return;
            }
            LocalDate fecha = LocalDate.of(y, m, d);
            fecha = fecha.plusDays(dias);
            d = fecha.getDayOfMonth();
            m = fecha.getMonthValue();
            y = fecha.getYear();
            System.out.println(String.format("%d %d %d", d, m, y));
        }
    }
}
