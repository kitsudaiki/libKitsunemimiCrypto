/**
 *  @file       hashes_test.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include "hashes_test.h"

#include <libKitsunemimiCrypto/hashes.h>

namespace Kitsunemimi
{
namespace Crypto
{

Hashes_Test::Hashes_Test()
    : Kitsunemimi::CompareTestHelper("Hashes_Test")
{
    generate_SHA_256_test();
}

/**
 * @brief generateSha256_test
 */
void
Hashes_Test::generate_SHA_256_test()
{
    std::string testInput = "test";
    std::string result = "";

    Kitsunemimi::Crypto::generate_SHA_256(result, testInput);

    TEST_EQUAL(result, "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08");
}

}
}
