### 项目介绍
使用C++11作为服务端开发语言，完成了一个简单的多线程HTTP服务器，支持静态资源的访问，支持高性能异步日志。

### 编译、执行
* build

    ```C++
    sh ./build.sh
    ```

* 启动server

    ```C++
    ./server
    ```

* 浏览器端

    ```C++
    ip:9006
    ```

### 个性化运行

```C++
./server [-p port] [-m TRIGMode] [-o OPT_LINGER] [-s sql_num] [-t thread_num] [-c close_log] [-a actor_model]
```

以上参数不是非必须，不用全部使用，根据个人情况搭配选用即可.

* -p，自定义端口号
	* 默认9006
* -m，listenfd和connfd的模式组合，默认使用LT + LT
	* 0，表示使用LT + LT
	* 1，表示使用LT + ET
    * 2，表示使用ET + LT
    * 3，表示使用ET + ET
* -o，优雅关闭连接，默认不使用
	* 0，不使用
	* 1，使用
* -s，数据库连接数量
	* 默认为8
* -t，线程数量
	* 默认为8
* -c，关闭日志，默认打开
	* 0，打开日志
	* 1，关闭日志
* -a，选择反应堆模型，默认Proactor
	* 0，Proactor模型
	* 1，Reactor模型

测试示例命令与含义

```C++
./server -p 9007  -m 0 -o 1 -s 10 -t 10  -a 1
```