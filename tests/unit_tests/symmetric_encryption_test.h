/**
 *  @file       symmetric_encryption_test.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef SYMMETRIC_ENCRYPTION_TEST_H
#define SYMMETRIC_ENCRYPTION_TEST_H

#include <libKitsunemimiCommon/test_helper/compare_test_helper.h>

namespace Kitsunemimi
{

class Symmetric_Encryption_Test
        : public Kitsunemimi::CompareTestHelper
{
public:
    Symmetric_Encryption_Test();

private:
    void encrypt_decrypt_AES_256();
};

} // namespace Kitsunemimi

#endif // SYMMETRIC_ENCRYPTION_TEST_H
