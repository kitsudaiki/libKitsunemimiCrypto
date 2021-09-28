/**
 *  @file       hashes_test.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef HASHES_TEST_H
#define HASHES_TEST_H

#include <libKitsunemimiCommon/test_helper/compare_test_helper.h>

namespace Kitsunemimi
{
namespace Crypto
{

class Hashes_Test
        : public Kitsunemimi::CompareTestHelper
{
public:
    Hashes_Test();

private:
    void generate_SHA_256_test();
    void generate_MD5_test();
};

}
}

#endif // HASHES_TEST_H
