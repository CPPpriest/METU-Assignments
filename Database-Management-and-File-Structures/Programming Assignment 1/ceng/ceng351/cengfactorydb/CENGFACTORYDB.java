package ceng.ceng351.cengfactorydb;

import java.sql.*;
import java.util.ArrayList;


public class CENGFACTORYDB implements ICENGFACTORYDB{

    private static String user = "e2448603"; // TODO: Your userName
    private static String password = "L&8mFyi2Zs52"; //  TODO: Your password
    private static String host = "144.122.71.128"; // host name
    private static String database = "db2448603"; // TODO: Your database name
    private static int port = 8080; // port

    private static Connection connection = null;
    public void initialize() {
        String url = "jdbc:mysql://" + host + ":" + port + "/" + database;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection =  DriverManager.getConnection(url, user, password);
        }
        catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public int createTables() {
        String CT_Factory = "CREATE TABLE IF NOT EXISTS Factory( " +
                                "factoryId INT, " +
                                "factoryName TEXT, " +
                                "factoryType TEXT, " +
                                "country TEXT, " +
                                "PRIMARY KEY (factoryId)   );";


        String CT_Employee ="CREATE TABLE IF NOT EXISTS Employee( " +
                                "employeeId INT, " +
                                "employeeName TEXT, " +
                                "department TEXT, " +
                                "salary INT, " +
                                "PRIMARY KEY (employeeId) );";


        String CT_Product ="CREATE TABLE IF NOT EXISTS Product( " +
                                "productId INT, " +
                                "productName TEXT, " +
                                "productType TEXT, " +
                                "PRIMARY KEY (productId)    );";


        String CT_Works_In ="CREATE TABLE IF NOT EXISTS Works_In( " +
                                "factoryId INT, " +
                                "employeeId INT, " +
                                "startDate DATE, " +
                                "PRIMARY KEY (factoryId, employeeId), " +
                                "FOREIGN KEY (factoryId) REFERENCES Factory(factoryId) " +
                                    "ON DELETE CASCADE " +
                                    "ON UPDATE CASCADE, " +
                                "FOREIGN KEY (employeeId) REFERENCES Employee(employeeId) " +
                                    "ON DELETE CASCADE " +
                                    "ON UPDATE CASCADE   );";


        String CT_Produce ="CREATE TABLE IF NOT EXISTS Produce( " +
                                "factoryId INT, " +
                                "productId INT, " +
                                "amount INT, " +
                                "productionCost INT, " +
                                "PRIMARY KEY (factoryId, productId), " +
                                "FOREIGN KEY (factoryId) REFERENCES Factory(factoryId) " +
                                    "ON DELETE CASCADE " +
                                    "ON UPDATE CASCADE, " +
                                "FOREIGN KEY (productId) REFERENCES Product(productId) " +
                                    "ON DELETE CASCADE " +
                                    "ON UPDATE CASCADE      );";


        String CT_Shipment = "CREATE TABLE IF NOT EXISTS Shipment( " +
                                "factoryId INT, " +
                                "productId INT, " +
                                "amount INT,  " +
                                "pricePerUnit INT, " +
                                "PRIMARY KEY (factoryId, productId), " +
                                "FOREIGN KEY (factoryId) REFERENCES Factory(factoryId) " +
                                    "ON DELETE CASCADE " +
                                    "ON UPDATE CASCADE, " +
                                "FOREIGN KEY (productId) REFERENCES Product(productId) " +
                                    "ON DELETE CASCADE " +
                                    "ON UPDATE CASCADE      );";



        String[] CT = new String[]{CT_Factory,CT_Employee,CT_Product,CT_Works_In,CT_Produce,CT_Shipment} ;

        int tableCount = 0;
        for (String crt : CT) {
            try {
                Statement stmt = connection.createStatement();
                stmt.execute(crt);
                tableCount++;
            }
            catch(SQLException e){System.out.println(e);}
        }

        return tableCount;
    }

