public class Main {

    // Soup (abstract product)
    public static abstract class Soup {
        public abstract String getDescription();
    }

    // Main course (abstract product)
    public static abstract class MainCourse {
        public abstract String getDescription();
    }

    // Desert (abstract product)
    public static abstract class Dessert {
        public abstract String getDescription();
    }

    // Concrete classes
    public static class Borscht extends Soup {
        @Override
        public String getDescription() {
            return "Борщ";
        }
    }

    public static class PumpkinSoup extends Soup {
        @Override
        public String getDescription() {
            return "Тыквенный суп";
        }
    }

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}