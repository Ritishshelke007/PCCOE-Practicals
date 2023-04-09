import java.util.LinkedList;
import java.util.Scanner;
class emp{
    int emp_id;
    String emp_name,emp_dept;
    public emp(int emp_id, String emp_name, String emp_dept){
        this.emp_id = emp_id;
        this.emp_name = emp_name;
        this.emp_dept = emp_dept;
    }

}

public class Employee {
    public static void main(String[] args) {
        int choice;
        String name,dept;
        int id, flag=0;
        Scanner sc = new Scanner(System.in);
        LinkedList<emp> ll = new LinkedList<>();

        do {
            System.out.println("Enter your choice : \n1. Add Employee\n2. Delete Employee\n3. Display");
            choice = sc.nextInt();

            switch (choice){
                case 1:
                    emp e1 = new emp(101, "Ritish","Computer");
                    emp e2 = new emp(102, "Nitin","IT");
                    emp e3 = new emp(110, "Nikhil","Mech");
                    emp e4 = new emp(115, "Rohit","ENTC");

                    ll.add(e1);
                    ll.add(e2);
                    ll.add(e3);
                    ll.add(e4);

                    System.out.println("Employee added!");
                    break;

                case 2:
                    try {
                        System.out.println("Enter index to delete ");
                        ll.remove(sc.nextInt());
                        System.out.println("Employee removed from list");
                    }
                    catch (Exception e){
                        System.out.println("Index not found!");
                    }

                    break;
                case 3:
                    for (emp e:ll){
                        System.out.println(e.emp_id + "\t" + e.emp_name +"\t"+ e.emp_dept);
                    }

                    break;

                default:
                    System.out.println("Invalid choice!");
                    break;

            }
            System.out.println("Press 1 to continue");
        }
        while (sc.nextInt()==1);
    }
}
