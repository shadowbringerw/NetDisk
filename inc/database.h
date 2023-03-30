#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <mysql/mysql.h>
#include "../inc/main.h"


//服务器给数据库中插入上传的文件信息
int insertFileMessage(const char *fileName, int fileSize);
	



#endif