    public int dropTables() {

        String DT_Shipment =    "DROP TABLE IF EXISTS Shipment; ";
        String DT_Produce =     "DROP TABLE IF EXISTS Produce; ";
        String DT_Works_In =    "DROP TABLE IF EXISTS Works_In; ";
        String DT_Product =     "DROP TABLE IF EXISTS Product; ";
        String DT_Employee =    "DROP TABLE IF EXISTS Employee; ";
        String DT_Factory =     "DROP TABLE IF EXISTS Factory; ";


        String[] DT = new String[]{DT_Shipment, DT_Produce, DT_Works_In, DT_Product, DT_Employee, DT_Factory,} ;

        int dropCount = 0;
        for (String dpt : DT) {
            try {
                Statement stmt = connection.createStatement();
                stmt.execute(dpt);
                dropCount++;
            }
            catch(SQLException e){System.out.println(e);}
        }

        return dropCount;
    }

    public int insertFactory(Factory[] factories) {

        int insertFactoryCount = 0;

        String sqlQuery = "INSERT INTO Factory VALUES(?, ?, ?, ?);" ;

        for(Factory factory : factories)
        {
            try(PreparedStatement pstmt = connection.prepareStatement(sqlQuery))
            {
                pstmt.setInt(1, factory.getFactoryId());
                pstmt.setString(2, factory.getFactoryName());
                pstmt.setString(3, factory.getFactoryType());
                pstmt.setString(4, factory.getCountry());

                pstmt.executeUpdate();
                pstmt.close();
                insertFactoryCount++;
            }
            catch(SQLException e){System.out.println(e);}
        }

        return insertFactoryCount;
    }

    public int insertEmployee(Employee[] employees) {

        int insertEmployeeCount = 0;

        String strTemplate = "INSERT INTO Employee VALUES(?, ?, ?, ?);" ;

        for(Employee employee : employees)
        {
            try(PreparedStatement pstmt = connection.prepareStatement(strTemplate))
            {
                pstmt.setInt(1, employee.getEmployeeId());
                pstmt.setString(2, employee.getEmployeeName());
                pstmt.setString(3, employee.getDepartment());
                pstmt.setInt(4, employee.getSalary());

                pstmt.executeUpdate();
                pstmt.close();
                insertEmployeeCount++;
            }
            catch(SQLException e){System.out.println(e);}
        }

        return insertEmployeeCount;
    }

    public int insertWorksIn(WorksIn[] worksIns) {

        int insertWorksInCount = 0;

        String strTemplate = "INSERT INTO Works_In VALUES(?, ?, ?);";

        for(WorksIn wi : worksIns)
         {
            //start statement
             try(PreparedStatement pstmt = connection.prepareStatement(strTemplate))
            {
                pstmt.setInt(1, wi.getFactoryId());
                pstmt.setInt(2, wi.getEmployeeId());
                pstmt.setString(3, wi.getStartDate());

                pstmt.executeUpdate();
                pstmt.close();
                insertWorksInCount++;
            }
             catch(SQLException e){System.out.println(e);}
         }


        return insertWorksInCount;
    }

    public int insertProduct(Product[] products) {

        int insertProductCount = 0;

        String strTemplate = "INSERT INTO Product VALUES(?, ?, ?);";
        for(Product pt : products)
         {
             try(PreparedStatement pstmt = connection.prepareStatement(strTemplate))
             {
                pstmt.setInt(1, pt.getProductId());
                pstmt.setString(2, pt.getProductName());
                pstmt.setString(3, pt.getProductType());

                pstmt.executeUpdate();
                pstmt.close();
                insertProductCount++;
            }
             catch(SQLException e){System.out.println(e);}

        }

        return insertProductCount;
    }

    public int insertProduce(Produce[] produces) {

        int insertProcduceCount = 0;

        String strTemplate = "INSERT INTO Produce VALUES(?, ?, ?,?);";

        for(Produce pc : produces)
        {
            try(PreparedStatement pstmt = connection.prepareStatement(strTemplate))
            {
                pstmt.setInt(1, pc.getFactoryId());
                pstmt.setInt(2, pc.getProductId());
                pstmt.setInt(3, pc.getAmount());
                pstmt.setInt(4, pc.getProductionCost());

                pstmt.executeUpdate();
                pstmt.close();
                insertProcduceCount++;
            }
            catch(SQLException e){System.out.println(e);}
        }

        return insertProcduceCount;
    }

