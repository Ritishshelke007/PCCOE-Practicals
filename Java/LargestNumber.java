import java.util.Scanner;

class Bank{
    int acc_no;
    String acc_name, acc_type;
    float acc_blnc,amount;

    Scanner sc = new Scanner(System.in);

    public void deposit() {
        System.out.println("Enter Account Number : ");
        acc_no = sc.nextInt();
        System.out.println("Enter Customer Name : ");
        acc_name = sc.next();
        System.out.println("Enter Account Type : ");
        acc_type = sc.next();
        System.out.println("Enter amount : ");
        amount = sc.nextInt();
        acc_blnc += amount;
        System.out.println("Amount Deposit Success!");
    }

    public  void display(){
        System.out.println("Customer Name : "+acc_name);
        System.out.println("Available Balance : "+acc_blnc);
    }

    public  void withdraw(){
        System.out.println("Enter amount to withdrawal : ");
        amount = sc.nextInt();
        if ((acc_blnc-amount)<0){
            System.out.println("Transaction failed | Unsufficient funds");
        }
        else {
            acc_blnc -=amount;
            System.out.println("Transaction Success!\nUpdated Balance : ");
            display();
        }
    }

}

public class Account {
    public static void main(String[] args) {
        int choice;
        Bank b = new Bank();
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("Enter choice\n1. Deposit\n2. Withdrawal\n3. Display Account");
            choice = sc.nextInt();

            switch (choice){
                case 1:
                    b.deposit();
                    break;

                case 2:
                    b.withdraw();
                    break;

                case 3:
                    b.display();
                    break;

                default:
                    System.out.println("Invalid Choice!");
            }
            System.out.println("Press 1 to continue");
        }
        while (sc.nextInt()==1);


    }
}
