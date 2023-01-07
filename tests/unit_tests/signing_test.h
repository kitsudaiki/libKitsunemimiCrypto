/**
 *  @file       signing_test.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef SIGNING_TEST_H
#define SIGNING_TEST_H

#include <libKitsunemimiCommon/test_helper/compare_test_helper.h>

namespace Kitsunemimi
{

class Signing_Test
        : public Kitsunemimi::CompareTestHelper
{
public:
    Signing_Test();

private:
    void create_verify_HMAC_Sha256();
};

} // namespace Kitsunemimi

#endif // SIGNING_TEST_H