    public int insertShipment(Shipment[] shipments) {
        int insertShipmentCount = 0;

        String strTemplate = "INSERT INTO Shipment VALUES(?, ?, ?,?);";

        for(Shipment shp : shipments)
        {

            try(PreparedStatement pstmt = connection.prepareStatement(strTemplate))
            {
                pstmt.setInt(1, shp.getFactoryId());
                pstmt.setInt(2, shp.getProductId());
                pstmt.setInt(3, shp.getAmount());
                pstmt.setInt(4, shp.getPricePerUnit());

                pstmt.executeUpdate();
                pstmt.close();
                insertShipmentCount++;
            }
            catch(SQLException e){System.out.println(e);}
        }

        return insertShipmentCount;
    }

    public Factory[] getFactoriesForGivenCountry(String country) {

        ArrayList<Factory>  FactoryList = new ArrayList<>();

        String sqlQuery =   "SELECT DISTINCT * " +
                            "FROM Factory F " +
                            "WHERE F.country = ? " +
                            "ORDER BY F.factoryId ASC;" ;

        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            pstmt.setString(1,country);

            ResultSet foundFactoryRecords = pstmt.executeQuery();

            while(foundFactoryRecords.next())
            {
                int FacId =         foundFactoryRecords.getInt(1);
                String FacName =    foundFactoryRecords.getString(2);
                String FacType =    foundFactoryRecords.getString(3);

                Factory Fact = new Factory(FacId,FacName,FacType,country);

                FactoryList.add(Fact);
            }

            pstmt.close();
        }
        catch(SQLException e){e.printStackTrace();}

        Factory[] FactoryArray = new Factory[FactoryList.size()];

