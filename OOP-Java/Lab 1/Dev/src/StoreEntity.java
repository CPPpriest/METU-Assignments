import java.awt.*;

public class StoreEntity extends Entity{

    Product product;
    double sellPrice;

    int stockCapacity;
    int currStock;

    public StoreEntity(Position p, Product prodType, double price, int mStock) {
        super(p.getX(), p.getY());

        this.product = prodType;
        this.sellPrice = price;

        this.stockCapacity = mStock;
        this.currStock = mStock;
    };


    @Override
    public void draw(Graphics2D g2d){
        String text = "Customer";
        drawHelper(g2d, text, Color.ORANGE);
    };

    @Override
    public void step(){

    };

}
