import java.util.ArrayList;

public class App {
    final int x;
    static int y;

    App() {
        System.out.println("ran");
    }

    {
        x = 69;
        System.out.println("Yeah Boi!");
    }

    public static void main(String[] args) throws Exception {
        App a = new App();
        // App b = new App();
        y = 10;
        System.out.println(a.x);
        ArrayList arr = new ArrayList<Integer>();
        arr.add(10);
        arr.add(20);
        arr.removeAll(arr);
        System.out.println(arr);
        /*
         * System.out.println(b.y);
         */
        // System.out.println(Integer.valueOf("69"));
    }
}
