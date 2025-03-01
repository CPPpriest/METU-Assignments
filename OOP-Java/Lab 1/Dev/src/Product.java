public class Product {
    public enum Types {
        FOOD,
        ELECTRONICS,
        LUXURY,
        NONE
    }

    private Types type;

    public Product(){
        this.type = Types.NONE;
    }

    public void setType(Types type){
        this.type = type;
    }

    public Types getProductType(){
        return this.type;
    }
}
