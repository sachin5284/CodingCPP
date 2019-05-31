public class Hello {

    /* This is my first java program.
     * This will print 'Hello World' as the output
     */
 
    public static void main(String []args) {
        B b = new A();
        
        b.sayHello();
       System.out.println("Sachin"); // prints Hello World
    }
 }
 interface B
 {
    void sayHello();
 }


 class A implements B
 {
    int x;
    public void sayHello() {
        System.out.println("Sachin");
    }

 }

 