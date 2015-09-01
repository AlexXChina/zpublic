// kxlol_server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "game_server.h"


int _tmain(int argc, _TCHAR* argv[])
{
    try
    {
        asio::io_service io_service;
        tcp::endpoint endpoint(tcp::v4(), 48360);
        game_server_ptr server(new game_server(io_service, endpoint));
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
