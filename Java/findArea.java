import java.util.Scanner;

abstract class Shape{
    Scanner sc = new Scanner(System.in);
    float length, breadth, height, radius;
    abstract void Area();
}
class Rectangle extends Shape{
    void Area(){
        System.out.println("Enter Length and Breadth : ");
        length = sc.nextFloat();
        breadth = sc.nextFloat();
        System.out.println("Area of Rectangle : "+(length*breadth));
    }
}
class Triangle extends Shape{
    void Area(){
        System.out.println("Enter Base and height :");
        length = sc.nextFloat();
        height = sc.nextFloat();
        System.out.println("Area of Triangle : "+(0.5*length*height));
    }
}
class Circle extends Shape{
    void Area(){
        System.out.println("Enter radius:");
        radius =sc.nextFloat();
        System.out.println("Area of Circle : "+3.14*radius*radius);
    }
}

public class findArea{

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int choice;
            Shape s;
            do {
                System.out.println("Enter Your Choice : \n1. Rectangle\n2. Triangle\n3. Circle\n");
                choice = sc.nextInt();

                switch (choice){
                    case 1:
                        s = new Rectangle();
                        s.Area();
                        break;

                    case 2:
                        s = new Triangle();
                        s.Area();
                        break;

                    case 3:
                        s = new Circle();
                        s.Area();
                        break;

                    default:
                        System.out.println("Invalid choice!");

                }
                System.out.println("Press 1 to continue");
        }
            while (sc.nextInt()==1);
        }
}




