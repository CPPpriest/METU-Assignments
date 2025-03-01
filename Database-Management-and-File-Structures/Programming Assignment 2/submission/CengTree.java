import java.util.ArrayList;

public class CengTree
{
    public CengTreeNode root;
    // Any extra attributes...

    //public Integer depth;


    public CengTree(Integer order)
    {
        CengTreeNode.order = order;

        // TODO: Initialize the class
        this.root = null;
    }

    public void addBook(CengBook book)
    {
        // TODO: Insert Book to Tree

        //Empty Tree, null root
        if(this.root == null)
        {
            this.root = new CengTreeNodeLeaf(null);

            CengTreeNodeLeaf LN = new CengTreeNodeLeaf(null);

            LN.insert2leaf(book);   // cannot overflow

            this.root = LN;

            return;
        }

        // leaf root but not empty
        if(this.root.getType() == CengNodeType.Leaf)
        {
            CengTreeNodeLeaf LN = (CengTreeNodeLeaf) this.root;
            if( LN.insert2leaf(book) )
            {
                //overflow case I

                CengTreeNodeInternal IN = new CengTreeNodeInternal(null);
                //IN.setLevel(0);

                CengTreeNodeLeaf currRoot = (CengTreeNodeLeaf) this.root;

                // childA and childB
                ArrayList<CengTreeNodeLeaf> leafChildren = currRoot.splitLeaf();
                CengTreeNodeLeaf childA = leafChildren.get(0);
                CengTreeNodeLeaf childB = leafChildren.get(1);
                //initiate childA, childB : level, type, order

                childA.setParent(IN);
                //childA.setLevel(IN.getLevel() + 1 );

                childB.setParent(IN);
                //childA.setLevel(IN.getLevel() + 1 );

                IN.insert2Internal( childB.bookKeyAtIndex(0), childB );
                IN.insertChild(childA);

                this.root = IN;

            }

        }

        // Internal root
        //Find corresponding leaf and insert to it
        else
        {
            CengTreeNode currNode = this.root;

            ArrayList<CengTreeNodeInternal> InternalPath = new ArrayList<CengTreeNodeInternal>();

            while(currNode.getType() == CengNodeType.Internal)
            {
                CengTreeNodeInternal currInternalNode = (CengTreeNodeInternal) currNode;

                int keyCount = currInternalNode.keyCount();
                int bookID = book.getBookID();

                for(int i=0; i<=keyCount; ++i)
                {
                    int currKey = currInternalNode.keyAtIndex(i);

                    if( (keyCount == i) || (bookID < currKey) )
                    {
                        InternalPath.add( (CengTreeNodeInternal) currNode );
                        currNode = currInternalNode.getAllChildren().get(i);
                        break;
                    }
                }

            }

            //here, currNode supposed to be a leaf node
            CengTreeNodeLeaf foundLeafNode = (CengTreeNodeLeaf) currNode;


            //-------------------------------------------------

            if( foundLeafNode.insert2leaf(book) )
            {
                // overflow case II

                int currInternal = InternalPath.size() - 1;
                CengTreeNodeInternal IN = InternalPath.get(currInternal);

                // childA and childB
                ArrayList<CengTreeNodeLeaf> leafChildren = foundLeafNode.splitLeaf();

                CengTreeNodeLeaf childB = leafChildren.get(1);
                childB.setParent(IN);


                if(IN.insert2Internal( childB.bookKeyAtIndex(0), childB ))
                {
                    // Overflow case III
                }

                //DONE
            }
        }
    }

    public ArrayList<CengTreeNode> searchBook(Integer bookID)
    {
        // TODO: Search within whole Tree, return visited nodes.

        //Empty Tree
        if(this.root == null)
        {
            String str ="Could not find " + bookID + ".\n";
            System.out.println(str);
            return null;
        }

        ArrayList<CengTreeNode> pathArray = new ArrayList<CengTreeNode>();

        CengTreeNode currNode = root;


        while(currNode.getType() == CengNodeType.Internal)
        {
            pathArray.add( currNode );

            CengTreeNodeInternal currIndexNode = (CengTreeNodeInternal) currNode;
            int keyCount = currIndexNode.keyCount();
            int childIndex = 0;

            int i = 0;
            while(i <= keyCount)
            {
                childIndex = i;

                if (    ( (i==keyCount) &&  ( bookID >= currIndexNode.keyAtIndex(i-1) ) )
                        ||
                        ( bookID < currIndexNode.keyAtIndex(i) )
                    )
                {
                    break;
                }

                ++i;
            }

            currNode = currIndexNode.getAllChildren().get(childIndex);
        }


        // currNode.getType() == CengNodeType.Leaf below this line
        pathArray.add( currNode );

        CengTreeNodeLeaf foundLeafNode = (CengTreeNodeLeaf) currNode;
        int recordCount = foundLeafNode.bookCount();
        for(int i=0; i<recordCount; ++i)
        {
            //record found
            if(foundLeafNode.bookKeyAtIndex(i) == bookID)
            {
                printPath(pathArray);
                return pathArray;
            }
            //record not found
            if(foundLeafNode.bookKeyAtIndex(i) > bookID)
            {

                break;
            }
        }

        String str ="Could not find " + bookID + ".\n";
        System.out.println(str);
        return null;
    }

    public void printTree()
    {
        CengTreeNode currNode = this.root;

        String treeStr = printSubTree(currNode, 0);

        System.out.println(treeStr);
    }

    // Any extra functions...
    public String printSubTree(CengTreeNode r, int lev)
    {
        if(r == null)
        {
            return "";
        }

        if(r.getType() == CengNodeType.Leaf)
        {
            CengTreeNodeLeaf LN = (CengTreeNodeLeaf) r;
            return LN.printLeafNode(lev);
        }

        CengTreeNodeInternal IN = (CengTreeNodeInternal) r;

        String retStr = "";

        retStr = retStr + IN.printInternalNode(lev);

        for(int i=0; i < IN.keyCount()+1 ; ++i)
        {
            retStr = retStr + printSubTree(IN.getAllChildren().get(i), lev+1);
        }

        return retStr;
    }


    public void printPath( ArrayList<CengTreeNode> pathArray)
    {
        String retStr = "";

        for(int i=0; i<pathArray.size(); ++i)
        {
            if(pathArray.get(i).getType() == CengNodeType.Internal)
            {
                CengTreeNodeInternal IN = (CengTreeNodeInternal) pathArray.get(i);


                retStr = retStr + IN.printInternalNode(i);
            }
            else
            {
                CengTreeNodeLeaf LN = (CengTreeNodeLeaf) pathArray.get(i);


                retStr = retStr + LN.printLeafNode(i);
            }
        }

        System.out.println(retStr);
    }

}
