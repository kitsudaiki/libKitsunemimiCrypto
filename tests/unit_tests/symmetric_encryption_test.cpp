/**
 *  @file       symmetric_encryption_test.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include "symmetric_encryption_test.h"

#include <libKitsunemimiCrypto/symmetric_encryption.h>

namespace Kitsunemimi
{

Symmetric_Encryption_Test::Symmetric_Encryption_Test()
    : Kitsunemimi::CompareTestHelper("Symmetric_Encryption_Test")
{
    encrypt_decrypt_AES_256();
}

/**
 * @brief encrypt_decrypt_AES_256
 */
void
Symmetric_Encryption_Test::encrypt_decrypt_AES_256()
{
    Kitsunemimi::ErrorContainer error;

    const std::string testData = "this is a test-string";
    CryptoPP::SecByteBlock key((unsigned char*)"asdf", 4);
    std::string encryptionResult;
    std::string decryptionResult;

    TEST_EQUAL(encrypt_AES_256_CBC(encryptionResult, testData, key, error), true);
    TEST_EQUAL(decrypt_AES_256_CBC(decryptionResult, encryptionResult, key, error), true);

    TEST_NOT_EQUAL(encryptionResult, testData);
    TEST_EQUAL(decryptionResult, testData);
}

} // namespace Kitsunemimi
