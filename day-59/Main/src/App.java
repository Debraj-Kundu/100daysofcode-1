import java.io.IOException;

class Parent {
    int hand, leg, eye;

    Parent() throws IOException {

    }

    void watch() {
        eye = 1;
    }

    void walk() {
        leg = 1;
    }

    void grab() {
        hand = 1;
    }
}

class Child extends Parent {
    Child() throws IOException {

    }
}

public class App {
    public static int sum(int... x) {
        return x[0] + x[1] + x[2];
    }

    public static void main(String[] args) throws Exception {
        // Child c = new Child();

        System.out.println(sum(1, 2, 3));
    }
}
