#include <gtest/gtest.h>

#include "ssh-store.hh"

namespace nix {

TEST(SSHStore, constructConfig)
{
    SSHStoreConfig config{
        "ssh",
        "localhost",
        StoreConfig::Params{
            {
                "remote-program",
                // TODO #11106, no more split on space
                "foo bar",
            },
        }};
    EXPECT_EQ(
        config.remoteProgram.get(),
        (Strings{
            "foo",
            "bar",
        }));
}
}
