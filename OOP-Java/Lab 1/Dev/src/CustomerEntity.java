import java.awt.*;
import java.util.ArrayList;

public class CustomerEntity extends Entity{

    ArrayList<Product> shoppingList = new ArrayList<Product>();

    public CustomerEntity(Position p){
        super(p.getX(), p.getY());
    };

    @Override
    public void draw(Graphics2D g2d){
        String text = "Store";
        drawHelper(g2d, text, Color.GRAY);
    };

    @Override
    public void step(){

    };
}
