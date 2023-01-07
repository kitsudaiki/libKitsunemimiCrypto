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

class Hashes_Test
        : public Kitsunemimi::CompareTestHelper
{
public:
    Hashes_Test();

private:
    void generate_SHA_256_test();
};

} // namespace Kitsunemimi

#endif // HASHES_TEST_H
