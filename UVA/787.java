
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static ArrayList<BigInteger> vec = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);
    static BigInteger best;

    static void startFrom(int pos) {
        BigInteger prod = vec.get(pos);
        best = best.max(prod);
        for (int i = pos + 1; i < vec.size(); i++) {
            if (vec.get(i).equals(0)) {
                return;
            }
            prod = prod.multiply(vec.get(i));
            best = best.max(prod);
        }
    }

    public static void solve(String numsStr) {
        vec.clear();
        for (String s : numsStr.split(" ")) {
            vec.add(new BigInteger(s));
        }
        vec.remove(vec.size() - 1);
        best = vec.get(0);
        for (int i = 0; i < vec.size(); i++) {
            startFrom(i);
        }
        System.out.println(best);
    }

    public static void main(String[] args) throws FileNotFoundException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        bf.lines().forEach((s) -> {
            solve(s);
        });
    }
}
