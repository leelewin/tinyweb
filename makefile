CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

# server: main.cpp  ./timer/lst_timer.cpp ./http/http_conn.cpp ./log/log.cpp ./CGImysql/sql_connection_pool.cpp  webserver.cpp config.cpp
# 	$(CXX) -o server  $^ $(CXXFLAGS) -lpthread -lmysqlclient

server: main.cpp  ./timer/lst_timer.cpp ./http/http_conn.cpp ./log/logger.cc  ./log/logstream.cc ./util/appendfile.cc ./util/fixedbuffer.h  ./util/timestamp.cc      \
            ./log/asynclogging.cc  ./log/logfile.cc ./util/appendfile.cc      \
           ./CGImysql/sql_connection_pool.cpp  webserver.cpp config.cpp
	$(CXX) -o server  $^ $(CXXFLAGS) -lpthread -lmysqlclient -std=c++11
clean:
	rm  -r server
