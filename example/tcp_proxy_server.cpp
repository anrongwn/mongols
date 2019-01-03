#include <unistd.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <sys/prctl.h>

#include <mongols/util.hpp>
#include <mongols/tcp_proxy_server.hpp>

#include <cstring>
#include <iostream>
#include <functional>

int main(int, char**) {
    //    daemon(1, 0);
    auto f = [](const mongols::tcp_server::client_t & client) {
        return true;
    };
    int port = 9090;
    const char* host = "127.0.0.1";

    mongols::tcp_proxy_server server(host, port);

    server.set_enable_http_mode(true);
    server.set_enable_http_lru_cache(true);
    server.set_http_lru_cache_expires(1);
    server.set_default_http_content();

    //see example/nodejs
    server.set_back_server(host, 8888);
    server.set_back_server(host, 8889);

    //    server.run(f);


    std::function<void(pthread_mutex_t*, size_t*) > ff = [&](pthread_mutex_t* mtx, size_t * data) {
        server.run(f);
    };

    std::function<bool(int) > g = [&](int status) {
        std::cout << strsignal(WTERMSIG(status)) << std::endl;
        return false;
    };

    mongols::multi_process main_process;
    main_process.run(ff, g);
}
