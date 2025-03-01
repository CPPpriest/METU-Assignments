import java.util.ArrayList;

public class CengTreeNodeLeaf extends CengTreeNode
{
    private ArrayList<CengBook> books;
    // TODO: Any extra attributes

    public CengTreeNodeLeaf(CengTreeNode parent)
    {
        super(parent);
        this.books = new ArrayList<>();
        this.type = CengNodeType.Leaf;
        // TODO: Extra initializations


    }

    // GUI Methods - Do not modify
    public int bookCount()
    {
        return books.size();
    }
    public Integer bookKeyAtIndex(Integer index)
    {
        if(index >= this.bookCount()) {
            return -1;
        } else {
            CengBook book = this.books.get(index);

            return book.getBookID();
        }
    }

    // Extra Functions

    //set all members for leaf: p:parent, b:books, t:type, d:order



    // insert to leaf, if leaf node overflows , returns true
    public Boolean insert2leaf(CengBook book)
    {
        //empty leaf (insert to leaf node root)
        if(this.bookCount() == 0)
        {
            this.books.add(book);   //add to leaf
            return false;
        }

        int recordCount = this.bookCount();


        for(int i=0; i<=recordCount; ++i)
        {
            int currID = this.bookKeyAtIndex(i);
            int recID = book.getBookID();

            if( (i == recordCount) || (recID < currID) )
            {
                this.books.add(i,book); //add to leaf
                break;
            }
        }

        if(this.bookCount() == (order*2 + 1) )
        {
            return true;    // leaf node overflow
        }

        return false;
    }


    // move last d+1 records from this to new leaf (leafB).
    // return leafB
    // leafB contains only the records, no other member is initialized

    public ArrayList<CengTreeNodeLeaf> splitLeaf()
    {
        ArrayList<CengTreeNodeLeaf> childLeafs = new ArrayList<CengTreeNodeLeaf>();

        CengTreeNodeLeaf childA = new CengTreeNodeLeaf(null);
        CengTreeNodeLeaf childB = new CengTreeNodeLeaf(null);

        //insert last d+1 records to leafB
        int d = CengTreeNode.order;
        for(int i=d ; i <= d*2 ; ++i)
        {
            childB.insert2leaf(this.books.get(i));
        }

        //remove last d+1 records from this leaf
        for(int i=d*2 ; i >= d ; --i)
        {
            this.books.remove(i);
        }

        childA = this;

        childLeafs.add(childA);
        childLeafs.add(childB);

        return childLeafs;
    }

    public String printLeafNode( int tabCount)
    {
        String tabs = "";

        for(int i=0; i<=tabCount; ++i)
        {
            tabs = tabs + "\t";
        }

        String leafStr = tabs + "<data>\n";
        for(int i=0; i<this.bookCount() ; ++i)
        {
            String recStr = tabs + "<record>";
            CengBook currRec = this.books.get(i);
            recStr = recStr + currRec.fullName();
            recStr = recStr + "</record>\n";

            leafStr = leafStr + recStr;
        }

        leafStr = leafStr + tabs + "</data>\n";

        return leafStr;

    }

}
