#ifndef C1E18F15_532A_4199_8648_C7EC415E382E
#define C1E18F15_532A_4199_8648_C7EC415E382E

#include "request.hpp"
#include "response.hpp"
#include <string>

namespace mongols {

class server_bind_script_request {
public:
    server_bind_script_request()
        : req(0)
    {
    }

    virtual ~server_bind_script_request() = default;

    void init(request* req)
    {
        this->req = req;
    }

    std::string uri() const
    {
        return this->req->uri;
    }

    std::string method() const
    {
        return this->req->method;
    }

    std::string client() const
    {
        return this->req->client;
    }

    std::string user_agent() const
    {
        return this->req->user_agent;
    }

    std::string param() const
    {
        return this->req->param;
    }

    bool has_header(const std::string& key) const
    {
        return this->req->headers.find(key) != this->req->headers.end();
    }

    std::string get_header(const std::string& key) const
    {
        return this->req->headers[key];
    }

    bool has_form(const std::string& key) const
    {
        return this->req->form.find(key) != this->req->form.end();
    }

    std::string get_form(const std::string& key) const
    {
        return this->req->form[key];
    }

    bool has_cookie(const std::string& key) const
    {
        return this->req->cookies.find(key) != this->req->cookies.end();
    }

    std::string get_cookie(const std::string& key) const
    {
        return this->req->cookies[key];
    }

    bool has_session(const std::string& key) const
    {
        return this->req->session.find(key) != this->req->session.end();
    }

    std::string get_session(const std::string& key) const
    {
        return this->req->session[key];
    }

    bool has_cache(const std::string& key) const
    {
        return this->req->cache.find(key) != this->req->cache.end();
    }

    std::string get_cache(const std::string& key) const
    {
        return this->req->cache[key];
    }

private:
    request* req;
};

class server_bind_script_response {
public:
    server_bind_script_response()
        : res(0)
    {
    }

    virtual ~server_bind_script_response() = default;

    void init(response* res)
    {
        this->res = res;
    }

    void status(int c)
    {
        this->res->status = c;
    }

    void content(const std::string& content)
    {
        this->res->content = content;
    }

    void header(const std::string& key, const std::string& value)
    {
        this->res->set_header(key, value);
    }

    void session(const std::string& key, const std::string& value)
    {
        this->res->set_session(key, value);
    }

    void cache(const std::string& key, const std::string& value)
    {
        this->res->set_cache(key, value);
    }

private:
    response* res;
};
}

#endif /* C1E18F15_532A_4199_8648_C7EC415E382E */
