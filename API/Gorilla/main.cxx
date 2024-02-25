#include <drogon/drogon.h>

auto main( int args, const char* params[] ) -> int {

    try
    {
        drogon::app()
            .addListener( "0.0.0.0", 1155 )
            .run();
    }
    catch( const std::exception& e )
    {
        std::cout << "[ DROGON::ERROR ] => " << e.what() << '\n';
    }

    return 0x00;
}
