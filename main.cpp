#include <iostream>
#include "libpq-fe.h"

using namespace std;

void CloseConn(PGconn *conn)
{
  PQfinish(conn);
  getchar();
}
PGconn *ConnectDB()
{
  PGconn *conn = NULL;


  conn = PQconnectdb("user=isw password=isw dbname=iswdb hostaddr=sebastian.cl port=5432");


  if (PQstatus(conn) != CONNECTION_OK)
  {
    cout << "Conexion fallida.\n";
    CloseConn(conn);
  }
    else
       cout << "conexion - OK\n";

  return conn;
}

int main()
{
  PGconn *conn = NULL;

  conn = ConnectDB();
}
