# include "../inc/database.h"

//服务器给数据库中插入上传的文件信息
int insertFileMessage(const char *fileName, int fileSize){
	MYSQL *conn;
	const char *server = "localhost";
	const char *user = "root";
	const char *password = "123456";
	const char *database = "netdisk";
	char query[300] = {0};
	sprintf(query, "%s%s%s%d%s", "insert into virtualfile(filename, fileSize) values ('", fileName, "', " , fileSize, ")");
	
	int queryResult;
	conn = mysql_init(NULL);

	if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)){
		printf("Error connecting to database: %s\n", mysql_error(conn));
	}
    	else{
		printf("Connected...\n");
	}

	queryResult = mysql_query(conn, query);
	if(queryResult){
		printf("Error making query:%s\n", mysql_error(conn));
	}
   	 else{
		printf("insert success\n");
	}
	mysql_close(conn);

	return 0;
	

}
