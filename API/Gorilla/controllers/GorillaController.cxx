#include <string>
#include <memory>
#include <cstdlib>
#include <jsoncpp/json/json.h>
#include <drogon/HttpController.h>

class Gorilla : public drogon::HttpController<Gorilla>
{
    public:

        METHOD_LIST_BEGIN

            ADD_METHOD_TO(Gorilla::Root, "/", {drogon::Get});

        METHOD_LIST_END

        void Root(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> && callback)
        {
            try 
            {
                const std::string& webpage = "<h1 style=\"text-align: center;\">Hello World<h1>";

                auto response = drogon::HttpResponse::newHttpResponse();
                response->setContentTypeCode(drogon::ContentType::CT_TEXT_HTML);
                response->setBody(webpage);

                callback(response);

            }
            catch ( const std::exception& error ) 
            {
                auto internal_error = drogon::HttpResponse::newHttpResponse();

                internal_error->setStatusCode(drogon::k500InternalServerError);

                callback(internal_error);
            }
        }

};