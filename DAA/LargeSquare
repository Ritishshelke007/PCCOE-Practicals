import java.math.BigInteger;
import java.util.*;

public class LargeSquare{
    public static BigInteger multiply(BigInteger x, BigInteger y) {
        int n = x.bitLength();

        // If n is small, return simple multiplication
        if (n <= 1) {
            return x.multiply(y);
        }

        // Split the input numbers into a1, a2, b1, and b2
        int half = n / 2;
        BigInteger a1 = x.shiftRight(half);
        BigInteger b1 = a1;
        BigInteger a2 = x.subtract(a1.shiftLeft(half));
        BigInteger b2 = a2;

        // Recursive calls
        BigInteger A = multiply(a1, b1);
        BigInteger B = multiply(a2, b2);

        // Optimized step: Compute C using one less recursive call
        BigInteger C = multiply(a1.add(a2), b1.add(b2)).subtract(A).subtract(B);

        // Combine the results
        BigInteger firstTerm = A.shiftLeft(2 * half);
        BigInteger secondTerm = C.shiftLeft(half);
        BigInteger result = firstTerm.add(secondTerm).add(B);

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Large Integer : ");
        BigInteger a = sc.nextBigInteger();

        BigInteger square = multiply(a, a);
        System.out.println("Square of "+a+ "is : " + square);
    }
}
