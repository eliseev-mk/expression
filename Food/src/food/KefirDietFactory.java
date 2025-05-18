package food;

public class KefirDietFactory implements MealFactory {
    @Override
    public Soup createSoup() {
        return new Okroshka();
    }

    @Override
    public MainCourse createMainCourse() {
        return new Pudding();
    }

    @Override
    public Dessert createDessert() {
        return new Yogurt();
    }
}