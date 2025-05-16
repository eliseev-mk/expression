public class Main {

    // Soup (abstract product)
    public static abstract class Soup {
        public abstract String getDescription();
    }

    // Main course (abstract product)
    public static abstract class MainCourse {
        public abstract String getDescription();
    }

    // Desert
    public static abstract class Dessert {
        public abstract String getDescription();
    }

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}