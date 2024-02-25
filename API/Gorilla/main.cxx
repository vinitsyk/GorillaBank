#include <drogon/drogon.h>

auto main( int args, const char* params[] ) -> int {

    try
    {
        drogon::app()
            .addListener( "0.0.0.0", 80 )
            .run();
    }
    catch( const std::exception& e )
    {
        std::cout << "[ DROGON::ERROR ] => " << e.what() << '\n';
    }

    return 0x00;
}
