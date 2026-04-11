//数据库操作
#include "D:/MySQL/include/mysql.h"
#include <iostream>
using namespace std;

int main(){
    // 1. 初始化MySQL
    MYSQL* conn = mysql_init(nullptr);
    if (!conn) {
        throw runtime_error("MySQL初始化失败");
    }



    

    return 0;
}