#include <stdio.h>
#include "gmock/gmock.h"

extern "C"
{
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>

    #include <security/pam_modules.h>

    #include "libtac/libtac.h"
}

namespace PamTacPlusTest
{
    using namespace std;
    using namespace std::tr1;
    using namespace testing;
    using ::testing::_;

    class Tool
    {
        public:
    };

    class CoreLayer
    {
    public:
    };

    StrictMock<CoreLayer> *g_core_layer_p;

    class PamTacPlusTest : public Test
    {
    public:
        StrictMock<CoreLayer> core_layer_mock;

        PamTacPlusTest()
        {
            g_core_layer_p = &core_layer_mock;
        }

        ~PamTacPlusTest()
        {
        }

        void SetUp()
        {
        }

        void TearDown()
        {
        }
    };

    TEST_F(PamTacPlusTest, tac_connect_single_Test)
    {
        const char *SERVER = "192.168.137.70";
        const char *KEY = "accton";
        const int SERVER_TIMEOUT = 10;
        int tac_fd;
        int ret;
        struct addrinfo *tac_server;
        struct addrinfo hints;
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        ret = getaddrinfo(SERVER, "tacacs", &hints, &tac_server);
        ASSERT_EQ(0, ret);

        tac_fd = tac_connect_single(tac_server, KEY, NULL, SERVER_TIMEOUT);
    }
}

extern "C"
{
    int connect(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen)
    {
        return 0;
    }

    int select(int nfds, fd_set *readfds, fd_set *writefds,
                  fd_set *exceptfds, struct timeval *timeout)
    {
        return 1;
    }

    int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
    {
        return 0;
    }
}
