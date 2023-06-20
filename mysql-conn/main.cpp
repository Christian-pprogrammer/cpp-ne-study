#include <iostream>
#include <mysql_driver.h>
// #include <mysql_connection.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>

// int main()
// {
//   sql::mysql::MySQL_Driver *driver;
//   sql::Connection *con;
//   sql::Statement *stmt;
//   sql::ResultSet *res;

//   // Establish a MySQL database connection
//   driver = sql::mysql::get_mysql_driver_instance();
//   con = driver->connect("tcp://localhost:3306", "username", "password");

//   // Select query
//   std::cout << "Executing SELECT query...\n";
//   stmt = con->createStatement();
//   res = stmt->executeQuery("SELECT * FROM your_table");

//   // Process the result set
//   while (res->next())
//   {
//     std::cout << "ID: " << res->getInt("id") << ", Name: " << res->getString("name") << std::endl;
//   }

//   delete res;
//   delete stmt;

//   // Update query
//   std::cout << "Executing UPDATE query...\n";
//   stmt = con->createStatement();
//   stmt->executeUpdate("UPDATE your_table SET name='John' WHERE id=1");

//   delete stmt;

//   // Delete query
//   std::cout << "Executing DELETE query...\n";
//   stmt = con->createStatement();
//   stmt->executeUpdate("DELETE FROM your_table WHERE id=2");

//   delete stmt;

//   con->close();
//   delete con;

//   return 0;
// }
