import java.math.BigInteger;

public class LargeIntegerSquare {

    public static BigInteger multiply(BigInteger a, BigInteger b) {
        // Base case: if length(a) <= 1 or length(b) <= 1, return a * b
        if (a.toString().length() <= 1) {
            return a.multiply(b);
        }

        // Partition a and b into lower and upper digits
        int n = a.toString().length() / 2;
        BigInteger[] splitA = a.divideAndRemainder(BigInteger.TEN.pow(n));
        BigInteger a1 = splitA[0];
        BigInteger a2 = splitA[1];

        BigInteger[] splitB = b.divideAndRemainder(BigInteger.TEN.pow(n));
        BigInteger b1 = splitB[0];
        BigInteger b2 = splitB[1];

        // Recursive steps
        BigInteger A = multiply(a1, b1);
        BigInteger B = multiply(a2, b1);
        BigInteger C = multiply(a1, b2);
        BigInteger D = multiply(a2, b2);

        // Combine the results
        BigInteger term1 = A.multiply(BigInteger.TEN.pow(2 * n));
        BigInteger term2 = (B.add(C)).multiply(BigInteger.TEN.pow(n));
        BigInteger result = term1.add(term2).add(D);

        return result;
    }

    public static void main(String[] args) {
        // Example: Multiply two numbers a and b using the Karatsuba algorithm
        BigInteger a = new BigInteger("65485236");
        BigInteger b = new BigInteger("65485236");

        BigInteger result = multiply(a, b);

        System.out.println("Result: " + result);
    }
}
