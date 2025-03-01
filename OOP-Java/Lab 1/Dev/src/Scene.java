import java.awt.*;
import java.util.ArrayList;
import java.util.HashMap;

final public class Scene {
    private static ArrayList<CustomerEntity> customers = new ArrayList<CustomerEntity>();
    private static ArrayList<StoreEntity> stores = new ArrayList<StoreEntity>();

    static int replenishmentCount;

    public Scene(){
        replenishmentCount = 0;
    }


    public void addCustomer( CustomerEntity ce){
        customers.add(ce);
    }

    public void addStore( StoreEntity se){
        stores.add(se);
    }

    public ArrayList<CustomerEntity> getCustomers() {
        return customers;
    }

    public ArrayList<StoreEntity> getStores() {
        return stores;
    }

    public void removeLeftCustomers(){
        // remove left Customers
        System.out.println("Left customers removed.\n");
    }

    public void moveAllEntities(){
        // move all entities
        System.out.println("All entities are moved.\n");
    }

    public void replenishAllStocks(){
        if( replenishmentCount == Common.getStockReplenishmentFrequency() )
        {
            // do replenishment for all stores
            System.out.println("All stocks are replenished.\n");
            replenishmentCount = 0;
        }
        replenishmentCount++;
    }

    public void drawCustomers(Graphics g){
        for (CustomerEntity customer : customers) {
            customer.draw( (Graphics2D) g);
        }
    }
    public void drawStores(Graphics g){
        for (StoreEntity store : stores) {
            store.draw( (Graphics2D) g);
        }
    }

}
