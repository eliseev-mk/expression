package food;

public class Lunch {
    private final Soup soup;
    private final MainCourse mainCourse;

    public Lunch(MealFactory factory) {
        this.soup = factory.createSoup();
        this.mainCourse = factory.createMainCourse();
    }

    public void showMenu() {
        System.out.println("Soup: " + soup.getDescription());
        System.out.println("Main course: " + mainCourse.getDescription());
    }
}