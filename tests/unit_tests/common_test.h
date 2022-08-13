/**
 *  @file       common_test.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef COMMON_TEST_H
#define COMMON_TEST_H

#include <libKitsunemimiCommon/test_helper/compare_test_helper.h>

namespace Kitsunemimi
{
namespace Crypto
{

class Common_Test
        : public Kitsunemimi::CompareTestHelper
{
public:
    Common_Test();

private:
    void hexEncode_test();

    void encodeBase64_test();
    void decodeBase64_test();

    void base64ToBase64Url_test();
    void base64UrlToBase64_test();
};

} // namespace Crypto
} // namespace Kitsunemimi

#endif // COMMON_TEST_H
