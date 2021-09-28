/**
 *  @file       common_test.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include "common_test.h"

#include <libKitsunemimiCrypto/common.h>
#include <libKitsunemimiCommon/buffer/data_buffer.h>

namespace Kitsunemimi
{
namespace Crypto
{

Common_Test::Common_Test()
    : Kitsunemimi::CompareTestHelper("Common_Test")
{
    hexEncode_test();

    encodeBase64_test();
    decodeBase64_test();

    base64ToBase64Url_test();
    base64UrlToBase64_test();
}

/**
 * hexEncode_test
 */
void
Common_Test::hexEncode_test()
{
    const std::string input = "qwertzuiop";
    std::string result;

    hexEncode(result, input.c_str(), input.size());

    TEST_EQUAL(result, "71776572747A75696F70");
}

/**
 * encodeBase64_test
 */
void
Common_Test::encodeBase64_test()
{
    std::string output = "";
    std::string input = "asdfasdfasdf123a";

    output = "";
    input = "asdfasdfasdf123a";
    encodeBase64(output, input.c_str(), input.size());
    TEST_EQUAL(output, "YXNkZmFzZGZhc2RmMTIzYQ==");

    output = "";
    input = "3256zu";
    encodeBase64(output, input.c_str(), input.size());
    TEST_EQUAL(output, "MzI1Nnp1");

    output = "";
    input = "5i";
    encodeBase64(output, input.c_str(), input.size());
    TEST_EQUAL(output, "NWk=");
}

/**
 * decodeBase64_test
 */
void
Common_Test::decodeBase64_test()
{
    std::string decode = "";
    Kitsunemimi::DataBuffer result;

    decodeBase64(result, "YXNkZmFzZGZhc2RmMTIzYQ==");
    decode = std::string(static_cast<char*>(result.data), result.bufferPosition);
    TEST_EQUAL(decode, "asdfasdfasdf123a");

    reset_DataBuffer(result, 1);

    decodeBase64(result, "MzI1Nnp1");
    decode = std::string(static_cast<char*>(result.data), result.bufferPosition);
    TEST_EQUAL(decode, "3256zu");

    reset_DataBuffer(result, 1);

    decodeBase64(result, "NWk=");
    decode = std::string(static_cast<char*>(result.data), result.bufferPosition);
    TEST_EQUAL(decode, "5i");
}

/**
 * base64ToBase64Url_test
 */
void
Common_Test::base64ToBase64Url_test()
{
    std::string input = "ab/4+3==";

    TEST_EQUAL(base64ToBase64Url(input), true);

    TEST_EQUAL(input, "ab_4-3");
}

/**
 * base64UrlToBase64_test
 */
void
Common_Test::base64UrlToBase64_test()
{
    std::string input = "ab_4-3";

    TEST_EQUAL(base64UrlToBase64(input), true);

    TEST_EQUAL(input, "ab/4+3==");
}

}
}
