import javax.print.attribute.standard.NumberOfInterveningJobs;
import java.awt.*;
import java.util.concurrent.ThreadLocalRandom;
import java.util.List;
import java.util.ArrayList;

public class Common {
    private static final String title = "Economics 101";
    private static final int windowWidth = 1650;
    private static final int windowHeight = 1000;

    private static final int entityRadius = 20; // radius of drawn entity (customer or store)

    private static final int storeNo = 10; // number of stores in the simulation
    private static final int customerNo = 10; // number of customers

    private static final int stockReplenishmentFrequency = 3000; // number of stepAllEntities calls before replenishing
                                                                 // all stores

    private static final int foodBottomPrice = 20;
    private static final int foodCeilingPrice = 50;
    private static final int electronicsBottomPrice = 200;
    private static final int electronicsCeilingPrice = 2000;
    private static final int LuxuryBottomPrice = 5000;
    private static final int LuxuryCeilingPrice = 10000;

    private static final int minimumShoppingListLength = 5;
    private static final int maximumShoppingListLength = 10;

    private static final int stockStorageMin = 15; // minimum size of storage available for a store
    private static final int stockStorageMax = 25; // maximum number of storage available for a store

    private static final int customerMovementSpeed = 2;
    private static final Font font = new Font("Verdana", Font.BOLD, 20);

    public static String getTitle() {
        return title;
    }

    public static int getWindowWidth() {
        return windowWidth;
    }

    public static int getWindowHeight() {
        return windowHeight;
    }

    public static int getEntityRadius() {
        return entityRadius;
    }

    public static Font getFont() {
        return font;
    }

    public static int getCustomerMovementSpeed() {
        return customerMovementSpeed;
    }

    // TODO
    // put your necessary fields and methods here
    public static Scene scene  = new Scene();

    public ArrayList<CustomerEntity> getAllCustomers(){
        return scene.getCustomers();
    }

    public static int getStockReplenishmentFrequency(){
        return stockReplenishmentFrequency;
    }
    ////

    // TODO
    // When adding new stores or customers, their position, shopping list,
    // max stock etc. should be random between the ranges defined above.
    // You can use the function below or define your own function to generate
    // a random integer
    public static int randInt(int min, int max) {
        return ThreadLocalRandom.current().nextInt(min, max + 1);
    }
    // E.g.
    /*
    //Product Generation
    switch(randInt(0,2)){
        case 0:
            //Food
            break;
        case 1:
            //Electronics
            break;
        case 2:
            //Luxury
            break;
     }
    }
    //x position of the center of entity generation
    double centerX = randInt(0,windowWidth-2*entityRadius)
    */

    // TODO
    // Create customers and stores
    // Hint: you can also use a static block for this
    // Also note that you should make sure there are about equal number of stores
    // for all products
    // like 4 stores for food, 3 stores for electronics and 4 stores for luxury etc.
    // Otherwise your simulation may deadlock

    static {

        for(int i=0; i < storeNo; ++i){

            // POSITION
            double px = randInt(0,windowWidth-2*entityRadius);      // ?
            double py = randInt(0,windowHeight-2*entityRadius);     // ?
            Position p = new Position(px, py);

            // PRODUCT TYPE && PRICE
            Product prodType = new Product();
            int price = 0;

            switch(randInt(0,2)) {
                case 0:
                    prodType.setType(Product.Types.FOOD);
                    price = randInt(foodBottomPrice,foodCeilingPrice);
                    break;
                case 1:
                    prodType.setType(Product.Types.ELECTRONICS);
                    price = randInt(electronicsBottomPrice, electronicsCeilingPrice);
                    break;
                case 2:
                    prodType.setType(Product.Types.LUXURY);
                    price = randInt(LuxuryBottomPrice, LuxuryCeilingPrice);
                    break;
            }

            int stockCapacity = randInt(stockStorageMin,stockStorageMax);
            StoreEntity newStore = new StoreEntity(p, prodType, price, stockCapacity );

            scene.addStore(newStore);
        }




        for(int i=0; i < customerNo; ++i){

            // POSITION
            double px = randInt(0,windowWidth-2*entityRadius);      // ?
            double py = randInt(0,windowHeight-2*entityRadius);     // ?
            Position p = new Position(px, py);


            CustomerEntity newCustomer = new CustomerEntity(p);

            scene.addCustomer(newCustomer);
        }



    }



    ////
}
