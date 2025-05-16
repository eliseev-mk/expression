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
            return "Borscht";
        }
    }

    public static class PumpkinSoup extends Soup {
        @Override
        public String getDescription() {
            return "PumpkinSoup";
        }
    }

    public static class FriedPotatoes extends MainCourse {
        @Override
        public String getDescription() {
            return "FriedPotatoes";
        }
    }

    public static class Cutlet extends MainCourse {
        @Override
        public String getDescription() {
            return "Cutlet";
        }
    }

    // Abstract factory
    public interface MealFactory {
        Soup createSoup();
        MainCourse createMainCourse();
    }

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}