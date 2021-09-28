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
    generate_MD5_test();
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

    TEST_EQUAL(result, "9F86D081884C7D659A2FEAA0C55AD015A3BF4F1B2B0B822CD15D6C15B0F00A08");
}

/**
 * @brief generateMd5_test
 */
void
Hashes_Test::generate_MD5_test()
{
    std::string testInput = "test";
    std::string result = "";

    Kitsunemimi::Crypto::generate_MD5(result, "test");

    TEST_EQUAL(result, "098F6BCD4621D373CADE4E832627B4F6");
}

}
}
