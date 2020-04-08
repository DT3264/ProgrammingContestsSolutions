
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

    static String ReadLn(int maxLg) // utility function to read from stdin
    {
        byte lin[] = new byte[maxLg];
        int lg = 0, car = -1;
        String line = "";
        try {
            while (lg < maxLg) {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) {
                    break;
                }
                lin[lg++] += car;
            }
        } catch (IOException e) {
            return (null);
        }

        if ((car < 0) && (lg == 0)) {
            return (null);  // eof
        }
        return (new String(lin, 0, lg));
    }

    public static void main(String[] args) throws FileNotFoundException {
        //BufferedReader bf = new BufferedReader(new FileReader(new File("in.txt")));
        //PrintWriter out = new PrintWriter("out.txt");
        String input;
        StringTokenizer idata;
        while ((input = Main.ReadLn(255)) != null) {

            idata = new StringTokenizer(input);
            int dias = Integer.parseInt(idata.nextToken());
            int d = Integer.parseInt(idata.nextToken());
            int m = Integer.parseInt(idata.nextToken());
            int y = Integer.parseInt(idata.nextToken());
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
