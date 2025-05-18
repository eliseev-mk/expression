import food.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("===Meat Diet===");
        MealFactory meatFactory = new MeatDietFactory();
        Lunch meatDiet = new Lunch(meatFactory);
        meatDiet.showMenu();

        System.out.println("\n===Veggie Diet===");
        MealFactory veggieFactory = new VeggieDietFactory();
        Lunch veggieDiet = new Lunch(veggieFactory);
        veggieDiet.showMenu();

        System.out.println("\n===Kefir Diet===");
        MealFactory kefirFactory = new KefirDietFactory();
        Lunch kefirDiet = new Lunch(kefirFactory);
        kefirDiet.showMenu();
    }
}