package food;

public class VeggieDietFactory implements MealFactory {
    @Override
    public Soup createSoup() {
        return new PumpkinSoup();
    }

    @Override
    public MainCourse createMainCourse() {
        return new FriedPotatoes();
    }

    public Dessert createDessert() {
        return new Croissant();
    }
}