        return FactoryList.toArray(FactoryArray);
    }

    public Factory[] getFactoriesWithoutAnyEmployee() {
        ArrayList<Factory>  FactList = new ArrayList<>();

        String sqlQuery =   "SELECT DISTINCT * " +
                            "FROM Factory F " +
                            "WHERE NOT EXISTS( " +
                                "SELECT DISTINCT W.factoryId " +
                                "FROM Works_In W " +
                                "WHERE W.factoryId = F.factoryId) " +
                            "ORDER BY F.factoryId ASC; " ;

        try {

            Statement stmt = connection.createStatement();

            ResultSet FactoriesWithoutEmployees = stmt.executeQuery(sqlQuery);

            while( FactoriesWithoutEmployees.next() )
            {
                int FacId =         FactoriesWithoutEmployees.getInt(1);
                String FacName =    FactoriesWithoutEmployees.getString(2);
                String FacType =    FactoriesWithoutEmployees.getString(3);
                String FacCountry = FactoriesWithoutEmployees.getString(4);

                Factory Fact = new Factory(FacId,FacName,FacType,FacCountry);

                FactList.add(Fact);
            }

            stmt.close();
        }
        catch(SQLException e){e.printStackTrace();}

        Factory[] FactArray = new Factory[FactList.size()];

        return FactList.toArray(FactArray);
    }

    public Factory[] getFactoriesProducingAllForGivenType(String productType) {

        ArrayList<Factory>  FactoriesProducingAllList = new ArrayList<>();

        String sqlQuery =   "SELECT DISTINCT * " +
                            "FROM Factory F " +
                            "WHERE NOT EXISTS ( " +
                                "SELECT DISTINCT PCT.productId " +
                                "FROM Product PCT " +
                                "WHERE PCT.productType = ? " +

                                "EXCEPT " +

                                "SELECT DISTINCT PDC.productId " +
                                "FROM Produce PDC " +
                                "WHERE PDC.factoryId = F.factoryId  ) " +
                            "ORDER BY F.factoryId ASC;" ;

        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            pstmt.setString(1,productType);

            ResultSet chosenFactories = pstmt.executeQuery();

            while(chosenFactories.next())
            {
                int FacId =         chosenFactories.getInt(1);
                String FacName =    chosenFactories.getString(2);
                String FacType =    chosenFactories.getString(3);
                String FacCountry = chosenFactories.getString(4);

                Factory Fact = new Factory(FacId,FacName,FacType,FacCountry);

                FactoriesProducingAllList.add(Fact);
            }

            pstmt.close();
        }
        catch(SQLException e){e.printStackTrace();}

        Factory[] FactoriesProducingAllArray = new Factory[FactoriesProducingAllList.size()];

        return FactoriesProducingAllList.toArray(FactoriesProducingAllArray);
    }

    public Product[] getProductsProducedNotShipped() {
        ArrayList<Product>  ProductList = new ArrayList<>();

        String sqlQuery =   "SELECT DISTINCT P.productId, P.productName, P.productType " +
                            "FROM Product P , Factory F " +
                            "WHERE P.productId IN( " +
                                "SELECT DISTINCT PDC.productId " +
                                "FROM Produce PDC " +
                                "WHERE PDC.factoryId = F.factoryId " +

                                "EXCEPT " +

                                "SELECT DISTINCT S.productId " +
                                "FROM Shipment S " +
                                "WHERE S.factoryId = F.factoryId    ) " +
                            "ORDER BY P.productId ASC;";


        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            ResultSet foundProducts = pstmt.executeQuery();

            while(foundProducts.next())
            {

                int ProductId = foundProducts.getInt(1);
                String ProductName = foundProducts.getString(2);
                String ProductType = foundProducts.getString(3);

                Product prod = new Product(ProductId,ProductName,ProductType);
                ProductList.add(prod);
            }

            pstmt.close();
        }
        catch(SQLException e){e.printStackTrace();}

        Product[] ProductArray = new Product[ProductList.size()];

        return ProductList.toArray(ProductArray);
    }

    public double getAverageSalaryForFactoryDepartment(int factoryId, String department) {

        double averageSalary = 0.0;
        String sqlQuery =   "SELECT AVG(E.salary) AS averageSalary " +
                            "FROM Employee E, Works_In W " +
                            "WHERE  W.employeeId = E.employeeId " +
                                "AND W.factoryId = ? " +
                                "AND E.department = ? ;";

        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            pstmt.setInt(1, factoryId);
            pstmt.setString(2, department);

            ResultSet resSet = pstmt.executeQuery();

            if (resSet.next())
            {
                averageSalary = resSet.getDouble("averageSalary");
            }

            pstmt.close();
        }
        catch(SQLException e){e.printStackTrace();}

        return averageSalary;
    }
    /**
     * Should return the most profitable products for each factory
     *
     * @return QueryResult.MostValueableProduct[]
     */
    public QueryResult.MostValueableProduct[] getMostValueableProducts() {

        ArrayList<QueryResult.MostValueableProduct>  FactoryValuableProductList = new ArrayList<>();

        String sqlQuery =   "SELECT DISTINCT PRDC.factoryId, PRDC.productId, P.productName, P.productType, MAX(COALESCE(S.amount, 0) * COALESCE(S.pricePerUnit, 0) - PRDC.amount * PRDC.productionCost) AS profit " +
                            "FROM Produce PRDC " +
                            "LEFT JOIN Shipment S ON PRDC.factoryId = S.factoryId AND PRDC.productId = S.productId " +
                            "JOIN Product P ON PRDC.productId = P.productId " +
                            "GROUP BY PRDC.factoryId, PRDC.productId, P.productName, P.productType " +
                            "HAVING profit = (SELECT MAX(COALESCE(SH2.amount, 0) * COALESCE(SH2.pricePerUnit, 0) - PRDC2.amount * PRDC2.productionCost) " +
                            "FROM Produce PRDC2 " +
                            "LEFT JOIN Shipment SH2 ON PRDC2.factoryId = SH2.factoryId AND PRDC2.productId = SH2.productId " +
                            "WHERE PRDC2.factoryId = PRDC.factoryId ) " +
                            "ORDER BY profit DESC, PRDC.factoryId ASC;";
        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            ResultSet foundFactoriesAndProducts = pstmt.executeQuery();

            while(foundFactoriesAndProducts.next())
            {
                int FacId =         foundFactoriesAndProducts.getInt(1);
                int ProdId =        foundFactoriesAndProducts.getInt(2);
                String ProdName =   foundFactoriesAndProducts.getString(3);
                String ProdType =   foundFactoriesAndProducts.getString(4);
                int Profit =        foundFactoriesAndProducts.getInt(5);

                QueryResult.MostValueableProduct element = new QueryResult.MostValueableProduct(FacId,ProdId,ProdName,ProdType,Profit);
                FactoryValuableProductList.add(element);
            }

            pstmt.close();
        }
        catch (SQLException e) { e.printStackTrace(); }

        QueryResult.MostValueableProduct[] FactoryValuableProductArray = new QueryResult.MostValueableProduct[FactoryValuableProductList.size()];

        return FactoryValuableProductList.toArray(FactoryValuableProductArray);
    }

    /**
     * For each product, return the factories that gather the highest profit
     * for that product
     *
     * @return QueryResult.MostValueableProduct[]
     */
    public QueryResult.MostValueableProduct[] getMostValueableProductsOnFactory() {

        ArrayList<QueryResult.MostValueableProduct>  productFactoryList = new ArrayList<>();

        String sqlQuery =   "SELECT ProdP.factoryId, FacP.productId, P2.productName, P2.productType, FacP.profit AS profit " +
                            "FROM ( " +
                                "SELECT PRDC.productId, MAX(COALESCE(S.amount,0) * COALESCE(S.pricePerUnit,0) - PRDC.amount * PRDC.productionCost) AS profit " +
                                "FROM Produce PRDC " +
                                "LEFT JOIN Shipment S ON PRDC.factoryId = S.factoryId AND PRDC.productId = S.productId " +
                                "JOIN Product P ON PRDC.productId = P.productId " +
                                "GROUP BY PRDC.productId " +
                                ") AS FacP , " +

                                "(SELECT PRDC2.factoryId, PRDC2.productId, MAX(COALESCE(S.amount,0) * COALESCE(S.pricePerUnit,0) - PRDC2.amount * PRDC2.productionCost) AS profit2 " +
                                "FROM Produce PRDC2 LEFT JOIN Shipment S ON PRDC2.factoryId = S.factoryId AND PRDC2.productId = S.productId " +
                                "JOIN Product P ON P.productId = PRDC2.productId " +
                                "GROUP BY PRDC2.factoryId, PRDC2.productId " +
                                ") AS ProdP, Product P2 " +

                            "WHERE FacP.productId = ProdP.productId " +
                                "AND FacP.profit = ProdP.profit2 " +
                                "AND ProdP.productId = P2.productId " +
                            "ORDER BY profit DESC, FacP.productId ASC; ";

        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);
            ResultSet rs = pstmt.executeQuery();

            while(rs.next())
            {
                int FacId = rs.getInt(1);
                int ProdId = rs.getInt(2);
                String ProdName = rs.getString(3);
                String ProdType = rs.getString(4);
                int Profit = rs.getInt(5);

                QueryResult.MostValueableProduct element = new QueryResult.MostValueableProduct(FacId,ProdId,ProdName,ProdType,Profit);
                productFactoryList.add(element);
            }

            if (pstmt != null) pstmt.close();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.MostValueableProduct[] productFactoryArray = new QueryResult.MostValueableProduct[productFactoryList.size()];
        return productFactoryList.toArray(productFactoryArray);
    }


    /**
     * For each department, should return all employees that are paid under the
     *     average salary for that department. You consider the employees
     *     that do not work earning ”0”.
     *
     * @return QueryResult.LowSalaryEmployees[]
     */
    public QueryResult.LowSalaryEmployees[] getLowSalaryEmployeesForDepartments() {
        ArrayList<QueryResult.LowSalaryEmployees>  lowSalaryEmpsList = new ArrayList<>();

        String sqlQuery =   "SELECT DISTINCT * " +
                            "FROM Employee E " +
                            "WHERE E.salary < ( " +
                                    "SELECT AVG(EMP.salary) " +
                                    "FROM Employee EMP " +
                                    "WHERE EMP.department = E.department) " +
                            "ORDER BY E.employeeId ASC;" ;

        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            ResultSet lowSalaryEmps = pstmt.executeQuery();

            while(lowSalaryEmps.next())
            {
                int EmpId = lowSalaryEmps.getInt(1);
                String EmpName = lowSalaryEmps.getString(2);
                String Dep = lowSalaryEmps.getString(3);
                int Salary = lowSalaryEmps.getInt(4);

                QueryResult.LowSalaryEmployees element = new QueryResult.LowSalaryEmployees(EmpId,EmpName,Dep,Salary);

                lowSalaryEmpsList.add(element);
            }

            pstmt.close();
        }
        catch (SQLException e) { e.printStackTrace(); }

        QueryResult.LowSalaryEmployees[] lowSalaryEmpsArray = new QueryResult.LowSalaryEmployees[lowSalaryEmpsList.size()];

        return lowSalaryEmpsList.toArray(lowSalaryEmpsArray);
    }


    /**
     * For the products of given productType, increase the productionCost of every unit by a given percentage.
     *
     * @return number of rows affected
     */
    public int increaseCost(String productType, double percentage) {

        int numberOfRowsAffected = 0;

        String sqlQuery =   "UPDATE Produce P " +
                            "SET P.productionCost = P.productionCost + (P.productionCost * ?) " +
                            "WHERE P.productId IN( " +
                                "SELECT DISTINCT PRDCT.productId " +
                                "FROM Product PRDCT " +
                                "WHERE PRDCT.productType =  ? );" ;
        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            pstmt.setDouble(1,percentage);
            pstmt.setString(2,productType);

            numberOfRowsAffected = pstmt.executeUpdate();

            pstmt.close();
        }
        catch (SQLException e) { e.printStackTrace(); }

        return numberOfRowsAffected;
    }


    /**
     * Deleting all employees that have not worked since the given date.
     *
     * @return number of rows affected
     */
    public int deleteNotWorkingEmployees(String givenDate) {
        int numberOfRowsAffected = 0;

        String sqlQuery =   "DELETE " +
                            "FROM Employee " +
                            "WHERE employeeId NOT IN ( " +
                                "SELECT DISTINCT W.employeeId " +
                                "FROM Works_In W " +
                                "WHERE W.startDate >= ? );" ;
        try {
            PreparedStatement pstmt = connection.prepareStatement(sqlQuery);

            pstmt.setString(1,givenDate);

            numberOfRowsAffected = pstmt.executeUpdate();

            pstmt.close();
        }
        catch (SQLException e) { e.printStackTrace(); }

        return numberOfRowsAffected;
    }


    /**
     * *****************************************************
     * *****************************************************
     * *****************************************************
     * *****************************************************
     *  THE METHODS AFTER THIS LINE WILL NOT BE GRADED.
     *  YOU DON'T HAVE TO SOLVE THEM, LEAVE THEM AS IS IF YOU WANT.
     *  IF YOU HAVE ANY QUESTIONS, REACH ME VIA EMAIL.
     * *****************************************************
     * *****************************************************
     * *****************************************************
     * *****************************************************
     */

    /**
     * For each department, find the rank of the employees in terms of
     * salary. Peers are considered tied and receive the same rank. After
     * that, there should be a gap.
     *
     * @return QueryResult.EmployeeRank[]
     */
    public QueryResult.EmployeeRank[] calculateRank() {
        return new QueryResult.EmployeeRank[0];
    }

    /**
     * For each department, find the rank of the employees in terms of
     * salary. Everything is the same but after ties, there should be no
     * gap.
     *
     * @return QueryResult.EmployeeRank[]
     */
    public QueryResult.EmployeeRank[] calculateRank2() {
        return new QueryResult.EmployeeRank[0];
    }

    /**
     * For each factory, calculate the most profitable 4th product.
     *
     * @return QueryResult.FactoryProfit
     */
    public QueryResult.FactoryProfit calculateFourth() {
        return new QueryResult.FactoryProfit(0,0,0);
    }

    /**
     * Determine the salary variance between an employee and another
     * one who began working immediately after the first employee (by
     * startDate), for all employees.
     *
     * @return QueryResult.SalaryVariant[]
     */
    public QueryResult.SalaryVariant[] calculateVariance() {
        return new QueryResult.SalaryVariant[0];
    }

    /**
     * Create a method that is called once and whenever a Product starts
     * losing money, deletes it from Produce table
     *
     * @return void
     */
    public void deleteLosing() {

    }
}
