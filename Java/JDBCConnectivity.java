import java.sql.*;

class JDBCConnectivity{
    public static void main(String[] args) {
        String driver = "com.mysql.jdbc.Driver";
        try{
            Class.forName(driver);
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/", "root", null);
            Statement st = con.createStatement();
            st.executeQuery("select * from employee");
        }catch(Exception e){
            System.out.println("Database not connected" + e);
        }
        // java -cp "D:\GITHUB\DBMS Assignment\Java\mysql-connector-j-8.4.0\mysql-connector-j-8.4.0.jar" JDBCConnectivity
    }
}