package food;

public class Lunch {
    private final Soup soup;
    private final MainCourse mainCourse;
    private final Dessert dessert;

    public Lunch(MealFactory factory) {
        this.soup = factory.createSoup();
        this.mainCourse = factory.createMainCourse();
        this.dessert = factory.createDessert();
    }

    public void showMenu() {
        System.out.println("Soup: " + soup.getDescription());
        System.out.println("Main course: " + mainCourse.getDescription());
        System.out.println("Dessert: " + dessert.getDescription());
    }
}