package food;

// Concrete factories
public class MeatDietFactory implements MealFactory {
    @Override
    public Soup createSoup() {
        return new Borscht();
    }

    @Override
    public MainCourse createMainCourse() {
        return new Cutlet();
    }

    public Dessert createDessert() {
        return new ChocolateCake();
    }
}