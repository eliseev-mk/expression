package food;

// Abstract factory
public interface MealFactory {
    Soup createSoup();
    MainCourse createMainCourse();
}