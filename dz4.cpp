#include "httplib.h"
#include <iostream>

int main(int argc, char **argv)
{
    int port = 8080;
    // меняем порт по умолчанию, если предоставлен соответствующий аргумент
    // командной строки
    if (argc >= 2) {
        if (std::sscanf(argv[1], "%d", &port) != 1) {
            return -1;
        }
    }

    std::cerr << "Listening on port" << port << "..." << std::endl;

    httplib::Server svr;
    // Увеличение времени передачи с клиента
    svr.set_read_timeout(60);
    // обработчик для GET запроса по адресу /stop. останавливает сервер.
    svr.Get("/stop", [&](const httplib::Request & /*unused*/,
                         httplib::Response & /*unused*/) { svr.stop(); });
    //возвращает страничку по адресу index
    svr.Get("/index",
            [&](const httplib::Request & /*unused*/, httplib::Response &resp) {
                resp.body = "Hi";
                resp.status = 200;
            });
    // возвращает страничку по адресу about
    svr.Get("/about", [&](const httplib::Request & /*unused*/,
                          httplib::Response &resp) {
        resp.headers.insert({"Content-Type", "text/html; charset=utf-8"});
        resp.body = R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>My site.</title>
</head>
<body>
<h1>My site.<h1><br>
                <i>Iron</i><br>
                ldldld
</body>
</html>
)";
        resp.status = 200;
    });
    //запускает сервер на указанном порту. программа не завершится, пока сервер
    //не будет остановлен
    svr.listen("0.0.0.0", port);
    return 0;
}
