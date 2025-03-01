import java.util.ArrayList;

public class CengTreeNodeInternal extends CengTreeNode
{
    private ArrayList<Integer> keys;
    private ArrayList<CengTreeNode> children;

    public CengTreeNodeInternal(CengTreeNode parent)
    {
        super(parent);
        this.children = new ArrayList<>();
        this.keys = new ArrayList<>();
        this.type = CengNodeType.Internal;

        // TODO: Extra initializations, if necessary.

        //decide if children are leaf or internal node, do accordingly
    }

    // GUI Methods - Do not modify
    public ArrayList<CengTreeNode> getAllChildren()
    {
        return this.children;
    }
    public Integer keyCount()
    {
        return this.keys.size();
    }
    public Integer keyAtIndex(Integer index)
    {
        if(index >= this.keyCount() || index < 0)
        {
            return -1;
        }
        else
        {
            return this.keys.get(index);
        }
    }

    // Extra Functions


    public Boolean insert2Internal( int m, CengTreeNode childB )
    {
        //empty internal (insert to internal node root)
        if(this.keyCount() == 0) {

            this.keys.add(m);   //add to keys
            this.children.add(childB);
            return false;
        }

        //-------------------------------------------------------
        int keyCount = this.keyCount();

        for(int i=0; i<=keyCount; ++i)
        {
            int currKey = this.keyAtIndex(i);

            if( (i == keyCount) || (m < currKey) )
            {
                this.keys.add(i,m); //add to leaf
                this.children.add(i+1,childB);
                break;
            }
        }


        //check overflow

        if(this.keyCount() == (CengTreeNode.order * 2 + 1) )
        {
            return true;    //internal node overflow
        }

        return false;
    }

    //Internal node, keys - non empty, inserts the leftmost child
    public void insertChild(CengTreeNode childA )
    {
        this.children.add(0,childA);
    }

    public void insertKey(int k)
    {
        this.keys.add(k);
    }

    public String printInternalNode(int tabCount)
    {
        String tabs = "\t";
        tabs.repeat(tabCount);

        String internalStr = tabs + "<index>\n";
        for(int i=0; i<this.keyCount() ; ++i)
        {
            int currKey = this.keyAtIndex(i);
            internalStr = internalStr + tabs + currKey + "\n";
        }

        internalStr = internalStr + tabs + "</index>\n";

        return internalStr;

    }

}
